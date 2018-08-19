#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;
int  main(int argc,char const *argv[])
{
	cout<<inet_addr(argv[1])<<endl;

}
