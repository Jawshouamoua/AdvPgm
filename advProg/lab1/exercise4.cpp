/*
 * the author of this code intended to create a vector of ints and then remove an int in the
 * vector if it is an even number.
 *
 * The code is broken because the second copy function iterates to the end of the vector, instead
 * of iterating to the 'new_end' iterator.
 *
 * I changed the second copy function to iterator to 'new_end'.
 *
 */

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<ext/functional>

int main() {

	std::vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	v.push_back(8);
	v.push_back(5);
	v.push_back(7);

	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::vector<int>::iterator new_end = remove_if(v.begin(), v.end(),
						__gnu_cxx::compose1(bind2nd(std::equal_to<int>(), 0), 
						bind2nd(std::modulus<int>(),2)));

	std::copy(v.begin(), new_end, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

}
