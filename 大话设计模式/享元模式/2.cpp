#include <iostream>
#include <list>
#include <string>
#include <map>
using namespace std;

class WebSite
{
public:
	virtual void use()=0;
}; 

class ConcreteWebSite:public WebSite
{
private:
	string name;
public:
	ConcreteWebSite(string name)
	{
		this->name=name;
	}
	void use()
	{
		cout<<"网站分类: "<<name<<endl;
	}
};

class WebSiteFactory
{
private:
	map<string,WebSite*> wf;
public:
	 
	WebSite *getWebSiteCategory(string key)
	{
		
		if(wf.find(key)==wf.end())
		{
			wf[key]=new ConcreteWebSite(key);
		}	

		return wf[key];
	}
	 
	int getWebSiteCount()
	{
		return wf.size();
	}
};

int main()
{
	WebSiteFactory *wf=new WebSiteFactory();

	WebSite *fx=wf->getWebSiteCategory("good");
	fx->use();
	
 	WebSite *fy=wf->getWebSiteCategory("产品展示");
	fy->use();

	WebSite *fz=wf->getWebSiteCategory("产品展示");
	fz->use();


	WebSite *f1=wf->getWebSiteCategory("博客");
	f1->use();

	WebSite *f2=wf->getWebSiteCategory("博客");
	f2->use();

	cout<<wf->getWebSiteCount()<<endl;
	return 0;
}