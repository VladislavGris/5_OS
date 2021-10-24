#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#define PROCESS_NAME "OS03-05-01"

int main()
{
    for(int i = 1; i <= 50; i++){
        printf("%s %d-%d\n",PROCESS_NAME, getpid(),i);
        sleep(1);
    }
    return 0;
}