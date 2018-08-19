#include <iostream>
#include <string>
using namespace std;

class Iterator;

class Aggregate
{
public:
	virtual Iterator *createIterator()=0;
};

class Iterator
{
public:
	virtual void first()=0;
	virtual void next()=0;
	virtual bool isDone()=0;
};

class ConcreteAggregate:public Iterator
{
public:
	void first()
	{}
	void next()
	{}
	bool isDone()
	{}
};


int main()
{
	return 0;
}