#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main() {
    int sockfd,rval;
    char buf[100];
    struct sockaddr_in server, client;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd < 0)  {
        printf("Socket Err\n");
        exit(0);
    }

    printf("Enter Message : ");
    scanf("%s",buf);
    int len = sizeof(client);   
    rval = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&server,len);
    if(rval > 0) {
        printf("Msg Sent\n");
        int len = sizeof(server);
        rval = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&server, &len);
        if(rval > 0)
        printf("received Ack : %s",buf);
        else printf("Receive Error!\n");
    }
    else {
        printf("Error in sending msg\n");
    }
}