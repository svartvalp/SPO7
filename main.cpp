#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    SYSTEM_INFO SysInfo;

    // System info
    GetSystemInfo(&SysInfo);

    cout << "Page size: " << SysInfo.dwPageSize << endl;
    cout << "Min app address " << SysInfo.lpMinimumApplicationAddress << endl;
    cout << "Max app address " << SysInfo.lpMaximumApplicationAddress << endl;
    cout << "Active processor mask " << SysInfo.dwActiveProcessorMask << endl;
    cout << "Number of processors " << SysInfo.dwNumberOfProcessors << endl;
    cout << "Processor type  " << SysInfo.dwProcessorType << endl;
    cout << "Granularity " << SysInfo.dwAllocationGranularity << endl;
    cout << "Processor level " << SysInfo.wProcessorLevel << endl;
    cout << "Processor revision " << SysInfo.wProcessorRevision << endl;

    cout << endl;



    // Memory info
    MEMORYSTATUS MemStat;
    MemStat.dwLength = { sizeof(MemStat) };
    GlobalMemoryStatus(&MemStat);

    cout << "Page size " << MemStat.dwLength << endl;
    cout << "Memory load " << MemStat.dwMemoryLoad << endl;
    cout << "Total Physic mem " << MemStat.dwTotalPhys << endl;
    cout << "Available physical mem " << MemStat.dwAvailPhys << endl;
    cout << "Total swap file size " << MemStat.dwTotalPageFile << endl;
    cout << "Available swap file size " << MemStat.dwAvailPageFile << endl;
    cout << "Total virtual mem " << MemStat.dwTotalVirtual << endl;
    cout << "Available virtual mem " << MemStat.dwAvailVirtual << endl;

    cout << endl;



    // Heap info
    HANDLE SysHeap = GetProcessHeap();

    UINT MAX_ALLOCATIONS = 32;
    UINT NumOfAllocations;

    for (NumOfAllocations = 0; NumOfAllocations < MAX_ALLOCATIONS; NumOfAllocations++)
        if (HeapAlloc(SysHeap, 0, 1024) == NULL) break;

    if (NumOfAllocations == 0)
        cout << "Heap memory wasn't allocated" << endl;
    else
        printf("Heap memory was allocated %d times", NumOfAllocations);

    cout << endl;



    //RAM info
    SIZE_T MEMSIZE = 4096;
    LPVOID Mem = VirtualAlloc(NULL, MEMSIZE, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

    if (Mem != NULL) {
        if (VirtualLock(Mem, MEMSIZE))
            cout << "Virtual lock" << endl;
        else
            cout << "" << endl;
            printf("Virtual lock fail");


        if (VirtualUnlock(Mem, MEMSIZE))
            cout << "Unlock virtual" << endl;
        else
            cout << "Unlock virtual fail" << endl;

        if (VirtualFree(Mem, 0, MEM_RELEASE))
            cout << "Free virtual" << endl;
        else
            cout << "Can't free virtual" << endl;
    }


    else cout << "Virtual mem don't allocated" << endl;
    cout << endl;
}