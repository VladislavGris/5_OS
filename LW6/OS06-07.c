#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#define MB_SIZE (1024*1024)
#define ALLOC_SIZE (256*MB_SIZE)

int main()
{
    int size = 1024*1024*256;
    printf("%d %d\n",size, ALLOC_SIZE);
    int* array = (int*)malloc(ALLOC_SIZE);
    int iterationCount = ALLOC_SIZE/sizeof(int);
    for(int i = 0; i < iterationCount; i++){
        array[i]=i;
    }
    printf("PID:%d\n",getpid());
    printf("%p\n", array);
    sleep(1000);
    return 0;
}