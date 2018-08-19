#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class CashSuper
{
public:
	virtual double acceptMoney(double money)=0;
};

class CashNormal:public CashSuper
{
public:
	double acceptMoney(double money)
	{
		return money;
	}
};

class CashRebate:public CashSuper
{
private:
	double discount;
public:
	CashRebate(double dis)
	{
		discount=dis;
	}
	double acceptMoney(double money)
	{
		return money*discount;
	}
};


class CashReturn:public CashSuper
{
private:
	double moneyCondition;
	double moneyReturn;
public:
	CashReturn(double mc,double mr)
	{
		moneyCondition=mc;
		moneyReturn=mr;
	}
	double acceptMoney(double money)
	{
		double result=money;
		if(money>=moneyCondition)
		{
			result=money-floor(money/moneyCondition)*moneyReturn;
		}
		return result;
	}
};

class  CashContext
{
private:
	CashSuper *cs;
public:
	CashContext(CashSuper *cs)
	{
		this->cs=cs;
	}
	double getResult(double money)
	{
		return cs->acceptMoney(money);
	}
};


int main()
{
	CashSuper *cs;
	CashContext *cc;
	double money;
	
	money=1000;
	cs=new CashRebate(0.8);
	cc=new CashContext(cs);
	cout<<cc->getResult(money)<<endl;

	money=1000;
	cs=new CashNormal();
	cc=new CashContext(cs);
	cout<<cc->getResult(money)<<endl;


	return 0;
}