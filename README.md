# Lab 9 System Calls

## Overview
The purpose of this assignment is to familiarize with commonly used 
system calls on a Portable Operating System Interface (POSIX) operating system. 
There are hundreds of system calls within the POSIX standard. This lab will include:

- Information Maintenance - Used to modify and retrieve information about the 
system as a whole. (info.c)
- Process Control - Used to create, destroy, and manipulate tasks/processes on the 
system. (pinfo.c and pmod.c)
- File Management - Used to create, delete, and modify files in the file system. (finfo.c)

## info.c
include:
• clock_gettime
• uname
• gethostname
• get_nprocs
• sysconf
• getpagesize

prints:
• The current time of day - in nanoseconds
• The system’s network name
• The operating system name
• The operating system release and version
• The system’s hardware type
• The number of CPUs on the system
• The total amount of physical memory IN BYTES
• The total amount of free memory IN BYTES

## pinfo.c
include:
• getpid
• getpriority
• sched_getscheduler
• getcpu
• getrusage
• getrlimit

Take a single command line 
parameter that is a process identifier - For that process identifier, print out - The process 
priority - The scheduling method - as a string of text NOT a number - If the process identifier 
does not exist, print an error message and exit - If the user does NOT specify a process 
identifier, print the information for the CURRENT executing process.

## pmod.c
include:
• nice
• nanosleep

• Modifies its own priority to REDUCE it by 10 - NOTE Make sure you specify the 
correct number to REDUCE the priority not increase.
• Sleeps for 1,837,272,638 nano seconds
• Prints a goodbye message and exits

## finfo.c
Displays the file information about a given file 
provided via the command line. The file name MUST be specified via the command line. 
Specifically, - The type of file - print this in a user readable way - The permissions set on the 
file - print these in a user readable way - The owner of the file - printing the user identifier 
(number) is enough - The size of the file IN BYTES - The date and time of last modification 
(format this for easy viewing, do NOT print out raw bytes or a large integer). - If at any point, 
there is an error print an error and exit.


## How to compile and run each program
### For info.c:
$ gcc -o info info.c
$ ./info

### For pinfo.c:
$ gcc -o pinfo pinfo.c
$ ./pinfo <process_id> # can find the ID of a process with top

### For pmod.c:
$ gcc -o pmod pmod.c
$ ./pmod

### For finfo.c:
$ gcc -o finfo finfo.c
$ ./finfo <filename> # replace <filename> with a real filename