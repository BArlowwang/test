#include <iostream>
#include <string>
#include <map>
using namespace std;

class Flyweight
{
public:
	virtual void operation(int)=0;
};

class ConcreteFlyweight:public Flyweight
{
	void operation(int extrinsicState)
	{
		cout<<"具体FlyWeight: "<<extrinsicState<<endl;
	}
};

class UnsharedConcreteFlyweight:public Flyweight
{
	void operation(int extrinsicState)
	{
		cout<<"不共享的具体FlyWeight: "<<extrinsicState<<endl;		
	}
};

class FlyweightFactory
{
private:
	map<string,Flyweight*> flyweights;
public:
	FlyweightFactory()
	{
		flyweights["X"]=new ConcreteFlyweight();
		flyweights["Y"]=new ConcreteFlyweight();
		flyweights["Z"]=new ConcreteFlyweight();
	}
	Flyweight *getFlyweight(string key)
	{
		return (Flyweight *)flyweights[key];
	}
};


int main()
{
	int state=22;
	FlyweightFactory *f=new FlyweightFactory();
	
	Flyweight *fx=f->getFlyweight("X");
	fx->operation(--state);
	
	Flyweight *fy=f->getFlyweight("Y");
	fy->operation(--state);

	Flyweight *fz=f->getFlyweight("Z");
	fz->operation(--state);

	Flyweight *uf=new UnsharedConcreteFlyweight();
	uf->operation(--state);

	return 0;
}