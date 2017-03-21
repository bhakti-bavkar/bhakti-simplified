#include <iostream>
#include "Tree.h"

using namespace std;

Tree :: Tree():root(new Node()){}

Tree :: Tree(int d):root(new Node(d)){}

Node* Tree :: getRoot()
{
	return root;
}

void Tree :: setRoot(Node* N)
{
	root=N;
}

void Tree :: insertIntoTree(int value)
{
	Node* temp;
	Node* prev;

	prev=NULL;
	temp=root;

	if (root->getData() == 0)
	{
		root->setData(value);
		return;
	}
	while (temp)
	{
		prev=temp;
		if (value<=temp->getData())
			temp=temp->moveLeft(temp);
		else
			temp=temp->moveRight(temp);
	}
	Node* newNode=new Node(value);
	if (value<=prev->getData())
		prev->setLeft(newNode);
	else
		prev->setRight(newNode);
}

Node* Tree :: findEle(int value)
{
	Node* temp= root;

	while(temp)
	{
		if(temp->getData()==value)
			return temp;
		else if (value<temp->getData())
			temp=temp->moveLeft(temp);
		else
			temp=temp->moveRight(temp);
	}

	return temp;
}

void Tree :: findElement(int value)
{
	Node* temp=findEle(value);

	if(!temp)
		cout<<"Element is not present in tree";
	else
		cout<<"Element is present in tree";
}

void Tree :: preOrder (Node* temp)
{
	if (!temp) return;
	cout<<temp->getData()<<"\t";
	preOrder(temp->moveLeft(temp));
	preOrder(temp->moveRight(temp));
}

void Tree :: inOrder (Node* temp)
{
	if (!temp) return;
	inOrder(temp->moveLeft(temp));
	cout<<temp->getData()<<"\t";
	inOrder(temp->moveRight(temp));
}

void Tree :: postOrder (Node* temp)
{
	if (!temp) return;
	postOrder(temp->moveLeft(temp));
	postOrder(temp->moveRight(temp));
	cout<<temp->getData()<<"\t";
}

int Tree :: findMin()
{
	Node* temp=root;

	while(temp->getLeft()!=NULL)
		temp=temp->moveLeft(temp);
	return temp->getData();
}

int Tree :: findMax()
{
	Node* temp=root;

	while(temp->getRight()!=NULL)
		temp=temp->moveRight(temp);
	return temp->getData();
}

int Tree :: sumPath(int value)
{
	int sum=0;
	Node* temp=root;

	while (temp)
	{
		sum+=temp->getData();
		if(value==temp->getData())
			break;
		if(value<temp->getData())
			temp=temp->moveLeft(temp);
		else
			temp=temp->moveRight(temp);
	}

	if (!temp) 
		return 0;
	else
		return sum;
}

int Tree :: totalElements()
{
	int count=0;
	Node* temp=root;

	if (!temp) return 0;
	count=totalEle(temp);
	return count;

}

int Tree :: totalEle(Node* temp)
{
	if(!temp) return 0;

	return(totalEle(temp->moveLeft(temp))+1+totalEle(temp->moveRight(temp)));
}

	




