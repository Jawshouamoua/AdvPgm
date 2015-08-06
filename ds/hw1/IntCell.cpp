#include "IntCell.h"

//construct the IntCell with initialValue

IntCell::IntCell( int initialValue ) : storedValue( initialValue ) {
}

//Return the stored value 

int IntCell::read() const {
	return storedValue ;
}

//store x 

void IntCell::write(int x) {
	storedValue = x; 
}

//add two IntCells

int IntCell::add(IntCell cell) {
	int value = cell.read() + storedValue ;
	return value;
}

//add an IntCell and int returning new IntCell

IntCell IntCell:: operator+ (const IntCell& cell) {
	IntCell m ;
	m.write(cell.read() + this->read()) ;
	return m ;
}


//add an IntCell and int modifying the state of IntCell

void IntCell::operator+(int x) {
	this->storedValue += x ;
}

