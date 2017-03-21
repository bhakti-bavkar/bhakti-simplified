#include <iostream>
#include "Node.cpp"

using namespace std;

class Stack
{
	Node* top;
	size_t size ;
	int stack_count;

	bool isEmpty();
	bool isFull();

public:
	Stack();
	Stack(size_t size);
	void push(int data);
	int pop();
	void EmptyStack();

};