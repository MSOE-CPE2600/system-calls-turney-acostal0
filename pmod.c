/****************************************************************
 * Filename: pmod.c
 * Assignment: Lab 9
 * Description:  Process Control System Calls: Altering a Process
 * Author: Lizbeth Acosta
 * Date: 11/12/24
 * Note: 
 * $ gcc -o pmod pmod.c
 * $ ./pmod
 * $ top
 * $ htop
 *****************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    // nice(int increment) adjusts the priority of the calling process
    // positive value reduces priority
    // negative value increases priority
    if (nice(10) == -1) {
        perror("nice failed");
        return 1;
    }
    printf("Priority decreased by 10\n");


    // nanosleep(*req, *rem) suspends the execution for the specified duration in nanoseconds
    // req is the desired sleep time, 1837272638 nanoseconds aka 1.837272638 seconds
    // rem is not required but stores the remaining time if it is suspended. 
    struct timespec req = {1, 837272638}; // 1 second and 837272638 nanoseconds
    if (nanosleep(&req, NULL) == -1) {
        perror("nanosleep failed");
        return 1;
    }

    printf("Goodbye\n");
    return 0;
    // Observing the behavior in htop after running the NI for the pmod command
    // changes to 10 compared to 0 from before it ran. And after the nanosleep call
    // the S changes to sleeping "S" .
}

