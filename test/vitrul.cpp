#include <iostream>
using namespace std;
class A 
{
	public:
		virtual void g(){
			 cout<<"print g()"<<endl;
		}
};
int main()
{
	A a;
	cout<<sizeof(a)<<endl;
}
