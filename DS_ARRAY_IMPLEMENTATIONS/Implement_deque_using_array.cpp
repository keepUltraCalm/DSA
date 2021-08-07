//DEQUE USING ARRAY

#include <iostream>
#include <climits>
using namespace std;

struct Deque {
	int cap, size, front, rear;
	int *arr;
	Deque(int c) {
		cap = c;
		arr = new int[cap];
		size = 0;
		front = 0;
		rear = 0;
	}
	int getFront() {
		if (Empty())
			return -1;
		return front;
	}
	int getRear() {
		if (Empty())
			return -1;
		return (front - 1 + size) % cap;
	}
	bool Full() {
		return (cap == size);
	}
	bool Empty() {
		return (size == 0);
	}
	void insertFront() {
		if (Full())
			return;
		front = (front - 1 + cap) % cap;
		size++;
	}
	void deleteFront() {
		if (Empty())
			return;
		front = (front + 1) % cap;
		size--;
		//size also decreased so deleted part par you never come back
	}
	void insertRear() {
		if (Full())
			return;
		rear = (rear + 1) % cap;
		size++;

	}
	void DeleteRear() {
		if (Empty())
			return;
		size--;
	}

};



int main() {
	return 0;
}

//array implementation (efficient) kar jaana sabki
//vector not jaruri..bas bta do efficiency increase
