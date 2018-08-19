#include <iostream>
using namespace std;
class A
{
	public:
		A(){
			cout<<1<<endl;
		}
		A(const A &a){
			x=a.x;
			cout<<2<<endl;
		}
		~A(){
			cout<<3<<endl;
		}
		A &operator =(const A &s ){
			cout<<4<<endl;
			return *this;
		}
		int x;
};

A fun(){
	A b;
	b.x=10;
	return b;
}
int main(){
	A a;
	a.x=1;
       	a=fun();
	cout<<"aa"<<a.x<<endl;
return 0;
}

