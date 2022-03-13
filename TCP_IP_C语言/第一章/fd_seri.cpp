//
// Created by 王泽鹏 on 2022/3/7.
//

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(){
    int fd1,fd2,fd3;
    fd1 = socket(PF_INET,SOCK_STREAM,0);
    fd2 = open("test.dat",O_CREAT|O_WRONLY|O_TRUNC);
    fd3 = socket(PF_INET,SOCK_STREAM,0);

    cout << fd1 << " " << fd2 << " " << fd3;
    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}