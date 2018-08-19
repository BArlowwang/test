#include <iostream>
#include <string>
#include <list>

using namespace std;

class Barbecuer
{
public:
	void bakeMutton()
	{
		cout<<"¿¾ÑòÈâ´®"<<endl;
	}
	void bakeChickenWing()
	{
		cout<<"¿¾¼¦³á"<<endl;
	}
};

class Command
{
protected:
	Barbecuer *receiver;
public:
	Command(Barbecuer *receiver)
	{
		this->receiver=receiver;
	}
	virtual void executeCommand()=0;
};

class BakeMuttonCommand:public Command
{
public:
	BakeMuttonCommand(Barbecuer *receiver):Command(receiver)
	{}
	void executeCommand()
	{
		receiver->bakeMutton();
	}
};

class BakeChikenWingCommand:public Command
{
public:
	BakeChikenWingCommand(Barbecuer *receiver):Command(receiver)
	{}
	void executeCommand()
	{
		receiver->bakeChickenWing();
	}
};

class Waiter
{
private:
	Command *command;
public:
	void setOrder(Command *command)
	{
		this->command=command;
	}
	void notify()
	{
		command->executeCommand();
	}
};

class Waiter2
{
private:
	list<Command*> orders;
public:
	void setOrder(Command *command)
	{
		orders.push_back(command);
	}
	void cancelOrder(Command *command) 
	{}
	void notify()
	{
		list<Command*>::iterator iter=orders.begin();
		while(iter!=orders.end())
		{
			(*iter)->executeCommand();
			iter++;
		}
	}
};


int main()
{
	
	Barbecuer *boy=new Barbecuer();
	Command *bm1=new BakeMuttonCommand(boy);
	Command *bm2=new BakeMuttonCommand(boy);
	Command *bc1=new BakeChikenWingCommand(boy);
	
	Waiter2 *girl=new Waiter2();

	girl->setOrder(bm1);
 	girl->setOrder(bm2);
 	girl->setOrder(bc1);
	
	girl->notify();



	/*
	Barbecuer *boy=new Barbecuer();
	Command *bm1=new BakeMuttonCommand(boy);
	Command *bm2=new BakeMuttonCommand(boy);
	Command *bc1=new BakeChikenWingCommand(boy);
	
	Waiter *girl=new Waiter();

	girl->setOrder(bm1);
	girl->notify();

	girl->setOrder(bm2);
	girl->notify();

	girl->setOrder(bc1);
	girl->notify();

	*/		

	return 0;
}