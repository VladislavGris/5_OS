#include <iostream>
#include <Windows.h>

int main()
{
    HANDLE hm = CreateMutex(NULL, FALSE, L"Mutex");

    LPCWSTR an1 = L".\\OS_07_03a.exe";
    LPCWSTR an2 = L".\\OS_07_03b.exe";
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

    for (int i = 1; i <= 90; i++) {
        if (i == 30) {
            WaitForSingleObject(hm, INFINITE);
        }
        if (i == 60) {
            ReleaseMutex(hm);
        }

        std::cout << "OS_07_03 " << i << std::endl;
        Sleep(100);
    }

    WaitForSingleObject(pi1.hProcess, INFINITE);
    WaitForSingleObject(pi2.hProcess, INFINITE);
    CloseHandle(hm);
    CloseHandle(pi1.hProcess);
    CloseHandle(pi2.hProcess);

    system("pause");
    return 0;
}
