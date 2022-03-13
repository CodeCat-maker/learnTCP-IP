//
// Created by 王泽鹏 on 2022/3/8.
//
#include <iostream>
#include <arpa/inet.h>

using std::cout;
using std::endl;
int main(){
    char *addr1 = (char *)"1.2.3.4";
    char *addr2 = (char *)"1.2.3.256";

    unsigned long conv_addr = inet_addr(addr1);
    if(conv_addr == INADDR_NONE)
        std::cout << "Error" << std::endl;
    else
        printf("Netword ordered integer addr: %#lx \n",conv_addr);
    conv_addr = inet_addr(addr2);

    if(conv_addr == INADDR_NONE)
        std::cout << "Error" << std::endl;
    else
        printf("Netword ordered integer addr: %#lx \n",conv_addr);


}