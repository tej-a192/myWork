#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main() {
    int sockfd, new_sockfd,rval;
    struct sockaddr_in server, client;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sockfd < 0) {
        printf("Sock err\n");
        exit(0);
    }

    rval = connect(sockfd, (struct sockaddr*)&server, sizeof(server));
    if(rval < 0) {
        printf("Connect Err\n");
        exit(0);
    }
    int len = sizeof(server);

    rval = getpeername(sockfd, (struct sockaddr*)&server, &len);
    if(rval < 0) {
        printf("Peer Err\n");   
        exit(0);
    }

    printf("Server Ip Addr : %s\n",inet_ntoa(server.sin_addr));
    printf("Server Port : %d\n",ntohs(server.sin_port));
}