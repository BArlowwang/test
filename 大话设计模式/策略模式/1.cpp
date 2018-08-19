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

class CashFactory
{
public:
	static CashSuper *createCashAccept(string str)
	{
		CashSuper *cs=NULL;
		if(str=="正常收费")
		{
			return new CashNormal();
		}
		else if(str=="打9折")
		{
			return new CashRebate(0.9);
		}
		else if(str=="满300返200")
		{
			return new CashReturn(300,200);
		}
		return cs;
	}
};


int main()
{
	CashSuper *cs;
	
	cs=CashFactory::createCashAccept("打9折");
	cout<<cs->acceptMoney(1000)<<endl;

	cs=CashFactory::createCashAccept("正常收费");
	cout<<cs->acceptMoney(1000)<<endl;

	return 0;
}