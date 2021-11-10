#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <iomanip>

int main()
{
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);
    std::wcout << std::left << std::setw(40) << L"Name" << std::setw(6) << L"PID: " << std::setw(15) << L"Parent PID: " << std::endl;
    try {
        if (!Process32First(snap, &pe)) {
            throw L"Process32First";
        }
        do {
            std::wcout << std::left << std::setw(40) << pe.szExeFile << std::setw(6) << pe.th32ProcessID << std::setw(15) << pe.th32ParentProcessID << std::endl;
        } while (Process32Next(snap, &pe));
    }
    catch (char* msg) {
        std::wcout << L"ERROR: " << msg << std::endl;
    }
    system("pause");
}