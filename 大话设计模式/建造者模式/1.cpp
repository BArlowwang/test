#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Person
{
public:
	virtual void createHead()=0;
	virtual void createHand()=0;
	virtual void createBody()=0;
	virtual void createFoot()=0;
};

class ThinPerson:public Person
{
	void createHead()
	{
		cout<<"thin head"<<endl;
	}
	void createHand()
	{
		cout<<"thin hand"<<endl;
	}
	void createBody()
	{
		cout<<"thin body"<<endl;
	}
	void createFoot()
	{
		cout<<"thin foot"<<endl;
	}
};

class FatPerson:public Person
{
	void createHead()
	{
		cout<<"fat head"<<endl;
	}
	void createHand()
	{
		cout<<"fat hand"<<endl;
	}
	void createBody()
	{
		cout<<"fat body"<<endl;
	}
	void createFoot()
	{
		cout<<"fat foot"<<endl;
	}
};


class Director
{
private:
	Person *p;
public:
	Director(Person *temp)
	{
		p=temp;
	}
	void create()
	{
		p->createHead();
		p->createHand();
		p->createBody();
		p->createFoot();
	}
};

//¿Í»§¶Ë´úÂë£º
int main()
{
    Person *p=new FatPerson();
	Director *d= new Director(p);
	d->create();
	delete d;
	delete p;
	return 0;
}