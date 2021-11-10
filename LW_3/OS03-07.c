#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#define PROCESS_NAME "OS03-07"

int main(int argc, char *argv[]) {
	char* const args[] = {"OS03-05-01",NULL};
    
	
    
	for(int i = 1; i <= 10; i++){
        printf("%s %d-%d\n",PROCESS_NAME, getpid(),i);
        sleep(1);
    }
    printf("Before process start %d\n", getpid());
    sleep(1);
    execv("./OS03-05-01", args);
    printf("After process start");
	return 0;
}