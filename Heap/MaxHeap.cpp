#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
	std::vector<int> mH;
	//int size;
	//int position;
	
	void bubbleUp();
	void sinkDown(int k);
	void swap(int &a,int &b);

public:
	MaxHeap(){}
	MaxHeap* getMaxHeap(){return this;}
	int getHeapSize();
	void insert(int num);
	int Extract();
	int search(int num,int k);
};

int MaxHeap :: getHeapSize()
{
	return (mH.size()-1);
}

void MaxHeap :: insert(int num)
{
	if(mH.empty())
	{
		mH.push_back(0);
		mH.push_back(num);
	}
	else
	{
		mH.push_back(num);
		bubbleUp();
	}
}

void MaxHeap :: bubbleUp()
{
	if(mH.size()<=2) return;

	int k=mH.size()-1;

	while(k>1 && mH[k]>mH[k/2])
	{
		swap(mH[k],mH[k/2]);
		k=k/2;
	}
}

int MaxHeap :: Extract()
{
	if(mH.empty()|| mH.empty()) return 0;
	else
	{
		int top=0;
		int last=mH.size();
		top=mH[1];
		if(mH.size()>2)
		{
			swap(mH[1],mH[last-1]);
			mH.pop_back();
			sinkDown(1);
		}
		else
			mH.pop_back();

		return top;
	}
}

void MaxHeap :: sinkDown(int k)
{
	if(k==0 || mH.empty()) return;

	if(mH.size()==2) return;

	int large=mH[k];
	int last=mH.size();
	
	while(k<last)
	{
		if(2*k<last && mH[k]<mH[2*k])
			large=mH[2*k];
		if((2*k)+1 <last && mH[k]<mH[2*k+1])
			large=mH[2*k+1];

		if(large!=mH[k])
		{
			swap(large,mH[k]);
			k=2*k;
		}
		else
			break;
	}
}

void MaxHeap :: swap(int &a,int &b)
{
	int t;
	t=a;a=b;b=t;
}

int MaxHeap :: search(int num,int k)
{
	if(mH[k]==num) return k;

	if(mH[k]==0) return 0;

	int last=mH.size();
	if(k>last) return 0;

	if(2*k<last && mH[2*k]>mH[k])
	{
		int result=search(num,2*k);
		if(result>0)
			return result;
	}
	if(2*k+1<last && mH[2*k+1]>mH[k])
	{
		int result=search(num,2*k+1);
		if(result>0)
			return result;
	}
	return 0;
}