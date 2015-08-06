#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std ;

template <typename Object>
class Stack {

	private:
		vector<int> stack ;
		Object temp ;


	public:

		Stack() {  }

		~Stack() {
			stack.clear() ;
			//delete stack ;
		}

		Stack( const Stack & rhs) {
			*this = rhs ;
		}

		const Stack & operator= (const Stack & rhs) {
			if (this == &rhs)
				return *this;
			stack.clear() ;
			for(int i=0; i<rhs.size;i++) 
				stack.push_back(rhs[i]);
		}	
	
		void push(const Object & d) {
			stack.push_back(d) ; 
		}
		
		Object & pop() {
			temp = stack.back() ;
			stack.pop_back() ;
			return temp ;
		}

		Object & top() {
			return stack.back() ;
		}

		bool isEmpty() {
			if(stack.empty()) return true ;
			else return false ;
		}



} ;
