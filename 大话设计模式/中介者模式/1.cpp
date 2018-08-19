#include<iostream>
#include <string>
using namespace std;

class Mediator;
class ConcreteColleague1;
class ConcreteColleague2;

class Colleague
{
protected:
	Mediator *mediator;
public:
	Colleague(Mediator *mediator)
	{
		this->mediator=mediator;
	}
};


class ConcreteColleague1:public Colleague
{
public:
	ConcreteColleague1(Mediator *mediator):Colleague(mediator)
	{}
	void send(string message);
	void notify(string message)
	{
		cout<<"同事1得到消息: "<<message<<endl;
	}
};

class ConcreteColleague2:public Colleague
{
public:
	ConcreteColleague2(Mediator *mediator):Colleague(mediator)
	{}
	void send(string message);
	void notify(string message)
	{
		cout<<"同事2得到消息: "<<message<<endl;
	}
};

class Mediator
{
public:
	virtual void send(string name,Colleague *colleague)=0;
};

class ConcreteMediator:public Mediator
{
public:
	ConcreteColleague1 *colleague1;
	ConcreteColleague2 *colleague2;
public:
	void send(string message,Colleague *colleague)
	{
		if(colleague==colleague1)
		{
			colleague2->notify(message);
		}
		else
		{
			colleague1->notify(message);
		}
	}
};

  
void ConcreteColleague1::send(string message) 
{
	mediator->send(message,this);
}

void ConcreteColleague2::send(string message) 
{
	mediator->send(message,this);
}

int main()
{
	ConcreteMediator *m=new ConcreteMediator();
	ConcreteColleague1 *c1=new ConcreteColleague1(m);
	ConcreteColleague2 *c2=new ConcreteColleague2(m);

	m->colleague1=c1;
	m->colleague2=c2;

	c1->send("吃饭啦");
	c2->send("去 ");

	return 0;
}
 