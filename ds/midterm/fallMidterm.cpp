#include <iostream>
#include "List.h"
using namespace std;

/*
 * Question 1
 *
 *	The big-O of:
 *		non-member function = 18*N + 3
 *		There are 3 initial steps for setting up variables and 18 steps 
 *		for each iteration of the while loop which iterates N times.
 *
 *		member function = 10*(N/2) + 8
 *		There are 8 initial steps for setting up variables and 10 steps 
 *		for each iteration of the for loop which iterates N/2 times.
 *		
 *
 */

void reverseList(List<int> &l) ;

int main() {
	
	List<int> list ;	
	List<int>::iterator itr = list.begin() ;
	for(int i=0; i < 10; i++) 
		list.insert(itr, i ) ;

	

	//cout << list.size() << endl ;
	//cout << list.front() << endl ;

/*
	itr = list.begin() ;
	for(int i=0; i< 10; i++) {
	list.insert(itr, list.back()) ;
	list.pop_back() ;
	}
*/

	reverseList(list) ;
	list.reverse() ;


	itr = list.begin() ;
	while(itr != list.end()) {
		cout << *itr++ << endl ;
		list.pop_front() ;
	}
		
}

void reverseList(List<int> & l) {
	List<int>::iterator itr = l.begin() ;
	int i = 0 ;
	while(i < l.size()) {
		l.insert(itr, l.back()) ;
		l.pop_back() ;
		i++;
	}

}
