#ifndef Rectangle_H
#define Rectangle_H

class Rectangle {

	public:
		explicit Rectangle (int initH=0, int initL=0) ;
		int getLength() const ;
		int getHeight() const ;
		void setLength(int l) ;
		void setHeight(int h) ;

	private:
		int height, length ;


} ;

#endif
