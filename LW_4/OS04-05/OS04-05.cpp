#include <iostream>
#include <Windows.h>

DWORD WINAPI OS04_05_T1() {

    for (int i = 0; i < 50; i++) {
        std::cout << "OS04-05-T1 " << i << " PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        Sleep(1000);
    }

    return 0;
}

DWORD WINAPI OS04_05_T2() {

    for (int i = 0; i < 125; i++) {
        std::cout << "OS04-05-T2 " << i << " PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        Sleep(1000);
    }

    return 0;
}


int main()
{
    DWORD thread1, thread2 = NULL;

    HANDLE hThread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_05_T1, NULL, 0, &thread1);
    HANDLE hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_05_T2, NULL, 0, &thread2);

    for (int i = 0; i < 100; i++) {
        if (i == 39) {
            TerminateThread(hThread2, -1);
            std::cout << "OS04-05-T2 terminated" << std::endl;
        }
        std::cout << "OS04-05 " << i << " PID-" << GetCurrentProcessId() << " TID-" << GetCurrentThreadId() << std::endl;
        Sleep(1000);
    }

    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    CloseHandle(hThread1);
    CloseHandle(hThread2);

    return 0;
}