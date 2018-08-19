#include<iostream>
#include <string>
using namespace std;

class Request
{
public:
	string requestType;
	string requestContent;
	int number;
};

class Manager
{
protected:
	string name;
	Manager *superior;
public:
	Manager(string name)
	{
		this->name=name;
	}
	void setSuperior(Manager *superior)
	{
		this->superior=superior;
	}
	virtual void requestApplications(Request *request)=0;
};

class CommonManager:public Manager
{
public:
	CommonManager(string name):Manager(name)
	{}
	void requestApplications(Request *request)
	{
		if(request->requestType=="请假" && request->number<=2)
		{
			cout<<name<<" "<<request->requestContent<<" 数量: "<<request->number<<"被批准"<<endl;
		}
		else 
		{
			if(superior!=NULL)
			{
				superior->requestApplications(request);
			}
		}
	}
};

class Majordomo:public Manager
{
public:
	Majordomo(string name):Manager(name)
	{}
	void requestApplications(Request *request)
	{
		if(request->requestType=="请假" && request->number<=5)
		{
			cout<<name<<" "<<request->requestContent<<" 数量: "<<request->number<<"被批准"<<endl;
		}
		else 
		{
			if(superior!=NULL)
			{
				superior->requestApplications(request);
			}
		}
	}
};


class GeneralManager:public Manager
{
public:
	GeneralManager(string name):Manager(name)
	{}
	void requestApplications(Request *request)
	{
		if(request->requestType=="请假")
		{
			cout<<name<<" "<<request->requestContent<<" 数量: "<<request->number<<"被批准"<<endl;
		}
	}
};


int main()
{
	CommonManager *jinli=new CommonManager("经理"); 
	Majordomo *zongjian=new Majordomo("总监");
	GeneralManager *zhongjingli=new GeneralManager("总经理");
	
	jinli->setSuperior(zongjian);
	zongjian->setSuperior(zhongjingli);
	
	Request *request=new Request();

	request->requestType="请假";
	request->requestContent="李俊宏请假";
	request->number=1;
	jinli->requestApplications(request);


	request->requestType="请假";
	request->requestContent="李俊宏请假";
	request->number=4;
	jinli->requestApplications(request);


	request->requestType="请假";
	request->requestContent="李俊宏请假";
	request->number=10;
	jinli->requestApplications(request);


	return 0;
}