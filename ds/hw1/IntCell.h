#ifndef IntCell_H
#define IntCell_H

class IntCell {

	public:
		explicit IntCell (int initialValue = 0) ;
		int read() const ;
		void write (int x) ;
		int add(IntCell m) ;
		IntCell operator+ (const IntCell & m) ;
		void operator+ (int x) ;
	//	IntCell addToNewCell(int x) ;
	//	void addToIntCell(int x) ;

	private:
		int storedValue ;
} ;

#endif
