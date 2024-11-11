#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
int main() {
    int sockfd,new_sockfd,rval;
    struct sockaddr_in server,client;
    struct timeval timeout;
    fd_set readfds;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    sockfd = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    listen(sockfd, 5);

    printf("Server is listening\n");

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;


    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    int ready_fds = select(sockfd+1, &readfds, NULL,NULL, &timeout);

    if(ready_fds < 0) {
        printf("Select failed!");
        exit(0);
    }
    if(ready_fds == 0) {
        printf("TimeOut\n");
        exit(0);
    }
    int len = sizeof(client);
    if(accept(sockfd, (struct sockaddr*)&client, &len) < 0)
        printf("Accept Error\n");

    printf("Connected!");

}