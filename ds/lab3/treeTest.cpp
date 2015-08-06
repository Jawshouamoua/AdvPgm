#include<iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	BinarySearchTree<int> tree ;
	BinarySearchTree<int> tree2 ;

	int temp[] = {7,10, 4, 5, 12, 11, 3, 2, 9, 1, 8, 6};
	for(int i=0; i<12; i++) {
		tree.insert(temp[i]);
	}

	cout << tree.computeNodes() << endl;
	cout << "number of leaves = " << tree.computeLeaves() << endl;
	cout << "number of full nodes = " << tree.computeFullNodes() << endl;

}
