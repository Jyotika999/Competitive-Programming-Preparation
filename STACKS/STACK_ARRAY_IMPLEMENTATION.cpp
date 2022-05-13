#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
	int *container; //Array for storing data
	int noOfElements;
	int capacity;
public:
	Stack () {
		noOfElements = 0;
		capacity = 1000;
		container = new int[capacity];
	}
	
	Stack (int capacity) {
		noOfElements = 0;
		this->capacity = capacity;
		container = new int[capacity];
	}

	bool isFull() {
		return noOfElements == capacity;
	}

	bool isEmpty() {
		return noOfElements == 0;
	}
	
	int size() {
		return noOfElements;
	}
	
	int top() {
		if (noOfElements == 0) {
			return -1;
		}
		return container[noOfElements - 1];
	}
	
	void push(int element) {
		if (isFull()) {
			return;
		}
		container[noOfElements] = element;
		noOfElements++;
	}
	
	void pop() {
		if (noOfElements == 0) {
			return;
		}
		noOfElements--;
	}
};

int main() {
	// your code goes here
	Stack stack(10);
	cout << stack.top() << " " << stack.isEmpty() << " " << stack.size() << endl;
	stack.push(5);
	cout << stack.top() << " " << stack.isEmpty() << " " << stack.size() << endl;
	stack.push(6);
	cout << stack.top() << " " << stack.isEmpty() << " " << stack.size() << endl;
	stack.push(7);
	cout << stack.top() << " " << stack.isEmpty() << " " << stack.size() << endl;
	stack.pop();
	cout << stack.top() << " " << stack.isEmpty() << " " << stack.size() << endl;
	stack.pop();
	cout << stack.top() << " " << stack.isEmpty() << " " << stack.size() << endl;
	stack.pop();
	cout << stack.top() << " " << stack.isEmpty() << " " << stack.size() << endl;
	return 0;
}