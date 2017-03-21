#include <iostream>
#include <vector>
#include "HeapNode.cpp"

using namespace std;

class MinHeap
{
	std::vector<HeapNode> mh;

	void bubbleUp();
	void sinkDown(int k);
	void swap(HeapNode& a,HeapNode& b);

public:
	MinHeap(){}
	void insert(int v,int pa,int ap);
	HeapNode* extract();
	void showHeap();
};

void MinHeap :: swap(HeapNode& a,HeapNode& b)
{
	HeapNode t;
	t=a;a=b;b=t;
}

void MinHeap :: insert(int v,int pa,int ap)
{
	HeapNode temp;

	if(mh.empty())
	{
		mh.push_back(temp);
		temp.setHeapNode(v,pa,ap);
		mh.push_back(temp);
	}
	else
	{
		temp.setHeapNode(v,pa,ap);
		mh.push_back(temp);
		bubbleUp();
	}
}

void MinHeap :: bubbleUp()
{
	if(mh.empty()) return;

	//if(mh.size()<2) return;

	int k=mh.size()-1;
	
	while(k>1 && mh[k]<mh[k/2])
	{
		swap(mh[k],mh[k/2]);
		k=k/2;
	}
}

HeapNode* MinHeap :: extract ()
{
	HeapNode *top;
	top=NULL;

	if(mh.empty() || mh.size()==1) 
		return top;
	
	HeapNode temp(mh[1]);
	top=&temp;

	if(mh.size()>2)
	{
		swap(mh[1],mh.back());
		mh.pop_back();
		sinkDown(1);
	}
	else
		mh.pop_back();

	return top;
}

void MinHeap :: sinkDown(int k)
{
	if(mh.empty() || mh.size()==1) 
		return;

	HeapNode smallest(mh[k]);
	int last=mh.size();

	
	while(k<last)
	{
		if(2*k<last && mh[2*k]<mh[k])
			smallest=mh[2*k];

		if(2*k+1<last && mh[2*k+1]<mh[k])
			smallest=mh[2*k+1];

		if(smallest!=mh[k])
		{
			swap(smallest,mh[k]);
			k=2*k;
		}
		else
			break;
	}
}

void MinHeap :: showHeap()
{
	cout<<"Heap Data: ";
	for(int i=0;i<mh.size();++i)
	{
		cout<<mh[i].getHeapValue()<<'\t';
	}
}