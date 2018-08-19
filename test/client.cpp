#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define MYPORT  7000
#define BUFFER_SIZE 1024
int main()
{
    int sock_cli;
    fd_set rfds;
    struct timeval tv;
    int retval, maxfd;

    ///����sockfd
    sock_cli = socket(AF_INET,SOCK_STREAM, 0);
    ///����sockaddr_in
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(MYPORT);  ///�������˿�
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  ///������ip

    //���ӷ��������ɹ�����0�����󷵻�-1
    if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    while(1){
        /*�ѿɶ��ļ��������ļ������*/
        FD_ZERO(&rfds);
        /*�ѱ�׼������ļ����������뵽������*/
        FD_SET(0, &rfds);
        maxfd = 0;
        /*�ѵ�ǰ���ӵ��ļ����������뵽������*/
        FD_SET(sock_cli, &rfds);
        /*�ҳ��ļ������������������ļ�������*/    
        if(maxfd < sock_cli)
            maxfd = sock_cli;
        /*���ó�ʱʱ��*/
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        /*�ȴ�����*/
        retval = select(maxfd+1, &rfds, NULL, NULL, &tv);
        if(retval == -1){
            printf("select�����ͻ��˳����˳�\n");
            break;
        }else if(retval == 0){
            printf("�ͻ���û���κ�������Ϣ�����ҷ�����Ҳû����Ϣ������waiting...\n");
            continue;
        }else{
            /*��������������Ϣ*/
            if(FD_ISSET(sock_cli,&rfds)){
                char recvbuf[BUFFER_SIZE];
                int len;
                len = recv(sock_cli, recvbuf, sizeof(recvbuf),0);
                printf("%s", recvbuf);
                memset(recvbuf, 0, sizeof(recvbuf));
            }
            /*�û�������Ϣ��,��ʼ������Ϣ������*/
            if(FD_ISSET(0, &rfds)){
                char sendbuf[BUFFER_SIZE];
                fgets(sendbuf, sizeof(sendbuf), stdin);
                send(sock_cli, sendbuf, strlen(sendbuf),0); //����
                memset(sendbuf, 0, sizeof(sendbuf));
            }
        }
    }

    close(sock_cli);
    return 0;
}