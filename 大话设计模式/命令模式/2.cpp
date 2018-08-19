//将一个请求封装为一个对象，从而使你可用不同的请求
//对客户进行参数化；对请求排队或者记录请求日志，以及支持可撤销操作。





#include<iostream>
#include <string>
using namespace std;

class Receiver
{
public:
	void action()
	{
		cout<<"执行请求"<<endl;
		//具体如何执行这个命令。
	}
};

class Command
{
protected:
	Receiver *receiver;
public:
	Command(Receiver *receiver)
	{
		this->receiver=receiver;
	}
	virtual void execute()=0;
};

class ConcreteCommand:public Command
{
public:
	ConcreteCommand(Receiver *receiver):Command(receiver)
	{}
	void execute()
	{
		receiver->action();
	}
};

class Invoker
{
private:
	Command *command;
public:
	void setCommand(Command *command)
	{
		this->command=command;
	}
	void executeCommand()
	{
		command->execute();
	}
};

int main()
{
	Receiver *r=new Receiver();
	Command *c=new ConcreteCommand(r);
	Invoker *i=new Invoker();

	i->setCommand(c);
	i->executeCommand();
	return 0;
}







 