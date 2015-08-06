#include<iostream>
#include<vector>

int main() {
	std::vector<int> v;
	std::vector<int>::iterator first, last;
	for(int i=0; i<5; i++) 
		v.push_back(i);

	first = v.begin();
	last = v.end();

	while(first != last) 
		std::cout << *first++ << " ";

	std::cout << std::endl;
		
}
