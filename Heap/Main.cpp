#include <iostream>

#include "MaxHeap.cpp"

using namespace std;

int generateMaxRevenue(MaxHeap* Revenue,int k)
{
	int top=0,revenue=0;
	if(k==0) return 0;

	while(k>0)
	{
		top=Revenue->Extract();
		revenue+=top;
		top--;
		Revenue->insert(top);
		k--;
	}

	return revenue;
}

int main(int argc, char const *argv[])
{
	int maxRevenue=0;
	int windows[5]={6,10,3,7,14};

	MaxHeap* Revenue=new MaxHeap();

	for (int i = 0; i < 5; ++i)
	{
		Revenue->insert(windows[i]);
	}

	maxRevenue=generateMaxRevenue(Revenue,6);
	cout<<maxRevenue;

	delete Revenue;

	return 0;
}
