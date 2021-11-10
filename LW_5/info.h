#pragma once
#include <Windows.h>

namespace Info {
    const char* GetPriorityClassName(DWORD pClass);
    const char* GetThreadPriorityName(DWORD tPrio);
    DWORD GetProcessAffinMask(HANDLE pHandle);
    DWORD GetSystemAffinMask(HANDLE pHandle);
    DWORD GetThreadIdealProcessor(HANDLE tHandle);
    DWORD GetProcessorsCount();
}