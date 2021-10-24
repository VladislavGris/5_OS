#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#define PROCESS_NAME "OS03-06"

int main()
{
    system("./OS03-05-01");
    for(int i = 1; i <= 100; i++){
        printf("%s %d-%d\n",PROCESS_NAME, getpid(),i);
        sleep(1);
    }
    exit(0);
}