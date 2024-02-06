#ifndef NPROC
#include "param.h"
#endif

struct pinfo
{
    char name[16];

    int pid;
    int ppid;

    int priority;
    int state;

    uint64 size;
};


struct pstat
{
    int processesNum;

    struct pinfo activeProcesses[NPROC];
};
