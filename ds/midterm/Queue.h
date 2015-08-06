#include<iostream>
#include "List.h"
using namespace std;

template <typename Object>
class Queue {

	private:
		List<Object> queue ;
		Object temp ;
		
	public:
		Queue () { }
	
		~Queue() {
			queue.clear() ;
		}

		Queue(const Queue & rhs) {
			*this = rhs ;
		}

/*
		const Queue & operator= (const Queue & rhs) {
			if(this == &rhs)
				return *this;
			queue.clear() ;
			while(!rhs.isEmpty()) {
				queue.push_back(rhs.dequeue()) ;
			}
		}
*/

		void enqueue(const Object & d) {
			queue.push_back(d) ;
		}

		Object & dequeue() {
			if(queue.empty()) {
				cout << "can't dequeue from empty queue!!" << endl; 
				exit(EXIT_FAILURE);
			}
			temp = queue.front() ;
			queue.pop_front() ;
			return temp ;
		}

		bool isEmpty() {
			if(queue.empty()) return true ;
			else return false;
		}

		void merge(Queue<Object> q1) {
			typename List<Object>::iterator itr = queue.begin();
			Object temp ;
			int size = queue.size();
			itr++;
			while(!q1.isEmpty()) {
				queue.push_back(*itr);
				*itr = q1.dequeue();
				itr++;
				temp = queue.back();
				queue.push_back(*itr);
				*itr = temp;
				itr++;
				
			}

			for(int i=0; i<size; i++) 
				queue.pop_back();
			
		}

} ;
			
