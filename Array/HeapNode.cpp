#include <iostream>

using namespace std;

class HeapNode
{
	int value;
	int parentArray;
	int arrayPos;

public:
	HeapNode():value(0),parentArray(0),arrayPos(0){}
	HeapNode(int v,int pa,int ap):value(v),parentArray(pa),arrayPos(ap){}
	HeapNode* getHeapNode(){return this;}
	int getHeapValue(){return this->value;}
	int getParentArray(){return this->parentArray;}
	int getArrayPos(){return this->arrayPos;}
	void setHeapNode(const HeapNode& n)
	{
		this->value=n.value;
		this->parentArray=n.parentArray;
		this->arrayPos=n.arrayPos;
	}
	void setHeapNode(int v,int pa,int ap)
	{
		this->value=v;
		this->parentArray=pa;
		this->arrayPos=ap;
	}

	friend bool operator == (HeapNode& a,HeapNode& b);
	friend bool operator != (HeapNode& a,HeapNode& b);
	friend bool operator <  (HeapNode& a,HeapNode& b);
	friend bool operator > (HeapNode& a,HeapNode& b);
	friend bool operator <= (HeapNode& a,HeapNode& b);
	friend bool operator >= (HeapNode& a,HeapNode& b);

	
};

bool operator == (HeapNode& a,HeapNode& b)
{
	return (a.value==b.value);
}

bool operator != (HeapNode& a,HeapNode& b)
{
	return (a.value!=b.value);
}
bool operator <  (HeapNode& a,HeapNode& b)
{
	return (a.value<b.value);
}
bool operator > (HeapNode& a,HeapNode& b)
{
	return (a.value>b.value);
}
bool operator <= (HeapNode& a,HeapNode& b)
{
	return (a.value<=b.value);
}
bool operator >= (HeapNode& a,HeapNode& b)
{
	return (a.value>=b.value);
}

