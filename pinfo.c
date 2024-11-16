/*********************************************
 * Filename: pinfo.c
 * Assignment: Lab 9
 * Description:  Process Control System Calls: 
 * Retrieving Process Information
 * Author: Lizbeth Acosta
 * Date: 11/12/24
 * Note: 
 * $ gcc -o pinfo pinfo.c
 * $ ./pinfo
 * $ ./pinfo 1
 * $ ./pinfo 38
 *********************************************/
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // get pid retreives the process ID of the calling process
    pid_t pid;
    if (argc > 1) {
        pid = atoi(argv[1]);
    } else {
        pid = getpid();
    }
    printf("Process ID: %d\n", pid);

    // getpriority retreives the priority if a process,
    // process group, or user. PRIO_PROCESS gets the 
    // priority for a process
    int priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1 && errno != 0) {
        perror("getpriority failed");
        return 1;
    }
    printf("Process priority: %d\n", priority);

    // sched_getscheduler retrieves the scheduling polocy for the 
    // specified process ID.
    // SCHED_OTHER: Default policy.
    // SCHED_FIFO: First-in, first-out real-time policy.
    // SCHED_RR: Round-robin real-time policy.
    // SCHED_BATCH: Optimized for batch jobs. 
    // SCHED_IDLE: Used for low-priority tasks.
    // SCHED_DEADLINE: Deadline-driven tasks
    int policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        return 1;
    }

    switch (policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_BATCH:
            printf("SCHED_BATCH\n");
            break;
        case SCHED_IDLE:
            printf("SCHED_IDLE\n");
            break;
        default:
            printf("Unknown scheduling method\n");
    }

    return 0;
}
