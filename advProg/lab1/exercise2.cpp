#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<stdlib.h>
#include<time.h>

std::string randStr() {
	std::string str;
	int strlen = (rand()%10) + 5;
	static char c; 


	for(int i=0; i < strlen; i++) {
		c = 'A' + rand()%24;
		str += c;	
	}

	return str;
}
	
bool sortByLen(std::string i, std::string j) {
	return (i.length() < j.length());
}

int main() {
	srand(time(NULL));
	for(int i=0; i < 20; i++) {
		std::cout << randStr() << std::endl;
	}
	std::vector<std::string> vectorStr(100);


	std::generate(vectorStr.begin(), vectorStr.end(), randStr);

	std::sort(vectorStr.begin(), vectorStr.end());
	std::cout << "first sort: ";

	std::copy(vectorStr.begin(), vectorStr.end(), std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << std::endl;

	std::sort(vectorStr.begin(), vectorStr.end(), sortByLen);
	std::cout << "second sort: ";
	
	std::copy(vectorStr.begin(), vectorStr.end(), std::ostream_iterator<std::string>(std::cout, " "));
	
	std::cout << std::endl;
}
