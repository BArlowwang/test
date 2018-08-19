#include <iostream>
#include <list>
#include <string>
using namespace std;
 
 
class Person
{
public:
	string action;
	virtual void getConclusion()=0;
};


class Man:public Person
{
public:
	void getConclusion()
	{
		if(action=="成功")
		{
			cout<<"男人成功时，背后多半有一个伟大的女人。"<<endl;
		}
		else if(action=="恋爱")
		{
			cout<<"男人恋爱时，凡事不懂装懂。"<<endl;
		}		
	}
};

class Woman:public Person
{
public:
	void getConclusion()
	{
		if(action=="成功")
		{
			cout<<"女人成功时，背后多半有失败的男人。"<<endl;
		}
		else if(action=="恋爱")
		{
			cout<<"男人恋爱时，遇到事懂也装不懂。"<<endl;
		}		
	}
};

int main()
{
	list<Person*> persons;

	Person *man1=new Man();
	man1->action="成功";
	persons.push_back(man1);

	Person *woman1=new Woman();
	woman1->action="成功";
	persons.push_back(woman1);

	Person *man2=new Man();
	man2->action="恋爱";
	persons.push_back(man2);

	Person *woman2=new Woman();
	woman2->action="恋爱";
	persons.push_back(woman2);

	list<Person*>::iterator iter=persons.begin();
	while(iter!=persons.end())
	{
		(*iter)->getConclusion();
		++iter;
	}
	return 0;
}