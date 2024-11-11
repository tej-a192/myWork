#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<fcntl.h>
#include<netinet/tcp.h>
#include<arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    int a,b,c,len;

    len = sizeof(a);
    getsockopt(sockfd, IPPROTO_TCP,TCP_MAXSEG,&a,&len);

    printf("MAx SEGMENT : %d\n",a);
    len = sizeof(b);
    getsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &b, &len);
    printf("Value before : %d\n",b);
    len = sizeof(c);
    int flag = 1;
    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &flag,len);

    getsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &c, &len);
    printf("Value After : %d\n",c);

    int d;
    len = sizeof(d);
    getsockopt(sockfd,SOL_SOCKET, SO_KEEPALIVE, &d,&len);
    printf("KEEP before  : %d",d);

    flag = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &flag, sizeof(flag));
    int e;
    len = sizeof(e);
    getsockopt(sockfd,SOL_SOCKET, SO_KEEPALIVE, &e,&len);
    printf("KEEP After  : %d",e);
}