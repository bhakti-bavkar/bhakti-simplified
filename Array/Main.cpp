#include <iostream>
#include "MinHeap.cpp"

using namespace std;

template<size_t rows,size_t cols>
void generateSortedArray(int (&a)[rows][cols],int result[])
{
	int i=0,j=1,k=0;

	MinHeap heapSort;
	HeapNode* top=NULL;

	for(i=0;i<rows;++i)
	{
		heapSort.insert(a[i][0],i,0);
		heapSort.showHeap();
		cout<<endl;
	}

	i=0;

	while(k<rows*cols)
	{
		top=heapSort.extract();
		if(top)
		{
			result[k++]=top->getHeapValue();
			i=top->getParentArray();
			j=top->getArrayPos();

			if(j+1>=cols) continue;

			heapSort.insert(a[i][j+1],i,j+1);
			heapSort.showHeap();
			cout<<endl;
		}
		else
			break;
	}
}

int main(int argc, char const *argv[])
{
	int arrayMat[3][4]={{9,16,100,101},
						{300,450,500,600},
						{29,84,90,98}};

	int result[12];
	for(int i=0;i<12;++i)
		result[i]=0;

	generateSortedArray(arrayMat,result);

	cout<<"Final array: ";
	for(int i=0;i<12;++i)
		cout<<result[i]<<'\t';
	

	return 0;
}