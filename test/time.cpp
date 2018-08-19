#include <iostream>
#include <sys/socket.h>
using namespace std;
int MAXLINE=1024;
int main(int argc, char const *argv[])
{
	int sockfd,n;
	char recvline[MAXLINE +1];
	sockaddr_in servaddr;
	if (argc !=2)
	{
		cerr<<"usage: gettime <IPAddress>"<<endl;
	}
	if ((sockfd=socket(AF_INET,SOCK_STREAM,,0))<0)
	{
		cerr<<"socket error"<<endl;
	}
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(13);
	if (inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0){
		cerr<<"inet_pton error for "<<argv[1]<<endl;
	}
	if (connect(sockfd,(SA*) &servaddr,sizeof(servaddr))<0){
		cerr<<"connect error "<<endl;
	}
	while((n=read(sockfd,recvline,MAXLINE))>0){
		recvline[n]=0;
		if (fputs(recvline,stdout)==EOF)
		{
			cerr<<"fputs error"<<endl;
		}
	}
		if(n<0){
			cerr<<"read error"<<endl;
		}
		return 0; 
}	
