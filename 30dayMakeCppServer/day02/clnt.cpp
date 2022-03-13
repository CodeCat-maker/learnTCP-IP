//
// Created by 王泽鹏 on 2022/3/13.
//
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include "util.h"

int main(){
    int sockfd = socket(PF_INET,SOCK_STREAM,0);
    errif(sockfd == -1,"socket() error");

    sockaddr_in serv_addr,clnt_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8888);

    errif(connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1, "socket connect error");

    while (1){
        char buf[1024];
        bzero(&buf, sizeof(buf));
        std::cin >> buf;
        ssize_t write_bytes = write(sockfd,buf, sizeof(buf));

        if (write_bytes == -1){
            std::cout << "connect has being closed\n";
            break;
        }

        bzero(&buf, sizeof(buf));

        ssize_t read_bytes = read(sockfd,buf, sizeof(buf));
        if (read_bytes > 0){
            std::cout << "message from server : " << buf << std::endl;
        }else if(read_bytes == 0){
            printf("server socket disconnected!\n");
            break;
        }else if(read_bytes == -1){
            close(sockfd);
            errif(true, "socket read error");
        }
    }
    close(sockfd);
    return 0;
}