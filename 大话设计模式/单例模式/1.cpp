#include <iostream>
#include <string>
using namespace std;

class Singleton
{	
private:
	int i;
	static Singleton *instance;
	Singleton(int i)
	{
		this->i=i;
	}
public:
	static Singleton *getInstance()
	{
		return instance;
	}
	void show()
	{
		cout<<i<<endl;
	}
};
Singleton* Singleton::instance=new Singleton(8899); 

class A:public Singleton
{

};

int main()
{
	Singleton *s=Singleton::getInstance();
	Singleton *s2=A::getInstance();
	cout<<(s==s2)<<endl;
	return 0;
}