#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main() {
    int sockfd, new_sockfd,rval;
    char buf[10];
    struct sockaddr_in server, client;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sockfd <0) {
        printf("Socket Err\n");
        exit(0);
    }

    rval = connect(sockfd, (struct sockaddr*)&server, sizeof(server));
    if(rval <0) {
        printf("Connect Err\n");
        exit(0);
    }
    printf("Enter Command : ");
    scanf("%s",buf);

    rval = send(sockfd, buf,sizeof(buf),0);
    if(rval <0) {
        printf("Send err\n");
        exit(0);
    }
}