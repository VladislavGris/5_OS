﻿#include <iostream>
#include <Windows.h>
int main()
{
    for (int i = 0; i < 1000; i++) {
        std::cout << "Iteration " << i << std::endl;
        Sleep(1000);
    }
    return 0;
}
