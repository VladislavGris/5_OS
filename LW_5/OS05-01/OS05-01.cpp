#include "../info.h"
#include <bitset>
#include <iostream>

int main()
{
    HANDLE hProc = GetCurrentProcess();
    HANDLE hThread = GetCurrentThread();
    DWORD processId = GetCurrentProcessId();
    DWORD threadId = GetCurrentThreadId();
    DWORD priorityClass = GetPriorityClass(hProc);
    DWORD threadPriority = GetThreadPriority(hThread);
    std::bitset<4> paBin(Info::GetProcessAffinMask(hProc));
    std::bitset<4> saBin(Info::GetSystemAffinMask(hProc));

    std::cout << "PID: " << processId << std::endl;
    std::cout << "TID: " << threadId << std::endl;
    std::cout << "Priority class: " << Info::GetPriorityClassName(priorityClass) << std::endl;
    std::cout << "Thread priority: " << Info::GetThreadPriorityName(threadPriority) << std::endl;
    std::cout << "Process affinity mask: " << paBin << std::endl;
    std::cout << "System affinity mask: " << saBin << std::endl;
    std::cout << "Number of processors: " << Info::GetProcessorsCount() << std::endl;
    std::cout << "Ideal processor: " << Info::GetThreadIdealProcessor(hThread) << std::endl;

    system("pause");
    return 0;
}
