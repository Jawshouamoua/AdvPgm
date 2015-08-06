#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>

int main() {
	std::vector<int> v1, v2, vSum;

	/*
	std::vector<int>::iterator itr1 = v1.begin();
	std::vector<int>::iterator itr2 = v2.begin();
	*/

	
	for(int i=0; i < 20; i++) {
		v1.push_back(i);
		v2.push_back(20-i);
	}

	vSum.resize(v1.size());

	std::transform(v1.begin(), v1.end(), v2.begin(), vSum.begin(), std::plus<int>());

	std::copy(vSum.begin(), vSum.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

}
