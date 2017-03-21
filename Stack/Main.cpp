#include <iostream>

#include "Stack.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	int ele=0;

	cout<<"I've finally done it!!! Lets start the show\n";

	Stack *s= new Stack();
	cout<<s->pop();
	s->push(1);
	s->push(2);
	s->push(3);
	s->push(4);
	s->push(5);
	s->push(6);
	s->pop();
	s->pop();
	s->pop();
	s->pop();
	s->pop();
	s->pop();
	return 0;
}