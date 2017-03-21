#include <iostream>

using namespace std;

/*char pointer accesses last 1-byte data instead of int 4-byte data.So-
1.If last byte is one(true) then LSB is 1-hence little endian
2.If last byte is zero(false) then MSB is 0-hence big endian. */

int main(int argc, char const *argv[])
{
	int a=1;
	char* ptr;

	ptr=(char*)&a;
	bool b=*ptr;

	cout<<a<<"\t"<<*ptr<<"\t"<<b<<endl;
	if(b)
		cout<<"Little Endian";
	else
		cout<<"Big Endian";
	return 0;
}