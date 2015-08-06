#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<vector>

int randNum() {
	return rand()%100;
}

struct oddEven : public std::unary_function<int, void> {
	int nEven, nOdd;
	oddEven() : nEven(0), nOdd(0) { }
	void operator() (int x) {
		if(x%2 == 0) 
			nEven++;
		else
			nOdd++;
	}
};

int main() {

	std::vector<int> vec(100);
	
	std::generate(vec.begin(), vec.end(), randNum);

	oddEven result = for_each(vec.begin(), vec.end(), oddEven());
	std::cout << "Number of odd elements: " << result.nOdd << std::endl;
	std::cout << "Number of even elements: " << result.nEven << std::endl;

}
