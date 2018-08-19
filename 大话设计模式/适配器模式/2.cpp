#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
	string name;
	Player(string name)
	{
		this->name=name;
	}
	virtual void attack()=0;
	virtual void defence()=0;
}; 

class Forwards:public Player
{
public:
	Forwards(string name):Player(name){}
	void attack()
	{
		cout<<name<<" Ç°·æ½ø¹¥"<<endl;
	}
	void defence()
	{
		cout<<name<<" Ç°·æ·ÀÊØ"<<endl;
	}
};

class Center:public Player
{
public:
	Center(string name):Player(name){}
	void attack()
	{
		cout<<name<<" ÖÐ·æ½ø¹¥"<<endl;
	}
	void defence()
	{
		cout<<name<<" ÖÐ·æ·ÀÊØ"<<endl;
	}
};

class Backwards:public Player
{
public:
	Backwards(string name):Player(name){}
	void attack()
	{
		cout<<name<<" ºóÎÀ½ø¹¥"<<endl;
	}
	void defence()
	{
		cout<<name<<" ºóÎÀ·ÀÊØ"<<endl;
	}
};
/*****************************************************************/
class ForeignCenter
{
public:
	string name;
	ForeignCenter(string name)
	{
		this->name=name;
	}
	void myAttack()
	{
		cout<<name<<" Íâ¼®ÖÐ·æ½ø¹¥"<<endl;
	}
	void myDefence()
	{
		cout<<name<<" Íâ¼®ºóÎÀ·ÀÊØ"<<endl;
	}
};
/*****************************************************************/
class Translator:public Player
{
private:
	ForeignCenter *fc;
public:
	Translator(string name):Player(name)
	{
		fc=new ForeignCenter(name); 
	}
	void attack()
	{
		fc->myAttack();
	}
	void defence()
	{
		fc->myDefence();
	}
};
/*****************************************************************/
int main()
{
	Player *p1=new Center("Àî¿¡ºê");
	p1->attack();
	p1->defence();
	
	Translator *tl=new Translator("Ò¦Ã÷");
	tl->attack();
	tl->defence();
	
	return 0;
}