#include "Node.h"
using namespace std;

Node :: Node():data(0),left(NULL),right(NULL){}

Node :: Node(int d):data(d),left(NULL),right(NULL){}

Node :: ~Node(){}

Node* Node :: getNode()
{
	return this;
}

int Node :: getData()
{
	return this->data;
}

Node* Node :: getLeft()
{
	return (this->left);
}

Node* Node :: getRight()
{
	return (this->right);
}

void Node:: setNode(Node* newNode)
{
	if (newNode != NULL)
	{
		this->left =newNode->left;
	    this->right=newNode->right;
	    this->data =newNode->data;
	}
	else
	{
		this->data =0;
		this->left =NULL;
		this->right=NULL;
	}
	
}

void Node:: setData(int value)
{
	this->data=value;
}

void Node :: setLeft(Node* N)
{
	this->left=N;
}

void Node :: setRight(Node* N)
{
	this->right=N;
}

Node* Node :: moveLeft(Node* N)
{
	if(N!=NULL)
	 N=N->left;
	return N;
}

Node* Node :: moveRight(Node* N)
{
	if(N!=NULL)
	 N=N->right;
	return N;
}


/*Node& Node :: operator = (const Node& node)
{
	if(this!=&node)
	{
	this->data=node.data;
	this->next=node.next;
	*this=*(&node);
	}
	return *this;
}

*/

