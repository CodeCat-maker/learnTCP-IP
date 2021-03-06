#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock;
	int clnt_sock;

    //定义服务器和客户端socket数据结构
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[]="Hello World!";
	
	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	//建立socket网络流 采用 IPV4 面向链接的传递方式
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling((char*)"socket() error");
	//初始化地址信息
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET; //IPV4链接方式
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY); //将本机ip传入
	serv_addr.sin_port=htons(atoi(argv[1])); //获取参数传递端口

    //绑定socket
	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1 )
		error_handling((char*)"bind() error");

    //进入等待链接
	if(listen(serv_sock, 5)==-1)
		error_handling((char*)"listen() error");
	
	clnt_addr_size=sizeof(clnt_addr);  
	clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);
	if(clnt_sock==-1)
		error_handling((char*)"accept() error");
	
	write(clnt_sock, message, sizeof(message));
	close(clnt_sock);	
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
