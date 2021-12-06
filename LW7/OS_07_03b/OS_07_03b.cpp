#include <iostream>
#include <Windows.h>

int main()
{
    HANDLE hm = OpenMutex(SYNCHRONIZE, FALSE, L"Mutex");
    for (int i = 1; i <= 90; i++) {
        if (i == 30) WaitForSingleObject(hm, INFINITE);
        if (i == 60) ReleaseMutex(hm);
        std::cout << "OS_07_03b " << i << std::endl;
        Sleep(100);
    }
    CloseHandle(hm);
    system("pause");
}
