#include <Windows.h>
#include <iostream>

int main()
{
    LPCWSTR process_path_1 = L"G:\\5_Sem\\ОС\\LW_3\\Debug\\OS03-02-01.exe";
    LPCWSTR process_path_2 = L"G:\\5_Sem\\ОС\\LW_3\\Debug\\OS03-02-02.exe";
    STARTUPINFO si1;
    STARTUPINFO si2;
    PROCESS_INFORMATION pi1;
    PROCESS_INFORMATION pi2;
    ZeroMemory(&si1, sizeof(STARTUPINFO)); si1.cb = sizeof(STARTUPINFO);
    ZeroMemory(&si2, sizeof(STARTUPINFO)); si2.cb = sizeof(STARTUPINFO);
    if (CreateProcess(process_path_1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1)) {
        std::cout << "Process OS03-02-01 created" << std::endl;
    }
    else {
        std::cout << "Process OS03-02-01 not created" << std::endl;
    }
    

    if (CreateProcess(process_path_2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2)) {
        std::cout << "Process OS03-02-02 created" << std::endl;
    }
    else {
        std::cout << "Process OS03-02-02 not created" << std::endl;
    }
    

    for (int i = 0; i < 100; i++) {
        std::cout << "PID " << GetCurrentProcessId() << std::endl;
        Sleep(1000);
    }
    std::cout << "End of loop" << std::endl;

    WaitForSingleObject(pi1.hProcess, INFINITE);
    WaitForSingleObject(pi2.hProcess, INFINITE);

    CloseHandle(pi1.hProcess);
    CloseHandle(pi2.hProcess);
    return 0;
}