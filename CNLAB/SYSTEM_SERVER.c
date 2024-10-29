#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main() {
    int sockfd,new_sockfd,rval;
    char buf1[10],buf2[20];
    struct sockaddr_in server,client;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sockfd < 0) {
        printf("Sock err\n");
        exit(0);
    }

    rval = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    if(rval < 0) {
        printf("Bind err\n");
        exit(0);
    }

    listen(sockfd, 5);

    while(1) {
        int len = sizeof(client);
        new_sockfd = accept(sockfd, (struct sockaddr*)&client, &len);
        if(new_sockfd < 0) {
            printf("Accept err\n");
            exit(0);
        }
        printf("Client Connected\n");

        rval = recv(new_sockfd, buf1, sizeof(buf1), 0);
        if(rval < 0) {
            printf("Recv Error\n");
            exit(0);
        }
        printf("Command Message & len: %ld %s\n",strlen(buf1),buf1);

        system(buf1);
    }
}