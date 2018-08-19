#include <iostream>
#include <string>
using namespace std;


class SchoolGirl
{
public:
	string name;
};


class IGiveGift
{
public:
	virtual void giveDolls()=0;
	virtual void giveFlowers()=0;
};

class Pursuit:public IGiveGift
{
private:
	SchoolGirl mm;
public:
	Pursuit(SchoolGirl m)
	{
		mm=m;
	}
	void giveDolls()
	{
		cout<<mm.name<<" ËÍÄãÍÞÍÞ"<<endl;	
	}
	void giveFlowers()
	{
		cout<<mm.name<<" ËÍÄãÏÊ»¨"<<endl;	
	}
};

class Proxy:public IGiveGift
{
private:
	Pursuit gg;
public:
	Proxy(SchoolGirl mm):gg(mm)
	{
		//gg=g;
	}
	void giveDolls()
	{
		gg.giveDolls();
	}
	void giveFlowers()
	{
		gg.giveFlowers();
	}
};

int main()
{
	SchoolGirl lijiaojiao;
	lijiaojiao.name="Àî½¿½¿";
	Pursuit zhuojiayi(lijiaojiao); 
	Proxy daili(lijiaojiao);

	daili.giveDolls();
	return 0;
}