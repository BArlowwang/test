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
	CashContext(string str)
	{
		if(str=="正常收费")
		{
			cs=new CashNormal();
		}
		else if(str=="打9折")
		{
			cs=new CashRebate(0.9);
		}
		else if(str=="满300送200")
		{
			cs=new CashReturn(300,200);
		}		
	}
	double getResult(double money)
	{
		return cs->acceptMoney(money);
	}
};


int main()
{
	double money=1000;
	CashContext *cc=new CashContext("打9折");
	cout<<cc->getResult(money);
	return 0;
}