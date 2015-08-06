#include <iostream> 
using namespace std ;

int main() {

int x, y, z ;
cin >> x >> y >> z ;
cout << x << y << z << endl ;
cout << z << y << x << endl ;

if(x > y) {
	if(x > z) {
		cout << "max: " << x << endl ;
	}
	else {
		cout << "max: " << z << endl ;
	}
}
else {
	if(y > z) {
		cout << "max: " << y << endl ;
	}
	else {
		cout << "max: " << z << endl ;
	}
}

if(x < y) {
	if(x < z)
		cout << "min: " << x << endl ;
	else
		cout << "min: " << z << endl ;
}
else {
	if(y < z) 
		cout << "min: " << y << endl ;
	else
		cout << "min: " << z << endl ;
}

int avg = (x+y+z) / 3 ;

cout << "average: " << avg << endl ;
}


