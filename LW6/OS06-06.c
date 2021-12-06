#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t pid = getpid();
    for(int i = 1; i <= 1000; i++){
        printf("%d-%d\n",pid,i);
        sleep(1);
    }
    return 0;
}