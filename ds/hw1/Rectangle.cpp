#include "Rectangle.h"

//constructor
Rectangle::Rectangle(int initH, int initL) : height(initH),length(initL) {
}

int Rectangle::getLength() const {
	return length ;
}

int Rectangle::getHeight() const {
	return height ;
}

void Rectangle::setLength(int l) {
	length = l ;
}

void Rectangle::setHeight(int h) {
	height = h ;
}


 
