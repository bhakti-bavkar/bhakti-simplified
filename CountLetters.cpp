#include <iostream>
#include <string>

using namespace std;

void countLetters(string& str)
{
	int j=0;

	for(int i=0; str[i]!='\0'; ++i)
	{
		j=0;
		cout<<str[i];
		while(str[i]==str[i+1] && str[i]!='\0')
		{
			++j;
			++i;
		}
		cout<<j+1;
	}
}

int main()
{
	string str;

	cout<<"Enter string of letters\n";
	cin>>str;

	countLetters(str);
	return 0;
}