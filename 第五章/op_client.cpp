//
// Created by 王泽鹏 on 2022/3/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define RIL_SIZE 4
#define OPSZ 4
void error_handing(char *msg){
    fputs(msg,stderr);
    fputc('\n',stderr);
    exit(1);
}
int main(int argc,char *argv[]){
    int sock;
    char opmsg[BUF_SIZE];
    int result,opnd_cnt;
    struct sockaddr_in serv_adr;
    if(argc != 3){
        printf("Usage : %s <ip> <port>\n", argv[0]);
        exit(1);
    }
    sock = socket(PF_INET,SOCK_STREAM,0);
    if(sock == -1){
        error_handing((char*)"socket() error");
    }
    //初始化链接地址
    memset(&serv_adr,0,sizeof (serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    if(connect(sock,(struct sockaddr*) &serv_adr,sizeof (serv_adr)) == -1)
        error_handing((char*)"connect() error");
    else
        puts("connect ....");
    fputs("Opeartor count",stdout);
    scanf("%d",&opnd_cnt);
    opmsg[0] = (char)opnd_cnt;

    for(int i = 0 ; i < opnd_cnt ; i ++){
        printf("Operator %d:",i+1);
        scanf("%d",(int*)&opmsg[i*OPSZ  + 1]);
    }

    fgetc(stdin);



}