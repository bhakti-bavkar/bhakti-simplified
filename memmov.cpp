#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void memmov (int* dest, int* src,size_t n)
{
	int i=0;
	//char* d=(char*) dest;
	//char* s=(char*) src;

	if(abs(dest - src)>=n || dest-src<n)
	{
		for(i=0;i<n;i++)
			dest[i]=src[i];
	}
	else if(src-dest<n)
	{
		for(i=n-1;i>=0;--i)
			dest[i]=src[i];
	}

}

int main()
{
	int *src, *dest;

	src=(int*) malloc(10*sizeof(int));
	
	cout<<"Enter values:\n";
	for(int i=0;i<10;++i)
		cin>>src[i];

	dest=(int*) malloc(10*sizeof(int));

	for(int i=0;i<10;++i)
		dest[i]=0;

	memmov(dest,src,10);

	cout<<"Destination: ";
	for(int i=0;i<10;++i)
		cout<<dest[i]<<"\t";

	free(src);


	return 0;

}