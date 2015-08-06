#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>


/*
int summation(int init, int step) {
	
}
*/

int main() {
	std::vector<int> v(40);

	int start(2);

	std::generate(v.begin(), v.end(), [&]{ start = start + 5; return start; } );
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}
