#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(){
    int tid = syscall(SYS_gettid);
    __pid_t pid = getpid();
    for(int i = 1; i <= 1000; i++){
        printf("PID-%d TID-%d %d\n",pid,tid,i);
        sleep(1);
    }
}