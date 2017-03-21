#include "Node.h"
using namespace std;

Node :: Node():data(0),next(NULL){}

//Node :: Node(int d):data(d),next(NULL){}

Node :: ~Node(){}

Node* Node :: getNode()
{
	return this;
}

int Node :: getData()
{
	return this->data;
}

Node* Node :: getNext()
{
	return (this->next);
}

void Node:: setNode(Node* newNode)
{
	if (newNode != NULL)
	{
		this->next=newNode->next;
	    this->data=newNode->data;
	}
	else
	{
		this->data=0;
		this->next=NULL;
	}
	
}

void Node:: setData(int value)
{
	this->data=value;
}

void Node :: setNext(Node* N)
{
	this->next=N;
}

/*Node& Node :: operator = (const Node& node)
{
	if(this!=&node)
	{
	this->data=node.data;
	this->next=node.next;
	//*this=*(&node);
	}
	return *this;
}
*/
/*void moveNext(Node* N)
{
	if(N!=NULL)
	 N=N->next;
	//return N;
}
*/


