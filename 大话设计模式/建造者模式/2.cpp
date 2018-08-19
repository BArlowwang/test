#include <string>
#include <iostream>
#include <vector>
using namespace std;



class Product
{
private:
	vector<string> product;
public:
	void add(string str)
	{
		product.push_back(str);
	}
	void show()
	{
		vector<string>::iterator iter=product.begin();
		while(iter!=product.end())
		{
			cout<<*iter<<"  ";
			++iter;
		}
		cout<<endl;
	}
};

class Builder
{
public:
	virtual void builderA()=0;
	virtual void builderB()=0;
	virtual Product *getResult()=0;
};

class ConcreteBuilder1:public Builder
{
private:
	Product *product;
public:
	ConcreteBuilder1()
	{
		product=new Product();
	}
	virtual void builderA()
	{
		product->add("one");
	}
	virtual void builderB()
	{
		product->add("two");
	}
	virtual Product *getResult()
	{
		return product;
	}
};


class ConcreteBuilder2:public Builder
{
private:
	Product *product;
public:
	ConcreteBuilder2()
	{
		product=new Product();
	}
	virtual void builderA()
	{
		product->add("A");
	}
	virtual void builderB()
	{
		product->add("B");
	}
	virtual Product *getResult()
	{
		return product;
	}
};

class Director
{
private:
	Product *p;
public:
	void construct(Builder *bd)
	{
		bd->builderA();
		bd->builderB();
		p=bd->getResult();
	}
	Product *getResult()
	{
		return p;
	}
};


int main()
{
	Director *director=new Director();

	Builder *bd1=new ConcreteBuilder1();
	director->construct(bd1);
	Product *pbd1=director->getResult();

	pbd1->show();

	

	return 0;
}



/*
#include <string>
#include <iostream>
#include <vector>
using namespace std;



class Product
{
private:
	vector<string> product;
public:
	void add(string str)
	{
		product.push_back(str);
	}
	void show()
	{
		vector<string>::iterator iter=product.begin();
		while(iter!=product.end())
		{
			cout<<*iter<<"  ";
			++iter;
		}
		cout<<endl;
	}
};

class Builder
{
public:
	virtual void builderA()=0;
	virtual void builderB()=0;
	virtual Product *getResult()=0;
};

class ConcreteBuilder1:public Builder
{
private:
	Product *product;
public:
	ConcreteBuilder1()
	{
		product=new Product();
	}
	virtual void builderA()
	{
		product->add("one");
	}
	virtual void builderB()
	{
		product->add("two");
	}
	virtual Product *getResult()
	{
		return product;
	}
};


class ConcreteBuilder2:public Builder
{
private:
	Product *product;
public:
	ConcreteBuilder2()
	{
		product=new Product();
	}
	virtual void builderA()
	{
		product->add("A");
	}
	virtual void builderB()
	{
		product->add("B");
	}
	virtual Product *getResult()
	{
		return product;
	}
};

class Director
{
public:
	void construct(Builder *bd)
	{
		bd->builderA();
		bd->builderB();
	}
};


int main()
{
	Director *director=new Director();

	Builder *bd1=new ConcreteBuilder1();
	director->construct(bd1);
	Product *pbd1=bd1->getResult();
	pbd1->show();

	Builder *bd2=new ConcreteBuilder2();
	director->construct(bd2);
	Product *pbd2=bd2->getResult();
	pbd2->show();
	

	return 0;
}

*/