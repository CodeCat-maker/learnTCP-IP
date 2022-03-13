//
// Created by 王泽鹏 on 2022/3/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void read_childProc(int sig);
int main(){


    struct sigaction act;
    act.sa_handler = read_childProc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    int state = sigaction(SIGCHLD,&act,0);

    int fds[2];
    pipe(fds);
    pid_t pid = fork();
    printf("%d\n",pid);
    if (pid == 0){
        char msg[1024];
        read(fds[0],msg,1024);
        puts(msg);
    }else{
        char msg[] = "hello world";
        write(fds[1],msg,sizeof (msg));
        printf("主进程\n");
    }
    return 0;
}

void read_childProc(int sig){
    pid_t pid;
    int status;
    pid = waitpid(-1,&status,WNOHANG);
    printf("removed proc id: %d \n", pid);
}