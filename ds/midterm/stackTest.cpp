#include<iostream>
#include "Stack.h"
#include<cstring>
using namespace std;

int main() {

	Stack<int> stack ;
	Stack<char> match ;
	char message[] = "int main(char[] argv, int argc) { } ";
	int parenCheck = 0; 

	for(int i=0; i < 10; i++) {
		stack.push(i);
	}

	for(int i=0; i<strlen(message); i++) {
		stack.push(message[i]) ;
		if(message[i] == '(') 
			parenCheck++;

		if(message[i] == ')') {
			if(parenCheck == 0) 
				cout << "Error: mismatch parenthesis" << endl;
			else 
				parenCheck--;
		}
	}
	if(parenCheck > 0) 
		cout << "Error: Missing closing parenthesis" << endl;
	/*		
	while(!stack.isEmpty())
	cout << "top of stack: " << stack.top() << endl ;
	*/

}

/*
 * Big O of member function is 
