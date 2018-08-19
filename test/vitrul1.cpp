#include <iostream>
using namespace std;
class pos{
public:
	pos(){};
	~pos(){};
	int x,y;
};
class Shape {
 public:
     Shape(){};
     virtual  ~Shape();
     virtual void render();
     void move(const pos&){};
     virtual void resize();
protected:
     pos  center;
};

int main()
{
pos p;
Shape s;
cout<<sizeof(p)<<endl;
cout<<sizeof(s)<<endl;
return 0;
}

