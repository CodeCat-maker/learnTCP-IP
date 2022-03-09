//
// Created by 王泽鹏 on 2022/3/9.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int status;
    pid_t pid = fork();
    if(pid ==0){
        return 3;
    }
    else{
        printf("Child PID : %d \n",pid);
        pid = fork();
        if(pid == 0)
            exit(7);
        else{
            printf("Child PID : %d \n",pid);
            wait(&status);
            if(WIFEXITED(status))
                printf("Child send one: %d \n", WEXITSTATUS(status));

            wait(&status);
            if(WIFEXITED(status))
                printf("Child send one: %d \n", WEXITSTATUS(status));
            sleep(30);
        }
    }
    return 0;
}