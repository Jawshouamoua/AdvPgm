#include <iostream>
#include <cstdlib>

template <typename Object>
class List {
	private:
		struct Node {
			/*See Figure 3.13 */
		Object data;
		Node *prev;
		Node *next;

		Node(const Object & d = Object(), Node *p = NULL, Node *n = NULL)
			: data(d), prev(d), next(n) { }
		} ;

	public:
			class const_iterator {
		public:
			const_iterator() : current(NULL)
				{ }
			const Object & operator* () const {
				return this->retrieve() ; 
			}

			const_iterator & operator++ () {
				current = current->next;
				return *this ;
			}

			const_iterator operator++ (int) {
				const_iterator old = *this ;
				++(*this) ;
				return old ;
			}

			bool operator== (const const_iterator & rhs) const {
				return current == rhs.current;
			}

			bool operator!= (const const_iterator & rhs) const {
				return !(*this == rhs); 
			}

			protected:
				Node *current;
				
				Object & retrieve() const {
					return current->data ;
				}

				const_iterator(Node *p) : current(p) 
					{}

				friend class List<Object> ;
				} ;

				class iterator : public const_iterator {

			public:
				iterator()
					{ }

				Object & operator* ( ) {
					return this->retrieve() ; 
				}

				const Object & operator* () const {
					return const_iterator::operator*(); 
				}
			
				iterator & operator++ () {
					this->current = this->current->next;
					return *this;
				}

				iterator operator++ (int) {
					iterator old = *this;
					++(*this);
					return old ;
				}

			protected:
				iterator(Node *p) : const_iterator(p) {
				}

				friend class List<Object>;
		};

		public: 
			List() {
				init() ;
			}
		
		~List() {
			clear() ;
			delete head;
			delete tail ; 
		}

		List() {
			clear() ;
			delete head ;
			delete tail ;
		}

		List(const List & rhs) {
			init() ;
			*this = rhs ;
		}
		
		const List & operator= (const List & rhs) {
			if(this == &rhs)
				return *this ;
			clear() ;
			for(const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
				push_back(*itr) ;
			return *this;
		}

		void init() {
			theSize = 0;
			head = new Node ;
			tail = new Node; 
			head->next = tail ;
			tail->prev = head ;
		}

		
		
