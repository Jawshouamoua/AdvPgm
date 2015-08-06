#include <iostream> 
#include "IntCell.h"
using namespace std ;

int main() {

	IntCell m1, m2, m3 ;
	int x;

	cin >> x ;
	m1.write(x) ;

	cin >> x ;
	m2.write(x) ;

	cin >> x ;
	m3.write(x) ;

	cout << m1.read() << m2.read() << m3.read() << endl ;

	cout << m3.read() << m2.read() << m1.read() << endl ;

	
	if(m1.read() > m2.read()) {
		if(m1.read() > m3.read()) 
			cout << "max: " << m1.read() << endl ;
		else 
			cout << "max: " << m3.read() << endl ;
	}
	else {
		if(m2.read() > m3.read()) 
			cout << "max: " << m2.read() << endl ;
		else 
		cout << "max: " << m3.read() << endl ;
	}

	if(m1.read() < m2.read()) {
		if(m1.read() < m3.read())
			cout << "min: " << m1.read() << endl ;
		else
			cout << "min: " << m3.read() << endl ;
	}
	else {
		if(m2.read() < m3.read()) 
			cout << "min: " << m2.read() << endl ;
		else
			cout << "min: " << m3.read() << endl ;
	}

	x = (m1.read() + m2.read() + m3.read()) / 3 ;
	cout << "average = " << x << endl ;

	return 0 ;
	
}


