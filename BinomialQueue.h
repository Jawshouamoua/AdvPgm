template <typename Comparable>
class BinomialQueue {
	public:
		
		BinomialQueue();
		BinomialQueue(const Comparable & item);
		BinomialQueue(const BinomialQueue & rhs);

		~BinomialQueue();
		
		BinomialQueue & operator=(const BinomialQueue & rhs);

		bool isEmpty() const;
		const Comparable & findMin() const;

		void insert(const Comparable & x);
		void deleteMin();
		void deleteMin(Comparable & rhs); 

	private:
		struct BinomialNode {
			Comparable element;
			BinomialNode *leftChild;
			BinomialNode *nextSibling;

			BinomialNode(const Comparable & e, BinomialNode *lt, BinomialNode *rt) :
				element{e}, leftChild{lt}, nextSibling{rt} {}

			const static int DEFAULT_TREES = 1;

			vector<BinomialNode *> theTrees; //An array of tree roots
			int currentSize;				//Number of items in the priority queue

			int findMinIndex() const;
			int capacity() const;
			BinomialNode * combineTrees(BinomialNode *t1, BinomialNode *t2);
			void makeEmpty(BinomialNode * & t);
		};	
		
		/**
 		 *return the result of merging equal-sized t1 and t2.
		 */	
		BinomialNode * combineTrees(BinomialNode *t1, BinomialNode *t2) {
			if(t2->element < t1->element)
				return combineTrees(t2, t1);
			t2->nextSibling = t1->leftChild;
			t1->leftChild = t2;
			return t1;
		}

		/**
 		 * Merge rhs into the priority queue.
 		 * rhs becomes empty. rhs must be different from this.
 		 * excersize 6.35 needed to make this operation more efficient.
 		 */
		void merge(BinomialQueue & rhs) {
			if(this == &rhs)
				return;

			currentSize += rhs.currentSize;

			if(currentSize > capacity()) {
				int oldNumTrees = theTrees.size();
				int newNumTrees = max(theTrees.size(), rhs.theTrees.size()) + 1;
				theTrees.resize(newNumTrees);
				for(int i = oldNumTrees; i < newNumTrees; ++i, j *= 2) {
					BinomialNode *t1 = theTrees[i];
					BinomialNode *t2 = i < rhs.theTrees.size() ? rhs.theTree[i] : NULL;
		
					int whichCase = t1 == NULL ? 0 : 1;
					whichCase += t2 == NULL ? 0 : 2;
					whichCase += carry == NULL ? 0 : 4;

					switch(whichCase) {
						case 0: /* No trees*/
						case 1:
							break;
						case 2: /*Only rhs*/
							theTrees[i] = t2;
							rhs.theTrees[i] = NULL;
							break;
						case 4: /*only carry*/
							theTrees[i] = carry;
							carry = NULL;
							break;
						case 3: /*this and rhs */
							carry = combineTrees(t1, t2);
							theTrees[i] = rhs.theTrees[i] = NULL;
							break;
						case 5: /* this and carry */
							carry = combineTrees(t2, carry);
							rhs.theTree[i] = NULL;
							break;
						case 6: /* rhs and carry */
							carry = combineTrees(t2, carry);
							rhns.theTrees[i] = NULL;
							break;
						case 7: /* all three */
							theTrees[i] = carry;
							carry = combineTrees(t1, t2);
							rhs.theTrees[i] = NULL;
							break;
					}
						
				}
				for(auto & root : rhs.theTrees)
					root = NULL;
				rhs.currentSize = 0;
			}
		}

		/*
 		 * Remove the minimum item and place it in minItem.
 		 * Thows underflow exception if empty.
 		 */
		void deleteMin(Comparable & minItem) {
			if(isEmpty())
				throw UnderflowException{ };

			int minIndex = findMinIndex() ;
			minItem = theTrees[minIndex]->element;
			BinomialNode *oldRoot = theTrees[minIndex];
			BinomialNode *deletedTree = oldRoot->leftChild;
			delete oldRoot;

			//construct H''
			Binomialqueue deletedQueue;
			deletedQueue.theTrees.resize(minIndex + 1);
			deletedQueue.currentSize = (1 << minIndex) - 1;
			for(int j=minIndex - 1; j >= 0; --j) {
				deletedQueue.theTrees[j] = deletedTree;
				deletedTree = deletedTree->nextSibling;
				deletedQueue.theTrees[j]->nextSibling = NULL;
			}

			//construct H'
			theTrees[minIndex] = NULL;
			currentSize -= deletedQueue.currentSize + 1;

			merge(deletedQueue);
		}	
		
		/**
 		 * Find index of tree containing the smallest item in the priority queue.
 		 * The priority queue must not be empty.
 		 * Return the index of tree containing the smallest item.
 		 */
		int findMinIndex() const {
			int i;
			int minIndex;
			
			for(int i = 0; theTrees[i] == NULL; ++i) ;

			for(minIndex = i; i < theTrees.size(); ++i)
				if(theTrees[i] != NULL && theTrees[i]->element < theTrees[minIndex]->element)
					minIndex = i;

			return minIndex;
		}

			
}
