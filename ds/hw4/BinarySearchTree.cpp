#include <iostream>
#include <cstdlib>
using namespace std;
template <typename Comparable>

class BinarySearchTree {

	private:
		struct BinaryNode {
			Comparable element;
			BinaryNode *left;
			BinaryNode *right;
			BinaryNode *parent;

			BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt)
				: element{theElement}, left{lt}, right{rt} {}

			//BinaryNode(Comparable && theElement, BinaryNode *lt, BinaryNode *rt)
			//	: element{ std::move(theElement) }, left{lt}, right{rt} {}
		};

	public:
		class const_iterator {
			public:
				const_iterator() : current(NULL) { }

				const Comparable & operator* () const {
					return this->retrieve() ;
				}
				const_iterator & operator++ () {
					current = current->right;
					return *this;
				}

				const_iterator operator++ (int) {
					const_iterator old = *this;
					++(*this);
					return old;
				}

				bool operator==(const const_iterator & rhs) const {
					return current == rhs.current;
				}
				bool operator != (const const_iterator & rhs) const {
					return !(*this==rhs);
				}
		
			protected:
				friend class BinarySearchTree<Comparable>;
				BinaryNode *current;

				Comparable & retrieve() const {
					return current->element;
				}
		
				const_iterator(BinaryNode *p) : current(p) { }

		};
		class iterator : public const_iterator {
			public:
				iterator() { }

				Comparable & operator * () {
					return this->retrieve();
				}
				const Comparable & operator*() const {
					return const_iterator::operator*();
				}
				iterator & operator++ () {
					this->current = this->current->right;
					return *this;
				}
				iterator operator++ (int) {
					iterator old = *this;
					++(*this);
					return old;
				}

			protected:
				iterator(BinaryNode *p) : const_iterator(p) { }

				friend class BinarySearchTree<Comparable>;
		};

		BinarySearchTree() : root(NULL) { }

		BinarySearchTree(const BinarySearchTree & rhs) : root{NULL} {
			root = clone(rhs.root);
		}

		//BinarySearchTree(BinarySearchTree && rhs);
		
		~BinarySearchTree() {
			makeEmpty();
		}

		const Comparable & findMin() const {
			return findMin(root)->element;
		}

		const Comparable & findMax() const {
			return findMax(root)->element;
		}
		
		bool isEmpty() const {
			return root == NULL;
		}
		void printTree (ostream & out = cout) const {
			printTree(root);
			std::cout << endl;
		}

		void makeEmpty() {
			makeEmpty(root);
		}

		void insert(const Comparable & x) {
			insert(x,root);
		}

	//	void insert(Comparable && x) {
			
		void remove(const Comparable & x) {
			insert(x, root);
		}
	
		BinarySearchTree & operator=(const BinarySearchTree & rhs) {
			if(this != &rhs) {
				makeEmpty() ;
				root = clone(rhs.root);
			}
			return *this;
		}

		//BinarySearchTree & operator=(BinarySearchTree && rhs);

	private:

		BinaryNode *root;

		void insert(const Comparable & x, BinaryNode * & t) {
			if(t == NULL)
				t = new BinaryNode{x, NULL, NULL} ;
			else if(x < t->element)
				insert(x, t->left);
			else if(t->element < x)
				insert(x, t->right);
			else
				; //Duplicate, do nothing
		}
/*
		void insert(Comparable && x, BinaryNode * &t) {
			if(t == NULL)
				t = new BinaryNode{std::move(x), NULL, NULL};
			else if(x < t->element)
				insert(std::move(x), t->left);
			else if(t->element < x)
				insert(std::move(x), t->right);
			else
				; //duplicate, do nothing
		}
*/
	
		void remove(const Comparable & x, BinaryNode * & t) {
			if(t == NULL)
				return;
			if(x < t->element)
				remove(x, t->left);
			else if(t->element < x)
				remove(x, t->right);
			else if(t->left != NULL && t->right != NULL) { //two children
				t->element = findMin(t->right)->element;
				remove(t->element,t->right);
			}
			else {
				BinaryNode *oldNode = t;
				t = (t->left != NULL) ? t->left : t->right;
				delete oldNode;
			}
		}

		BinaryNode * findMin(BinaryNode *t) const {
			if(t != NULL)
				while(t->left != NULL)
					t = t->left;
			return t;
		}
		BinaryNode * findMax(BinaryNode *t) const {
			if(t != NULL)
				while(t->right != NULL)
					t = t->right;
			return t;
		}

		bool contains(const Comparable & x, BinaryNode *t) const {
			if(t==NULL)
				return false;
			else if(x < t->left)
				return contains(x, t->left);
			else if (t->element < x) 
				return contains(x, t->right);
			else 
				return true;
		}

		void makeEmpty(BinaryNode * & t) {
			if(t != NULL) {
				makeEmpty(t->left);
				makeEmpty(t->right);
				delete t;
			}
			t = NULL ;
		}

		void printTree(BinaryNode *t, ostream & out) const {
			if(t == NULL) 
				return;
			else {
				printTree(t->left);
				cout << t->element << ", ";
				printTree(t->right);
			}
		}

		BinaryNode * clone(BinaryNode *t) const {
			if(t == NULL)
				return NULL;
			else
				return new BinaryNode{t->element, clone(t->left). clone(t-right)};
		}
};

int main() {
	BinarySearchTree<int> tree ;
	int numbers[] = {5,6,9,54,7,19,1,2};
	for(int i=0; i<8; i++) 
		tree.insert(numbers[i]);

	cout << "find max: " << tree.findMax() << endl;
	cout << "find min: " << tree.findMin() << endl;

}
	



		
