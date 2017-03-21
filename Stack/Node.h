#include <iostream>

using namespace std;

class Node
{
	int data;
	Node* next;

public:
	Node();
	//Node(int data);
	Node* getNode();
	int getData();
	Node* getNext();
	void setNode(Node* N);
	void setData(int v);
	void setNext(Node* N);
	Node* moveNext(Node* N);
	//Node& operator = (const Node& node);
	~Node();

};