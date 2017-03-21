#include <iostream>
#include <map>
#include <deque>
#include "Page.cpp"

class PageTable
{
	typedef std::map<int,Page*> pageTable;
	typedef std::map<int,Page*>:: iterator ptr;

public:
	PageTable(int size);
	Page* getPageFromPageTable(int num);
	void add

};
