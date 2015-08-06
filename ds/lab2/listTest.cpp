#include<iostream>
#include "List.h"

using namespace std;

int main() {
	List<int> list;
	List<int>::iterator itr = list.begin();
	int temp[] = {5,7,9,2,0,2};
	cout << list.empty() << endl;
	for(int i=0; i<6; i++)
		itr = list.insert(itr, temp[i]);
	cout << list.empty() << endl;
	list.uniqueInsert(list.begin(), 5);
	cout << list.member(7) << endl;
	cout << list.member(8) << endl;
	list.remove(2);
	list.remove(8);

	list.print();

}
