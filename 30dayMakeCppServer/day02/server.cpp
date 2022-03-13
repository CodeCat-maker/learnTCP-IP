//
// Created by 王泽鹏 on 2022/3/13.
//
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include "util.h"

int main(){
    int sockfd = socket(PF_INET,SOCK_STREAM,0);
    errif(sockfd == -1,"socket() error");

    struct sockaddr_in serv_adr,clnt_addr;
    bzero(&serv_adr, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(8888);

    errif(bind(sockfd,(struct sockaddr*)&serv_adr,sizeof (serv_adr)) == -1,"bind() error");

    errif(listen(sockfd,SOMAXCONN) == -1,"listen() error");

    socklen_t len_clnt = sizeof(clnt_addr);
    bzero(&clnt_addr, sizeof(clnt_addr));

    int clnt_sockfd = accept(sockfd,(sockaddr*)&clnt_addr,&len_clnt);
    errif(clnt_sockfd == -1,"accept() error");

    printf("new client fd %d! IP: %s Port: %d\n", clnt_sockfd, inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));

    while (true) {
        char buf[1024];
        bzero(&buf, sizeof(buf));
        ssize_t read_bytes = read(clnt_sockfd, buf, sizeof(buf));
        if(read_bytes > 0){
            printf("message from client fd %d: %s\n", clnt_sockfd, buf);
            write(clnt_sockfd, buf, sizeof(buf));
        } else if(read_bytes == 0){
            printf("client fd %d disconnected\n", clnt_sockfd);
            close(clnt_sockfd);
            break;
        } else if(read_bytes == -1){
            close(clnt_sockfd);
            errif(true, "socket read error");
        }
    }
    close(sockfd);
    return 0;
}