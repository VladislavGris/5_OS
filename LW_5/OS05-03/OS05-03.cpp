#include "../info.h"
#include <iostream>
#include <time.h>

/*
THREAD_PRIORITY_ABOVE_NORMAL 1
THREAD_PRIORITY_BELOW_NORMAL -1
THREAD_PRIORITY_HIGHEST 2
THREAD_PRIORITY_IDLE -15
THREAD_PRIORITY_LOWEST -2
THREAD_PRIORITY_NORMAL 0
THREAD_PRIORITY_TIME_CRITICAL 15
*/

/*
    AboveNormal 32768
    BelowNormal 16384
    High 128
    Idle 64
    Normal 32
    RealTime 256
*/

DWORD WINAPI TA() {
    HANDLE hProc = GetCurrentProcess();
    HANDLE hThread = GetCurrentThread();
    DWORD priorityClass;
    DWORD threadPriority;
    clock_t start, end;
    start = clock();
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
            Sleep(200);
        }
    }
    end = clock();
    std::cout << "++++++++++++++++++  Elapsed time: " << (end - start)/ CLK_TCK <<"  ++++++++++++++++++" << std::endl;
    return 0;
}

int main(int argc, char* argv[])
{
    std::cout << argc << std::endl;
	try {
		if (argc != 5) throw "Wrong number of parameters";
		DWORD mask = atoi(argv[1]);
		DWORD pClass1 = atoi(argv[2]);
		DWORD tPrio1 = atoi(argv[3]);
		DWORD tPrio2 = atoi(argv[4]);

		if (mask == 0 || pClass1 == 0) throw "Incorrect parameter values";

		std::cout << "Process affinity mask: " << argv[1] << std::endl;
		std::cout << "Process priority class: " << argv[2] << std::endl;
		std::cout << "First child thread priority: " << argv[3] << std::endl;
		std::cout << "Second child thread priority: " << argv[4] << std::endl;

		if (!SetProcessAffinityMask(GetCurrentProcess(), mask)) throw "SetProcessAffinityMask";

        DWORD threadId1, threadId2 = NULL;

        HANDLE hThread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TA, NULL, CREATE_SUSPENDED, &threadId1);
        std::cout << "First child thread created" << std::endl;
        HANDLE hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TA, NULL, CREATE_SUSPENDED, &threadId2);
        std::cout << "Second child thread created" << std::endl;

        SetThreadPriority(hThread1, tPrio1);
        SetThreadPriority(hThread2, tPrio2);
        std::cout << "hsdfjksj" << std::endl;
        ResumeThread(hThread1);
        ResumeThread(hThread2);

        WaitForSingleObject(hThread1, INFINITE);
        WaitForSingleObject(hThread2, INFINITE);

        CloseHandle(hThread1);
        CloseHandle(hThread2);
		
	}
	catch (const char* msg) {
		std::cout << "Error: " << msg << std::endl;
	}
    system("pause");
    return 0;
}
