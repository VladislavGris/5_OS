#include <iostream>
#include <Windows.h>

CRITICAL_SECTION cs;

DWORD WINAPI A() {
    for (int i = 1; i <= 90; i++) {
        if (i == 30)  EnterCriticalSection(&cs);
        if (i == 60) LeaveCriticalSection(&cs);
        std::cout << "Thread A " << i << std::endl;
        Sleep(100);
    }
    return 0;
}

DWORD WINAPI B() {
    for (int i = 1; i <= 90; i++) {
        if (i == 30)  EnterCriticalSection(&cs);
        if (i == 60) LeaveCriticalSection(&cs);
        std::cout << "Thread B " << i << std::endl;
        Sleep(100);
    }
    return 0;
}

int main()
{
    DWORD AId = NULL, BId = NULL;
    HANDLE AH = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)A, NULL, 0, &AId);
    HANDLE BH = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)B, NULL, 0, &BId);

    InitializeCriticalSection(&cs);

    for (int i = 1; i <= 90; i++) {
        if (i == 30)  EnterCriticalSection(&cs);
        if (i == 60) LeaveCriticalSection(&cs);
        std::cout << "main " << i << std::endl;
        Sleep(100);
    }

    WaitForSingleObject(AH, INFINITE);
    WaitForSingleObject(BH, INFINITE);

    DeleteCriticalSection(&cs);
    system("pause");
    return 0;
}
