#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/resource.h>
#include <sched.h>

void parent(){
    int tid = syscall(SYS_gettid);
    __pid_t pid = getpid();
    for(int i = 0; i < 1000; i++){
        printf("i: %d\n",i);
        printf("PID-%d\n",pid);
        printf("TID-%d\n",tid);
        printf("nice-%d\n",getpriority(PRIO_PROCESS, 0));
        sleep(1);
    }
    exit(0);
}

void child(){
    nice(10);
    int tid = syscall(SYS_gettid);
    __pid_t pid = getpid();
    for(int i = 0; i < 1000; i++){
        printf("i: %d\n",i);
        printf("PID-%d\n",pid);
        printf("TID-%d\n",tid);
        printf("nice-%d\n",getpriority(PRIO_PROCESS, 0));
        sleep(1);
    }
    exit(0);
}

int main()
{
    pid_t pid;
    switch (pid = fork())
    {
    case -1:
        perror("fork");
        exit(1);
        break;
    case 0:
        child();
        break;
    default:
        parent();
        break;
    }
    return 0;
}