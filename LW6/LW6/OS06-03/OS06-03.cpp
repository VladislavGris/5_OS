#include <Windows.h>
#include <iostream>
#define PAGE_COUNT 256
#define PAGE_SIZE 4096 // hex 0x00001000
/*
    Г - C3 = 195
    р - F0
    и - E8
    2 147 
    page offset: 798 720 = 195*4096 = hex 0x000C3000 => value: 0x00030c00 = 199680
    in page offset: 0x00000f0e = 3 854  (3 852 + 2)  0x00000F0C  
    result value: 200 643   offset to result: 0x000C3F0C
    to end offset: 1 048 576 = 4096*256 = hex 0x00100000 => value: 0x0003ffff = 262143
    array max value: 262 144-1 (256*4096/4)
*/
int main()
{
    LPVOID xmemaddr = VirtualAlloc(NULL, PAGE_COUNT * PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE);
    std::cout << "Memory: " << std::hex << xmemaddr << std::dec << std::endl;
    int* array = (int*)xmemaddr;
    int iterationCount = (PAGE_COUNT * PAGE_SIZE) / sizeof(int);
    for (int i = 0; i < iterationCount; i++) {
        array[i] = i;
    }
    system("pause");
    VirtualFree(xmemaddr, NULL, MEM_RELEASE);
    system("pause");
}
