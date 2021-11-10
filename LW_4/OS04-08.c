#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/syscall.h>

void* OS04_07_T1(void* arg){
    __pid_t pid = getpid();
    int tid = syscall(SYS_gettid);
    for(int i = 1; i <= 75; i++){
        if(i == 50){
            printf("Child sleep for 10 sec");
            sleep(10);
        }
        printf("Child PID-%d TID-%d %d\n",pid,tid,i);
        sleep(1);
    }
    pthread_exit("Child thread");
}

int main(){
    pthread_t thread;
    void* thread_result;
    __pid_t pid = getpid();
    int tid = syscall(SYS_gettid);
    
    int res = pthread_create(&thread, NULL, OS04_07_T1, NULL);

    for(int i = 1; i <= 100; i++){
        if(i == 30){
            printf("Main sleep for 10 sec");
            sleep(15);
        }
        printf("PID-%d TID-%d %d\n",pid,tid,i);
        sleep(1);
    }

    int status = pthread_join(thread, (void**)&thread_result);

    exit(0);
}