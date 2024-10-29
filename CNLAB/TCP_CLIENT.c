#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

int main() {
    int sockfd,rval;
    char buf[100], buf1[100];
    struct sockaddr_in server, client;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd < 0) {
        printf("Socket error\n");
        exit(0);
    }

    rval = connect(sockfd, (struct sockaddr*)&server, sizeof(server));
    if(rval < 0) {
        printf("Connection error\n");
        exit(0);
    }
    printf("Enter Message to Sent : ");
    scanf("%s",buf);

    rval = send(sockfd, buf, sizeof(buf), 0);
    if(rval > 0) {
        printf("Msg Sent\n");

        rval = recv(sockfd, buf1, sizeof(buf1), 0);
        if(rval > 0) {
            printf("Acknowledgement Received\n");
            printf("Received Msg : %s\n", buf1);
        }
    }
    else {
        printf("SEND Err\n");
    }
}