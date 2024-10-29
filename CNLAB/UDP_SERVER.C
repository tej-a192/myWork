#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>


int main() {
    int sockfd,rval;
    char buf[100], buf1[100] = "Ackn";
    struct sockaddr_in server, client;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd < 0) {
        printf("Socket Err\n");
        exit(0);
    }

    rval = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    if(rval < 0) {
        printf("Bind err\n");
        exit(0);
    }
    while(1) {
        int len = sizeof(client);
        rval = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&client, &len);
        if(rval > 0) {
            printf("Received Msg : %s",buf);
            rval = sendto(sockfd,buf1, sizeof(buf1),0, (struct sockaddr*)&client, len);
            if(rval > 0) {
                printf("Ack sent\n");
            }
            else printf("Ack Fail\n");
        }
        else printf("Recv Erro\n");
    }
}