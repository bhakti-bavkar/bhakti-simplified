#include <iostream>

using namespace std;

class Page
{
	int pageNumber;

public:
	Page(int page):pageNumber(page){}
	Page* getPage(){return this;}
	int getPageNumber(){return this->pageNumber;}

	friend bool operator == (Page& P1,Page& P2);
	friend bool operator != (Page& P1,Page& P2);

};

bool operator == (Page& P1,Page& P2)
{
	return (P1.pageNumber == P2.pageNumber);
}


bool operator != (Page& P1,Page& P2)
{
	return (P1.pageNumber != P2.pageNumber);
}
