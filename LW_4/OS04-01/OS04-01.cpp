#include <Windows.h>
#include <iostream>

int main()
{
    for (int i = 0; i < 1000; i++) {
        std::cout << i << " PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        Sleep(1000);
    }
}