#include <iostream>
#include <map>

using namespace std;

void printOccurances(const string& s)
{
	std::map<char, int> myMap;
	std::map<char, int>::iterator p;

	for(int i=0;s[i]!='\0';++i)
	{
		p=myMap.find(s[i]);
		if(p==myMap.end())
		{
			myMap.insert(pair<char,int>(s[i],1));
		}
		else
		{
			p->second=p->second+1;
		}
		p=myMap.begin();
	}

	for(p=myMap.begin();p!=myMap.end();++p)
		cout<<p->first<<"->"<<p->second<<endl;
}

int main(int argc, char const *argv[])
{
	string s;

	cout<<"Enter string: ";
	cin>>s;

	printOccurances(s);
	return 0;
}