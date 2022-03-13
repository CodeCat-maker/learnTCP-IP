//
// Created by 王泽鹏 on 2022/3/9.
//
#include <iostream>
#include <unistd.h>
using namespace std;
int val1;
int main(){
    int val1 = 1;
    int val2 = 10;
    pid_t pid = 0;
    pid = fork();
    if(pid == 0){
        ::val1 += 1;
        cout << ::val1 << endl;
        cout << ++val1 << "  " << ++val2 << "\n";
    }else{
        ::val1 += 1;
        cout << ::val1 << endl;
        cout << --val1 << " "<< --val2 << "\n";
    }
    return 0;
}