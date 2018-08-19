#include <iostream>
#include <list>
#include <string>
using namespace std;

class Context;

class AbstractExpression
{
public:
	virtual void interpret(Context *)=0;
};

class TerminalExpression:public AbstractExpression
{
public:
	void interpret(Context *context)
	{
		cout<<"ÖÕ¶Ë½âÊÍÆ÷"<<endl;
	}
};

class NonterminalExpression:public AbstractExpression
{
public:
	void interpret(Context *context)
	{
		cout<<"·ÇÖÕ¶Ë½âÊÍÆ÷"<<endl;
	}
};

class Context
{
public:
	string input,output;
};

int main()
{
	Context *context=new Context(); 
	list<AbstractExpression*>  lt;
	lt.push_back(new TerminalExpression());
	lt.push_back(new NonterminalExpression());
	lt.push_back(new TerminalExpression());
	lt.push_back(new TerminalExpression());
	
	for(list<AbstractExpression*>::iterator iter=lt.begin();iter!=lt.end();iter++)
	{
		(*iter)->interpret(context);
	}
	
	return 0;
}