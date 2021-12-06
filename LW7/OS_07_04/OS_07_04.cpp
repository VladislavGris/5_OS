#include <iostream>
#include <Windows.h>

int main()
{
    HANDLE hs = CreateSemaphore(NULL, 2, 3, L"Semaphore");

    LPCWSTR an1 = L".\\OS_07_04a.exe";
    LPCWSTR an2 = L".\\OS_07_04b.exe";
    STARTUPINFO si1; STARTUPINFO si2;
    PROCESS_INFORMATION pi1; PROCESS_INFORMATION pi2;

    ZeroMemory(&si1, sizeof(STARTUPINFO)); ZeroMemory(&si2, sizeof(STARTUPINFO));
    si1.cb = sizeof(STARTUPINFO); si2.cb = sizeof(STARTUPINFO);

    if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1)) {
        std::cout << "Process 1 created" << std::endl;
    }
    else {
        std::cout << "Process 1 not created" << std::endl;
    }
    if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2)) {
        std::cout << "Process 2 created" << std::endl;
    }
    else {
        std::cout << "Process 2 not created" << std::endl;
    }
    LONG prevcount = 0;
    for (int i = 1; i <= 90; i++) {
        if (i == 30) {
            WaitForSingleObject(hs, INFINITE);
        }
        if (i == 60) {
            ReleaseSemaphore(hs, 1, &prevcount);
            std::cout << "OS_07_04 prevcount: " << prevcount << std::endl;
        }

        std::cout << "OS_07_04 " << i << std::endl;
        Sleep(100);
    }

    WaitForSingleObject(pi1.hProcess, INFINITE);
    WaitForSingleObject(pi2.hProcess, INFINITE);
    CloseHandle(hs);
    CloseHandle(pi1.hProcess);
    CloseHandle(pi2.hProcess);
    system("pause");
    return 0;
}
