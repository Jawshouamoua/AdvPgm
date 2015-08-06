#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<stdlib.h>
#include<time.h>

template <typename BidirectionalIterator>
void my_reverse(BidirectionalIterator first, BidirectionalIterator last) {
	last--;
	while(std::distance(first, last) > 0)
		std::swap(*first++, *last--);
}

int randNum() {
	return rand()%100;
}

void test(int size) {
	std::vector<int> v(size);

	std::cout << "size: " << size << std::endl;
	
	std::generate(v.begin(), v.end(), randNum);
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	my_reverse(v.begin(), v.end());
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
}
int main() {

	for(int i=0; i<20; i++) {
		test(i);
	}
	
}
