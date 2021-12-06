#include <iostream>
#include <Windows.h>

int main()
{
    HANDLE he = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"Event");
    WaitForSingleObject(he, INFINITE);
    for (int i = 1; i <= 90; i++) {
        if (i == 30) {

        }
        if (i == 60) {

        }

        std::cout << "OS_07_05a " << i << std::endl;
        Sleep(100);
    }
    CloseHandle(he);
	system("pause");
}
