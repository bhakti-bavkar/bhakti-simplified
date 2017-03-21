#include <iostream>
#include <cstdlib>

using namespace std;

int* deleteDuplicates(int* a,int n)
{
	int i,j;
	
	for(i=0,j=0; i<n,j<n; ++i,++j)
	{
		while(a[j]==a[j+1])
			++j;
		a[i]=a[j];
	}

	if(i<j)
	{
		for(i;i<j;i++)
			a[i]=0;
	}
	return a;
}
int main()
{
	int i,a[10];
	
	int *ptr;
	ptr=&a[0];
	for(i=0;i<10;++i)
		{
			a[i]=0;
		}
	cout<<"Enter 10 Values into array.\n";
	for (i=0;i<10;i++) 
		cin>>a[i];

	ptr=deleteDuplicates(ptr,10	);

	cout<<"Final Array: ";
	for(i=0;i<10;++i)
	{
		cout<<a[i];
	}

 

	return 0;
}

