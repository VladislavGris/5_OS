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
    cpu_set_t set;
    CPU_ZERO(&set);
    int c = nice(0);
    for(int i = 0; i < 100; i++){
        printf("i: %d\n",i);
        printf("PID-%d\n",pid);
        printf("TID-%d\n",tid);
        printf("nice-%d\n",getpriority(PRIO_PROCESS, 0));
        printf("Available processors:");
        if(sched_getaffinity(0, sizeof(cpu_set_t), &set)==0){
            int is = 0;
            for(int i = 0; i < __CPU_SETSIZE; i++){
                is = CPU_ISSET(i, &set);
                if(is == 1){
                    printf(" %d", i);
                }
            }
            printf("\n----------------------------------------\n");
        }else{
            printf("shed_getaffinity = ERROR");
        }
        sleep(1);
    }
    

    exit(0);
}