#include<iostream>
#include "Queue.h"
using namespace std;

int main() {

	Queue<int> q ;
	Queue<int> q1;
	q.enqueue(5) ;
	q.enqueue(4) ;
	q1.enqueue(3);
	q1.enqueue(2);

	q.merge(q1) ;

	while(!q.isEmpty()) {
		cout << q.dequeue() << endl;
	}


}
