#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/pstat.h"

void printProcessesCount(int n){
    switch(n) {
    case 0:
        printf("There are no active processes.\n");
        break;
    case 1:
        printf("There is 1 active process.\n");
        break;
    default:
        printf("There are %d active processes:\n", n);
        break;
    }
}

void printActiveProcesses(struct pstat* stats) {
    for(struct pinfo* p = stats->activeProcesses; p < stats->activeProcesses + stats->processesNum; p++){
        printf(
            "Process: %s, pid: %d, ppid: %d, priority: %d, state: %d, size: %l\n", 
            p->name, 
            p->pid, 
            p->ppid, 
            p->priority, 
            p->state, 
            p->size
        );
    }
}

int main(void) {
    struct pstat stats;
    getpinfo(&stats);

    printProcessesCount(stats.processesNum);
    printActiveProcesses(&stats);

    exit(0);
}