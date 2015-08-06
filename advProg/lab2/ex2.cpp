#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>

std::list<int> bitstuff(std::list<int> l) {
	std::list<int> l2;
	std::list<int>::iterator itr = l.begin();
	int cnt = 0;
	
	while(itr != l.end()) {
		if(*itr == 1)
			cnt++;

		else
			cnt = 0;

		if(cnt > 4) {
			itr = l.insert(itr, 0);		
			itr++;
			cnt = 0;
		}

		itr++;
	}
	itr = l.begin();
	while(itr != l.end()) 
		l2.push_back(*itr++);

	return l2;
}

std::list<int> bitUnstuff(std::list<int> l) {
	std::list<int> l2;
	std::list<int>::iterator itr = l.begin();
	int cnt = 0;

	while(itr != l.end()) {
		if(*itr == 1)
			cnt++;
		else
			cnt = 0;

		std::cout << cnt << std::endl;
		if(cnt > 4) {
			std::cout << "yo, might be removing a 0, yo" << std::endl;
			std::list<int>::iterator check = itr;
			check++;
			if(*check == 0) {
				check++;
				if(*check == 1) {
					check++;
					if(*check == 1) {
						--check;
						l.erase(--check);	
					}
				}
			}
			cnt = 0;
		}
		itr++;
	}

	itr = l.begin();
	while(itr != l.end())
		l2.push_back(*itr++);

	return l2;
}

int main() {
	std::list<int> chan;
	std::list<int> stuffedChan;
	std::list<int> unstuffedChan;
	int diffSize;


	do {
		int i;
		std::cout << "enter a 0 or 1. Enter anything else to quit" << std::endl;
		std::cin >> i;
		if(i != 0 && i != 1)
			break;
		chan.push_back(i);
	} while(true);

/*
	for(int i=0; i < 15; i++) {
		chan.push_back(1);
	}
*/

	std::cout << "bit sequence = " << std::endl;
	std::copy(chan.begin(), chan.end(), std::ostream_iterator<int>(std::cout, " "));	
	std::cout << std::endl;


	std::cout << "applying bit-stuffing to sequence" << std::endl;
	stuffedChan = bitstuff(chan);

	
	std::cout << "bit sequence after bit stuffing" << std::endl;
	std::copy(stuffedChan.begin(), stuffedChan.end(), std::ostream_iterator<int>(std::cout, " "));	
	std::cout << std::endl;

	diffSize = stuffedChan.size() - chan.size();

	std::cout << "original length: " << chan.size() << std::endl;
	std::cout << "new length: " << stuffedChan.size() << std::endl;
	std::cout << "absolute expansion: " << diffSize << std::endl;
	std::cout << "relative expansion: " << (float)diffSize / chan.size() << std::endl;

	unstuffedChan = bitUnstuff(stuffedChan);
	std::cout << "unstuffed channel = " << std::endl;
	std::copy(unstuffedChan.begin(), unstuffedChan.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std:: endl;

	std::cout << "comparision of original message with message being stuffed and unstuffed equals " ;
	std::cout << ((chan == unstuffedChan) ? "True" : "False") << std::endl;
	
}
