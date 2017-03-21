#include <iostream>

using namespace std;

class Base
{
	public:
	int base;


	Base():base(0){cout<<"Base Default Constructor"<<endl;}
	Base(int data):base(data){cout<<"Base Constructor"<<endl;}

	virtual void show()
	{
		cout<<"This is Base: "<<base<<endl;
	}

};

class Derived : public Base
{
	int deri;

public:
	Derived():Base(),deri(0){cout<<"Derived Default Constructor"<<endl;}
	Derived(int data):Base(),deri(data){cout<<"Derived + Base Default Constructor"<<endl;}
	Derived(int data,int b):Base(b),deri(data){cout<<"Base + Derived Default Constructor"<<endl;}

	void show()
	{
		cout<<"This is Base in Derived: "<<base<<endl;		
		cout<<"This is Derived: "<<deri<<endl;
	}
};

int main(int argc, char const *argv[])
{	
	Base *b1=new Base();
	Derived *d1=new Derived();
 	Derived *d2=new Derived(10);
	Derived *d3=new Derived(40,10);
   
    b1->show();

    b1=d1;
    b1->show();
    
	b1=d2;
    b1->show();
    
    b1=d3;
    b1->show();
    
/*	Base *b2=new Base(100);

	Derived *d1=new Derived();
	Derived *d2=new Derived(10);
	Derived *d3=new Derived(40,10);

	b1->show();
	b2->show();
	d1->show();
	d2->show();
	d3->show();*/
	return 0;
}