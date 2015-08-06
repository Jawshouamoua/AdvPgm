#include <iostream>
#include "IntCell.h"
using namespace std ;

int main() {
	IntCell m ;
	IntCell m2 ;

	m.write(5) ;
	m2.write(6) ;

	cout << "Cell contents: " << m.read() << endl ;

	cout << "adding m and m2 = " << m.add(m2) << endl ;


	IntCell m3 = m+m2 ;
	cout << "Adding 5 to m to create m3 = " << m3.read() << endl ;

	m3+3 ;
	cout << "adding 3 to m3 = " << m3.read() << endl ;


	return 0 ;
}
