#include <iostream>
#include <string>
#include <string.h>
#include <cstdio> 
using namespace std ;

bool chkInclude (string in) {
	const char *cs = in.c_str() ;
	if (strncmp(cs, "#include", 8) == 0)
		return true;
	else
		return false ;
}

int main(int argc, char **argv) {
	string s1 ;
	FILE *file = fopen(argv[1], "r") ;
	
	s1 = fgets(s1, 100, file) ;

	while (cin >> s1) {
		if (chkInclude(s1))
			cout << s1 << endl ;
	}

} 
