#include <iostream>
using namespace std ;

int f(int x, int cnt) {

	if(x==0) 
		return cnt ;
	else if(x%2 == 0) 
		f(x/2,cnt) ; 
	else
		f(x/2, cnt+1) ;
}

int main() {
	
	int nOnes ;

	for(int i=0; i<16; i++) {
		nOnes = f(i, 0) ;
		cout << "number of 1s in " << i << " = " << nOnes << endl ;
	}

	return 0 ;

}
