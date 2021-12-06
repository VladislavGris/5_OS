#include <iostream>
#include <Windows.h>

int main()
{
    HANDLE hs = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, L"Semaphore");
    LONG prevcount = 0;
    for (int i = 1; i <= 90; i++) {
        if (i == 30) {
            WaitForSingleObject(hs, INFINITE);
        }
        if (i == 60) {
            ReleaseSemaphore(hs, 1, &prevcount);
            std::cout << "OS_07_04a prevcount: " << prevcount << std::endl;
        }

        std::cout << "OS_07_04a " << i << std::endl;
        Sleep(100);
    }
    CloseHandle(hs);
    system("pause");
}
