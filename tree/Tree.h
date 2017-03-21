#include <iostream>
#include "Node.cpp"

using namespace std;

class Tree
{
	Node* root;

	int totalEle(Node* N);
	Node* findEle(int value);

public:
	Tree();
	Tree(int value);

	Node* getRoot();
	void setRoot(Node*);

	void insertIntoTree(int value);
	void findElement(int value);

	void preOrder(Node* root);
	void inOrder(Node* root);
	void postOrder(Node* root);

	Node* deleteElement(int value);

	int findMin();
	int findMax();

	int sumPath(int value);
	int totalElements();
};