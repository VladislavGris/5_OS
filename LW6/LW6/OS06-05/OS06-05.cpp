#include <Windows.h>
#include <iostream>

void sh(HANDLE heap);

int main()
{
    HANDLE heap = GetProcessHeap();
    std::cout << "--------------- Before -----------------" << std::endl;
    sh(heap);
    int size = 300000;
    int* x = (int*)HeapAlloc(heap, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, size * sizeof(int));
    std::cout << "--------------------------------- " << std::hex << x << " ------------------------------" << std::endl;
    std::cout << "--------------- After -----------------" << std::endl;
    sh(heap);
    HeapFree(heap, HEAP_NO_SERIALIZE, x);
    system("pause");
}

void sh(HANDLE heap) {
    PROCESS_HEAP_ENTRY phe;
    phe.lpData = NULL;
    while (HeapWalk(heap, &phe)) {
        std::cout << "-- address = " << std::hex << phe.lpData
            << ", size = " << std::dec << phe.cbData
            << ((phe.wFlags & PROCESS_HEAP_REGION) ? " R" : "") // начало непрерывной области
            << ((phe.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE) ? " U" : "") // нераспределенная область
            << ((phe.wFlags & PROCESS_HEAP_ENTRY_BUSY) ? " B" : "") // распределенная область
            << "\n";
    }
}
