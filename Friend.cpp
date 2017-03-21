#include <iostream>

using namespace std;

class One
{
	int a;
public:
	One(){a=1;}
	One(int one):a(one){}
	friend void setTwo(One& one);
	void showOne(){cout<<a<<endl;}
};

void setTwo(One& one)
{
	one.a=2;
}

int main(int argc, char const *argv[])
{
	One *one=new One();
	One *one1=new One(10);

	one->showOne();
	one1->showOne();

	setTwo(*one);
	setTwo(*one1);

	one->showOne();
	one1->showOne();

	return 0;
}