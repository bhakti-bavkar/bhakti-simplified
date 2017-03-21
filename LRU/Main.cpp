#include <iostream>
#include <map>
#include <deque>
#include "Page.cpp"

#define MAX_FRAMES 3

typedef std::map<int,Page*> PageTable;
typedef pair<int,Page*> mapPair;

typedef std::deque<Page> myCache;
		int frameCount=0; 

void createPagetable(PageTable& pt, int size)
{
	Page* p=NULL;

	for(int i=0;i<size;i++)
	{
		p=new Page(i);
		pt.insert(mapPair(i,p));
	}

	//return pt;
}

Page* getPageFromPageTable(PageTable& pt,int num)
{
	PageTable :: iterator p=pt.begin();

	p=pt.find(num);

	if(p!=pt.end())
		return p->second;
	else
		return NULL;
}

bool isCacheFull()
{
	return (frameCount == MAX_FRAMES);
}

bool isCacheEmpty()
{
	return (frameCount == 0);
}

void pageReference(myCache& cache,PageTable& pt,int num)
{
	Page temp(num);

	myCache:: iterator p=cache.begin();
	//p=find(cache.begin(),cache.end()temp);
	int i=0;
	while(p!=cache.end())
	{
		if(cache.at(i)==temp) break;
		p++;
		i++;
	}

	if(p==cache.begin())
	{
		cout<<"\nPage Hit: "<<num;	
	}
	else if(p!=cache.end())//Page already found in Cache
	{
		Page* page=p->getPage();
		Page newPage(*page);
		cout<<"\nPage Hit: "<<num;;
		cache.erase(p);
		cache.push_front(newPage);
	}
	else//Page not found in cache
	{
		cout<<"\nPage Fault: "<<num;
		Page* page=getPageFromPageTable(pt,num);
		if(!isCacheFull())
		{
			cache.push_front(*page);
			++frameCount;
		}
		else
		{
			if(!isCacheEmpty())
			{
				cache.pop_back();
				cache.push_front(*page);
			}

		}
	}
}

void printCache(myCache& cache)
{
	Page page(0);
	cout<<"\nCache: ";
	for(int i=0;i<cache.size();++i)
	{
		page=cache.at(i);
		cout<<"\t"<<page.getPageNumber();
	}
	cout<<"\n";
}

int main(int argc, char const *argv[])
{
	int pages[10];//={3,4,1,5,4,2,9,5,2,1};

	PageTable pt;
	myCache cache;

	createPagetable(pt,20);

	cout<<"Enter page number of requested pages: ";
	for(int i=0;i<10;++i)
		cin>>pages[i];

	for(int i=0;i<10;++i)
	{
		printCache(cache);
		pageReference(cache,pt,pages[i]);
		//printCache(cache);

	}

	return 0;
}