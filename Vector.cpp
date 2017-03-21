#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int>  v_int;
	vector<char> v_char;

	vector<int>:: iterator p;

	cout<<"size:"<<v_int.size()<<endl;

	for(int i=0;i<26;++i)
		v_int.push_back(i+'A');
	cout<<"size:"<<v_int.size()<<endl;
	
	for(int i=0;i<26;++i)
		cout<<v_int[i]<<"\t";

	cout<<endl;

	for(int i=0;i<v_int.size();++i)
	{
		v_char.push_back(v_int[i]);
		cout<<v_char[i]<<"\t";
	}

	cout<<endl;

	p=v_int.begin();
	p=p+13;

	v_int.erase(p,p+5);
	cout<<"size:"<<v_int.size()<<endl;

	for(int i=0;i<v_int.size();++i)
		cout<<v_int[i]<<"\t";

	p=v_int.begin();
	p=p+13;
	v_int.insert(p,5,'a');
	cout<<"size:"<<v_int.size()<<endl;

	for(int i=0;i<v_int.size();++i)
		cout<<v_int[i]<<"\t";


	return 0;
}