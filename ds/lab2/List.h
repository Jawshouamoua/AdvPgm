#include <iostream>
#include <cstdlib>
using namespace std;

template <typename Object>
class List {
   private:
	struct Node {
		/* See Figure 3.13 */
        Object  data;
        Node   *next;

        Node( const Object & d = Object( ), Node *n = NULL )
          : data( d ), next( n ) { }
	};

   public:
	class const_iterator {
      public:
        const_iterator( ) : current( NULL )
          { }

        const Object & operator* ( ) const
          { return this->retrieve( ); }
            
        const_iterator & operator++ ( )
        {
            current = current->next;
            return *this;
        }
    
        const_iterator operator++ ( int )
        {
            const_iterator old = *this;
            ++( *this );
            return old;
        }
    
        bool operator== ( const const_iterator & rhs ) const
          { return current == rhs.current; }
        bool operator!= ( const const_iterator & rhs ) const
          { return !( *this == rhs ); }
    
      protected:
        Node *current;
    
        Object & retrieve( ) const
          { return current->data; }
    
        const_iterator( Node *p ) : current( p )
          { }
            
        friend class List<Object>;
	};

	class iterator : public const_iterator {

      public:
        iterator( )
          { }
    
        Object & operator* ( )
          { return this->retrieve( ); }

        const Object & operator* ( ) const
          { return const_iterator::operator*( ); }
            
        iterator & operator++ ( )
        {
            this->current = this->current->next;
            return *this;
        }
    
        iterator operator++ ( int )
        {
            iterator old = *this;
            ++( *this );
            return old;
        }
		
    
      protected:
        iterator( Node *p ) : const_iterator( p )
          { }
    
        friend class List<Object>;
    };

   public:
	List() { init( ); }
    
    ~List( )
    {
        clear( );
        delete head;
    }
    
    List( const List & rhs )
    {
        init( );
        *this = rhs;
    }
    
    const List & operator= ( const List & rhs )
    {
        if( this == &rhs )
            return *this;
        clear( );
		Node *p = rhs.head;
		Node *thiss = head;
		p = p->next;
		while (p->next != NULL) {
			thiss->next = new Node(p->data, NULL);
			thiss = thiss->next;
			p = p->next;
		}
		return *this;
    }
    
    void init( )
    {
        theSize = 0;
        head = new Node;
	}

	iterator begin() {
		return iterator( head);
	}

	const_iterator begin() const {
		return const_iterator( head);
	}


	int size() const {
		return theSize;
	}

	bool empty() const {
		return size() == 0;
	}

	void print() const {
		Node *p = head;
		p = p->next;
		while(p != NULL) {
			cout << p->data << ", " ;
			p = p->next;
		}
		cout << endl;
	}

	bool member(const Object & x) {
		Node *p = head;
		p = p->next;
		while(p != NULL) {
			if(p->data == x)
				return true;
			p = p->next;
		}
		return false;
	}

	void clear() {
		while (!empty())
			pop_front();
	}

    Object & front( )
      { return *begin( ); }
    const Object & front( ) const
      { return *begin( ); }
    void push_front( const Object & x )
      { insert( begin( ), x ); }
    void pop_front( )
      { erase( begin( ) ); }

    iterator insert( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        theSize++;
        return iterator( p->next = new Node( x, p->next) );
    }

	iterator uniqueInsert(iterator itr, const Object & x) {
		if(!this->member(x)) {
			return insert(itr, x);
		}
		else {
			cout << "already member of list!" << endl;
			return itr;
		}
	}

    iterator erase( iterator itr )
    {
			Node *p = itr.current;
			Node *temp = p->next;
			iterator retVal( p );
		if(!this->empty()) {
			p->next = p->next->next;
			delete temp;
			theSize--;
		}
 
        return retVal;
    }
 
    iterator erase( iterator from, iterator to )
    {
        for( iterator itr = from; itr != to; )
            itr = erase( itr );
 
        return to;
    }

	void remove(const Object & x) {
		Node *p = head;
		p = p->next;
		while(p != NULL && p->next != NULL) {
			if(x == p->next->data) {
				erase(p) ;
				return;
			}
			p = p->next;
		}
		cout << "not in list!" << endl;
	}

  private:
    int   theSize;
    Node *head;
    Node *tail;

/* This should either be private or public but not both. 
    void init( )
      { }
*/
};
