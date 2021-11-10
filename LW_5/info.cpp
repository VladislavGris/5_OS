#include "info.h"
#include <iostream>
namespace Info {

    const char* GetPriorityClassName(DWORD pClass) {
        switch (pClass)
        {
        case IDLE_PRIORITY_CLASS:
            return "IDLE_PRIORITY_CLASS";
        case BELOW_NORMAL_PRIORITY_CLASS:
            return "BELOW_NORMAL_PRIORITY_CLASS";
        case NORMAL_PRIORITY_CLASS:
            return "NORMAL_PRIORITY_CLASS";
        case ABOVE_NORMAL_PRIORITY_CLASS:
            return "ABOVE_NORMAL_PRIORITY_CLASS";
        case HIGH_PRIORITY_CLASS:
            return "HIGH_PRIORITY_CLASS";
        case REALTIME_PRIORITY_CLASS:
            return "REALTIME_PRIORITY_CLASS";
        default:
            return "UNDEFINED_PRIORITY_CLASS";
        }
    }

    const char* GetThreadPriorityName(DWORD tPrio) {
        switch (tPrio)
        {
        case THREAD_PRIORITY_LOWEST:
            return "THREAD_PRIORITY_LOWEST";
        case THREAD_PRIORITY_BELOW_NORMAL:
            return "THREAD_PRIORITY_BELOW_NORMAL";
        case THREAD_PRIORITY_NORMAL:
            return "THREAD_PRIORITY_NORMAL";
        case THREAD_PRIORITY_ABOVE_NORMAL:
            return "THREAD_PRIORITY_ABOVE_NORMAL";
        case THREAD_PRIORITY_HIGHEST:
            return "THREAD_PRIORITY_HIGHEST";
        case THREAD_PRIORITY_IDLE:
            return "THREAD_PRIORITY_IDLE";
        case THREAD_PRIORITY_TIME_CRITICAL:
            return "THREAD_PRIORITY_TIME_CRITICAL";
        default:
            return "THREAD_PRIORITY_UNDEFINED";
        }
    }

    DWORD GetProcessAffinMask(HANDLE pHandle) {
        DWORD pa = NULL, sa = NULL;
        try {
            if (!GetProcessAffinityMask(pHandle, &pa, &sa)) throw "GetProcessAffinMask";
        }
        catch (char* msg) {
            std::cout << "Error: " << msg << std::endl;
        }
        return pa;
    }

    DWORD GetSystemAffinMask(HANDLE pHandle) {
        DWORD pa = NULL, sa = NULL;
        try {
            if (!GetProcessAffinityMask(pHandle, &pa, &sa)) throw "GetSystemAffinMask";
        }
        catch (char* msg) {
            std::cout << "Error: " << msg << std::endl;
        }
        return sa;
    }

    DWORD GetThreadIdealProcessor(HANDLE tHandle) {
        DWORD icpu = -1;
        icpu = SetThreadIdealProcessor(tHandle, MAXIMUM_PROCESSORS);
        return icpu;
    }

    DWORD GetProcessorsCount() {
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);
        return sysInfo.dwNumberOfProcessors;
    }
}