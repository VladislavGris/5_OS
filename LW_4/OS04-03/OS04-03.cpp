#include <iostream>
#include <Windows.h>

DWORD WINAPI OS04_03_T1() {

    for (int i = 0; i < 50; i++) {
        std::cout << "OS04-03-T1 "<< i << " PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        Sleep(1000);
    }

    return 0;
}

DWORD WINAPI OS04_03_T2() {

    for (int i = 0; i < 125; i++) {
        std::cout << "OS04-03-T2 " << i <<" PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        Sleep(1000);
    }

    return 0;
}

int main()
{
    DWORD thread1, thread2 = NULL;

    HANDLE hThread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_03_T1, NULL, 0, &thread1);
    HANDLE hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_03_T2, NULL, 0, &thread2);

    for (int i = 0; i < 100; i++) {
        std::cout << "OS04-03 " << i << " PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        if (i == 19) {
            SuspendThread(hThread1);
            std::cout << "OS04-03-T1 suspended" << std::endl;
        }
        if (i == 59) {
            ResumeThread(hThread1);
            std::cout << "OS04-03-T1 resumed" << std::endl;
        }
        if (i == 39) {
            SuspendThread(hThread2);
            std::cout << "OS04-03-T2 suspended" << std::endl;
        }
        Sleep(1000);
    }
    ResumeThread(hThread2);
    std::cout << "OS04-03-T2 resumed";

    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    CloseHandle(hThread1);
    CloseHandle(hThread2);

    return 0;
}