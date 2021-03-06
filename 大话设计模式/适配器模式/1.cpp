#include <iostream>
#include <string>
using namespace std;

class Adaptee
{
public:
	virtual void myRequest()
	{
		cout<<"实际上的接口"<<endl;
	}
};

class Target
{
public:
	virtual void request()=0;
	~virtual Target(){}
};

class Adapter:public Target
{
private:
	Adaptee adaptee;
public:
	void request()
	{
		adaptee.myRequest();
	}
};

int main()
{
	Target *target=new Adapter();
	target->request();
	delete target;
	return 0;
}