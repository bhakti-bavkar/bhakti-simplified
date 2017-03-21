#include <iostream>

using namespace std;

class Node
{
	int data;
	Node* left;
	Node* right;

public:
	Node();
	Node(int data);
	Node* getNode();
	int getData();
	Node* getLeft();
	Node* getRight();
	void setNode(Node* N);
	void setData(int v);
	void setLeft(Node* N);
	void setRight(Node* N);
	Node* moveLeft(Node* N);
	Node* moveRight(Node* N);
	//Node& operator = (const Node& node);
	~Node();

};