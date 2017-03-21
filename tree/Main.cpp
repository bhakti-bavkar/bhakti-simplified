#include <iostream>
#include "Tree.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	Tree *t=new Tree();

	t->insertIntoTree(45);
	t->insertIntoTree(23);
	t->insertIntoTree(105);
	t->insertIntoTree(80);
	t->insertIntoTree(92);
	t->insertIntoTree(35);

	t->inOrder(t->getRoot());
	cout<<"\n"<<t->findMin();
	cout<<"\n"<<t->findMax();
	cout<<"\n"<<t->totalElements();
	cout<<"\n";
	t->findElement(35);

	return 0;
}

