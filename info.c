/***************************************************
 * Filename: info.c
 * Assignment: Lab 9
 * Description: Information Maintenance System Calls
 * Author: Lizbeth Acosta
 * Date: 11/12/24
 * Note: 
 * $ gcc -o info info.c
 * $ ./info
 ***************************************************/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>

int main() {
    // get time
    // The clock_gettime function is used in POSIX systems to retrieve the current 
    // time from a specified clock. It provides high-resolution time measurement, making 
    // it useful for performance profiling, timing operations, and working with various system clocks.
    struct timespec tp;

    if (clock_gettime(CLOCK_REALTIME, &tp) == 0) {
        printf("Current time of day: %ld seconds or %ld nanoseconds\n", tp.tv_sec, tp.tv_nsec);
    } else {
        perror("clock_gettime failed");
    }

    // uname
    // The uname system call is used to retrieve information about the 
    // operating system and the machine it’s running on.
    struct utsname unameData;
    if (uname(&unameData) == 0) {
        printf("System network name: %s\n", unameData.nodename);
        printf("Operating system: %s\n", unameData.sysname);
        printf("OS release: %s\n", unameData.release);
        printf("OS version: %s\n", unameData.version);
        printf("Hardware type: %s\n", unameData.machine);
    } else {
        perror("uname failed");
    }

    // hostname
    // The gethostname function is used to retrieve the hostname 
    // of the current machine, which is the name that identifies the system on a network.
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Hostname: %s\n", hostname);
    } else {
        perror("gethostname failed");
    }

    // number of CPUs
    // get_nprocs provides the number of processing units (logical CPUs) that the system has 
    // available for parallel tasks or multi-threaded operations
    int nprocs = get_nprocs();
    printf("Number of CPUs: %d\n", nprocs);

    // Get memory information
    // The sysconf function is used in POSIX systems to retrieve various system configuration 
    // parameters at runtime. These parameters can provide information about system limits, resources, 
    // or capabilities, such as the number of processors, memory limits, or the maximum length of a file name.
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("Total physical memory: %lu bytes\n", info.totalram);
        printf("Free memory: %lu bytes\n", info.freeram);
    } else {
        perror("sysinfo failed");
    }

    return 0;
}