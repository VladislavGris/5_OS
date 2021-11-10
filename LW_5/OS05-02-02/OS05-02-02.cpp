#include <iostream>
#include "../info.h"

/*
	AboveNormal 32768
	BelowNormal 16384
	High 128
	Idle 64
	Normal 32
	RealTime 256
*/

int main(int argc, char* argv[])
{
	try {
		if (argc != 4) throw "Wrong number of parameters";
		DWORD mask = atoi(argv[1]);
		DWORD pClass1 = atoi(argv[2]);
		DWORD pClass2 = atoi(argv[3]);

		if (mask == 0 || pClass1 == 0 || pClass2 == 0) throw "Incorrect parameter values";

		std::cout << "Process affinity mask: " << argv[1] << std::endl;
		std::cout << "First child process priority class: " << argv[2] << std::endl;
		std::cout << "Second child process priority class: " << argv[3] << std::endl;

		if (!SetProcessAffinityMask(GetCurrentProcess(), mask)) throw "SetProcessAffinityMask";

		LPCWSTR path = L"G:\\5_Sem\\ОС\\LW_5\\Debug\\OS05-02x.exe";
		STARTUPINFO si1, si2;
		PROCESS_INFORMATION pi1, pi2;
		ZeroMemory(&si1, sizeof(STARTUPINFO)); si1.cb = sizeof(STARTUPINFO);
		ZeroMemory(&si2, sizeof(STARTUPINFO)); si2.cb = sizeof(STARTUPINFO);

		if (CreateProcess(path, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | pClass1, NULL, NULL, &si1, &pi1)) {
			std::cout << "First process OS05-02x created";
		}
		else throw "Process creation error";
		std::cout << "1" << std::endl;
		if (CreateProcess(path, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | pClass2, NULL, NULL, &si2, &pi2)) {
			std::cout << "Second process OS05-02x created";
		}
		else throw "Process creation error";

		WaitForSingleObject(pi1.hProcess, INFINITE);
		WaitForSingleObject(pi2.hProcess, INFINITE);
		CloseHandle(pi1.hProcess);
		CloseHandle(pi2.hProcess);
	}
	catch (const char* msg) {
		std::cout << "Error: " << msg << std::endl;
	}

	return 0;
}
