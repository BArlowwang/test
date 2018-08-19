#include <iostream>
#include <string>
using namespace std;
 
class Resume
{
private:
	string name,sex,age,timeArea,company;
public:
	Resume(string s)
	{
		name=s;
	}
	void setPersonalInfo(string s,string a)
	{
		sex=s;
		age=a;
	}
	void setWorkExperience(string t,string c)
	{
		timeArea=t;
		company=c;
	}
	void display()
	{
		cout<<name<<"  "<<sex<<"  "<<age<<endl;
		cout<<"工作经历:  "<<timeArea<<"  "<<company<<endl<<endl;

	}
	Resume *clone()
	{
		Resume *b;
		b=new Resume(name);
		b->setPersonalInfo(sex,age);
		b->setWorkExperience(timeArea,company);
		return b;
	}
};


int main()
{
	Resume *r=new Resume("李俊宏"); 	 
	r->setPersonalInfo("男","26");
	r->setWorkExperience("2007-2010","读研究生");
	r->display();
	

	Resume *r2=r->clone();
	r2->setWorkExperience("2003-2007","读本科");
	
	r->display();
	r2->display();
	
	return 0;
}