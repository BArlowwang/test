#include <iostream>
#include <string>
using namespace std;

class Operation
{
public:
	double numberA,numberB;
	virtual double  getResult()
	{
		return 0;
	}
};

class addOperation:public Operation
{
	double getResult()
	{
		return numberA+numberB;
	}
};

 
class subOperation:public Operation
{
	double getResult()
	{
		return numberA-numberB;
	}
};

class mulOperation:public Operation
{
	double getResult()
	{
		return numberA*numberB;
	}
};

class divOperation:public Operation
{
	double getResult()
	{
		return numberA/numberB;
	}
};

class operFactory
{
public:
	static Operation *createOperation(char c)
	{
		switch(c)
		{
		case '+':
			return new addOperation;
			break;

		case '-':
			return new subOperation;
			break;

		case '*':
			return new mulOperation;
			break;

		case '/':
			return new divOperation;
			break;
		}
	}
};

int main()
{
	Operation *oper=operFactory::createOperation('+');
	oper->numberA=9;
	oper->numberB=99;
	cout<<oper->getResult()<<endl;
	return 0;
}