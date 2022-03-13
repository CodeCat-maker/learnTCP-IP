#include <iostream>
#include <arpa/inet.h>

using std::cout;
using std::endl;

int main(){
    struct sockaddr_in addr1,addr2;
    char *str_ptr;
    char str_arr[20];

    addr1.sin_addr.s_addr = htonl(0x1020304);
    addr2.sin_addr.s_addr = htonl(0x1010101);

    //返回字符串地址
    str_ptr = inet_ntoa(addr1.sin_addr);
    strcpy(str_arr,str_ptr);
    std::puts(str_ptr);

    inet_ntoa(addr2.sin_addr);
    std::puts(str_ptr);
    std::puts(str_arr);
}