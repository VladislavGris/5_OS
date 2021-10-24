#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#define PARENT_PROCESS "OS03-05"
#define CHILD_PROCESS "OS03-05-01"

void cycle(int iteration, const char* p_name){
    for(int i = 1; i <= iteration; i++){
        printf("%s %d-%d\n",p_name, getpid(),i);
        sleep(1);
    }
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
        cycle(50, CHILD_PROCESS);
        break;
    default:
        cycle(100, PARENT_PROCESS);
        break;
    }
    return 0;
}