#include <iostream>
#include <Windows.h>

int check = 0;
int value = 1;

void SyncStart() {
    _asm {
        Sync:
            lock bts check, 0;
            jc Sync;
    }
}

void SyncEnd() {
    _asm {
        lock btr check, 0;
    }
}

DWORD WINAPI Thread_1() {
    SyncStart();
    for (int i = 0; i < 10; i++) {
        std::cout << "Thread_1 " << i << std::endl;
        Sleep(500);
    }
    SyncEnd();
    return 0;
}

DWORD WINAPI Thread_2() {
    SyncStart();
    for (int i = 0; i < 10; i++) {
        std::cout << "Thread_2 " << i << std::endl;
        Sleep(500);
    }
    SyncEnd();
    return 0;
}

int main()
{
    DWORD T1Id = NULL, T2Id = NULL;
    HANDLE T1H = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread_1, NULL, 0, &T1Id);
    HANDLE T2H = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread_2, NULL, 0, &T1Id);
    WaitForSingleObject(T1H, INFINITE);
    WaitForSingleObject(T2H, INFINITE);
    system("pause");
    return 0;
}
