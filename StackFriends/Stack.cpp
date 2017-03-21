#include "Stack.h"

#define MAX 5

using namespace std;

Stack :: Stack():top(NULL),size(MAX),stack_count(0){}

Stack :: Stack(size_t size):top(NULL),size(size),stack_count(0){}

bool Stack :: isEmpty()
{
	if(this->top != NULL)
		return false;
	else
		return true;

}

bool Stack :: isFull()
{
	if(this->stack_count==size)
		return true;
	else
		return false;
}

void Stack :: push(int d)
{
	if(this->isFull())
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}
	else
	{
		//Node* newNode= new Node(d);
		Node* newNode= new Node();
		newNode->setData(d);
		if(!top)
			top=newNode;
		else
		{
			newNode->setNext(top);
			top=newNode;
		}
		++stack_count;
	}

}

int Stack :: pop()
{
	Node* temp;
	Node* cur;
	int value=0;

	if(this->isEmpty())
	{
		cout<<"Stack Underflow"<<endl;
	}
	else
	{
		temp=top;
		value=top->getData();
		moveNext(top);
		delete (temp);
		cout<<"Data popped is "<<value<<endl;
		--stack_count;
	}
	return value;
}

void Stack :: EmptyStack()
{
	int data=0;
	if(this->isEmpty())
	{
		cout<<"Already Empty"<<endl;
		return;
	}
	else
	{
		while(this->top)
			data=pop();
	}

}


void moveNext(Node* N)
{
	if(N!=NULL)
	 N=N->next;
	//return N;
}
