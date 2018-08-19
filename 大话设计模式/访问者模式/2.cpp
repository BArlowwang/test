#include <iostream>
#include <list>
#include <string>
using namespace std;
 
class Man;
class Woman;

class Action
{
public:
	virtual void getManConclusion(Man *)=0;
	virtual void getWomanConclusion(Woman *)=0;
}; 

class Success:public Action
{
	void getManConclusion(Man *)
	{
		cout<<"男人成功时，背后多半有一个伟大的女人"<<endl;
	}
	void getWomanConclusion(Woman *)
	{
		cout<<"女人成功时，背后多半有不成功的男人"<<endl;
	}

};

class Love:public Action
{
	void getManConclusion(Man *)
	{
		cout<<"男人恋爱时，凡事不懂装懂"<<endl;
	}
	void getWomanConclusion(Woman *)
	{
		cout<<"女人恋爱时，凡事懂也装不懂"<<endl;
	}
};

class Person
{
public:
	virtual void accept(Action*)=0;
};

class Man:public Person
{
public:
	void accept(Action* visitor)
	{
		visitor->getManConclusion(this);
	}
};

class Woman:public Person
{
public:
	void accept(Action* visitor)
	{
		visitor->getWomanConclusion(this);
	}
};

class ObjectStructure
{
private:
	list<Person*> elements;
public:
	void attach(Person* element)
	{
		elements.push_back(element);
	}
	void detach(Person* element)
	{
		for(list<Person*>::iterator iter=elements.begin();iter!=elements.end();++iter)
		{
			if((*iter)==element)
			{
				elements.erase(iter);
			}
		}
	}
	void display(Action *visitor)
	{
		for(list<Person*>::iterator iter=elements.begin();iter!=elements.end();++iter)
		{
			(*iter)->accept(visitor);
		}
	}
};

int main()
{
 

	Success *s=new Success();
	os->display(s);

	Love *lv=new Love();
	os->display(lv);

	return 0;
}