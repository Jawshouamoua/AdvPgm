#include <iostream>
#include <vector>
#include "IntCell.h"
using namespace std ;

int main () {
	
	IntCell* cells = new IntCell(10) ;
	IntCell* cells2 = cells ;

	for(int i = 0; i < 10; i++) 
		cells[i].write(i) ;


	for(int i = 0; i < 10; i++)
		cout << cells2[i].read() << endl ;


}

