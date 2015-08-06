#ifndef IntCell2_H
#define IntCell2_H

class IntCell2 {

	public: 
	explicit IntCell (int intialValue = 0) {
		stroredValue = new int { *rhs.storedValue } ;
	}

	int read() const {
		return *storedValue ; 
	}

	void write (int x) {
		*storedValue = x ; 
	}

	private:
		int *storedValue ;

} ;
		
