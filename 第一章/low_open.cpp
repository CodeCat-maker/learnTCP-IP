//
// Created by 王泽鹏 on 2022/3/7.
//

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
using namespace std;
void error(string msg);
int main(){
    int fd; //文件句柄
    char buf[] = "hello world";
    fd = open("data.txt",O_CREAT|O_RDWR|O_TRUNC);
    if(fd == -1){
        error("open() error");
    }
    cout << "file des: " << fd;
    if(write(fd,buf, sizeof(buf)) == -1)
        error("wirte() error");
    close(fd);
    return 0;
}
void error(string msg){
    cout << msg << endl;
    exit(1);
}