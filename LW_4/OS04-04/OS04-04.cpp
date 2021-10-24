#include <iostream>
#include <Windows.h>

DWORD WINAPI OS04_04_T1() {

    for (int i = 0; i < 50; i++) {
        if (i == 24) {
            std::cout << "OS04_04_T1 sleep" << std::endl;
            Sleep(10000);
        }
        std::cout << "OS04-04-T1 " << i << " PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        Sleep(1000);
    }

    return 0;
}

DWORD WINAPI OS04_04_T2() {

    for (int i = 0; i < 125; i++) {
        if (i == 79) {
            std::cout << "OS04_04_T2 sleep" << std::endl;
            Sleep(15000);
        }
        std::cout << "OS04-04-T2 " << i << " PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        Sleep(1000);
    }

    return 0;
}

int main()
{
    DWORD thread1, thread2 = NULL;

    HANDLE hThread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_04_T1, NULL, 0, &thread1);
    HANDLE hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_04_T2, NULL, 0, &thread2);

    for (int i = 0; i < 100; i++) {
        if (i == 29) {
            std::cout << "main sleep" << std::endl;
            Sleep(10000);
        }
        std::cout << "OS04-04 "<< i <<" PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        Sleep(1000);
    }

    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    CloseHandle(hThread1);
    CloseHandle(hThread2);

    return 0;
}