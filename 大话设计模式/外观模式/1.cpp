#include <iostream>
#include <string>
using namespace std;

class Sub1
{
public:
	void f1()
	{
		cout<<"子系统的方法 1"<<endl;
	}
};

class Sub2
{
public:
	void f2()
	{
		cout<<"子系统的方法 2"<<endl;
	}
};

class Sub3
{
public:
	void f3()
	{
		cout<<"子系统的方法 3"<<endl;
	}
};

class Facade
{
private:
	Sub1 *s1;
	Sub2 *s2;
	Sub3 *s3;
public:
	Facade()
	{
		s1=new Sub1();
		s2=new Sub2();
		s3=new Sub3();
	}
	void method()
	{
		s1->f1();
		s2->f2();
		s3->f3();
	}
};

int main()
{
	Facade *f=new Facade();
	f->method();s
	return 0;
}