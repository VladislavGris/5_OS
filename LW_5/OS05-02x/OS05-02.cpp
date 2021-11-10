#include <iostream>
#include "../info.h"

int main()
{
    HANDLE hProc = GetCurrentProcess();
    HANDLE hThread = GetCurrentThread();
    DWORD priorityClass;
    DWORD threadPriority;

    for (int i = 1; i <= 1000000; i++) {
        if (i % 1000 == 0) {
            priorityClass = GetPriorityClass(hProc);
            threadPriority = GetThreadPriority(hThread);

            std::cout << "i: " << i << std::endl;
            std::cout << "PID: " << GetCurrentProcessId() << std::endl;
            std::cout << "TID: " << GetCurrentThreadId() << std::endl;
            std::cout << "Priority class: " << Info::GetPriorityClassName(priorityClass) << std::endl;
            std::cout << "Thread priority: " << Info::GetThreadPriorityName(threadPriority) << std::endl;
            std::cout << "Process affinity mask: " << Info::GetProcessAffinMask(hProc) << std::endl;
            std::cout << "System affinity mask: " << Info::GetSystemAffinMask(hProc) << std::endl;
            std::cout << "Ideal processor: " << Info::GetThreadIdealProcessor(hThread) << std::endl;
            std::cout << "---------------------------------------------------------------" << std::endl;
            Sleep(200);
        }
    }

    system("pause");
    return 0;
}
