#include <iostream>
#include <string>
using namespace std;

class Prototype
{
private:
	string str;
public:
	Prototype(string s)
	{
		str=s;
	}
	Prototype()
	{
		str="";
	}
	void show()
	{
		cout<<str<<endl;
	}
	virtual Prototype *clone()=0;
};

class ConcretePrototype1:public Prototype
{
public:
	ConcretePrototype1(string s):Prototype(s)
	{}
	ConcretePrototype1(){}
	virtual Prototype *clone()
	{
		ConcretePrototype1 *p=new ConcretePrototype1();
		*p=*this;
		return p;
	}
};


class ConcretePrototype2:public Prototype
{
public:
	ConcretePrototype2(string s):Prototype(s)
	{}
	ConcretePrototype2(){}
	virtual Prototype *clone()
	{
		ConcretePrototype2 *p=new ConcretePrototype2();
		*p=*this;
		return p;
	}
};

int main()
{
	ConcretePrototype1 *test=new ConcretePrototype1("Ð¡Àî");
	ConcretePrototype2 *test2=(ConcretePrototype2 *)test->clone();
	test->show();
	test2->show();
	return 0;
}