#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<time.h>
using namespace std;

int randNum() {
	return (rand()%100);
}

int main() {
	vector<int> vectorInt(100);
	srand(time(NULL));

	generate(vectorInt.begin(), vectorInt.end(), randNum);

	copy(vectorInt.begin(), vectorInt.end(), ostream_iterator<int>(cout, " "));

}
