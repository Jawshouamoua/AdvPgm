#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
template <typename Comparable>

class Set {
		
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
				BinarySearchTree::BinaryNode *current;

				Comparable & retrieve() const {
					return current->element;
				}
		
				const_iterator(BinarySearchTree::BinaryNode *p) : current(p) { }
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
				iterator(BinarySearchTree::BinaryNode *p) : const_iterator(p) { }

		};


		Set() {}

		Set(const Set & rhs) {
			BinarySearchTree(rhs) ;
		}
	
		~Set() {
			set.makeEmpty;
		}

		insert(const Comparable & x) {
			set.insert(x);
		}

		iterator begin() {
			return iterator(set.root);
		}
		iterator end() const {
			return const_iterator(set.findMax());
		}
		



	private:
		BinarySearchTree set;
