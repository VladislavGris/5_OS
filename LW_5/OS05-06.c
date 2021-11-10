#define _GNU_SOURCE
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sched.h>

int main(){
    int tid = syscall(SYS_gettid);
    __pid_t pid = getpid();
    int c = nice(19);
    for(int i = 0; i < 1000; i++){
        printf("i: %d\n",i);
        printf("PID-%d\n",pid);
        printf("TID-%d\n",tid);
        printf("nice-%d\n",getpriority(PRIO_PROCESS, 0));
        sleep(1);
    }
    exit(0);
}