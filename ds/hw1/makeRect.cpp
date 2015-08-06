//generic findMax with a function object, C++ style.
//Precondition: a.size() > 0.
const Object & findMax (const vector<Object> & arr, Comparator isLessThan)
{
	int maxIndex = 0 ;

	for(int i = 1; i < arr.size(); i++)
		if(isLessThan(arr[maxIndex], arr[i]))
			maxIndex = i ;

	return arr[maxIndex] ;
}

//Generic findMax, using default ordering.
#include <functional>
template <typename Object>
const Object & findMax (const vector<Object> & arr) {
	return findMax (arr,less<Object> { } ) ;
}


#include <iostream>
#include "Rectangle.h"
using namespace std ;

int main() {
	
	Rectangle r1 ;
	r1.setLength(5) ;
	r1.setHeight(2) ;

	cout << r1.getLength() << r1.getHeight() << endl ;

	return 0 ;
}
