/*********************************************
 * Filename: finfo.c
 * Assignment: Lab 9
 * Description: File Management System Calls
 * Author: Lizbeth Acosta
 * Date: 11/12/24
 * Note: 
 * $ gcc -o finfo finfo.c
 * $ ./finfo random.txt
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // checks if there are 2 arguments
    if (argc < 2) {
        fprintf(stderr, "Need 2 arguments, add filename after %s\n", argv[0]);
        return 1;
    }
    // stores filename
    const char *filename = argv[1];
    
    // holds file info
    struct stat fileInfo;
    
    // uses stat system call to get file details
    // stat works best because symbolic links
    // points to actual files and since we want to know
    // about the file it self and not the link
    if (stat(filename, &fileInfo) == -1) {
        perror("stat failed");
        return 1;
    }

    // Determines file type and prints string in human readable way
    printf("File type: ");
    if (S_ISREG(fileInfo.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(fileInfo.st_mode)) {
        printf("Directory\n");
    } else if (S_ISCHR(fileInfo.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(fileInfo.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(fileInfo.st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISLNK(fileInfo.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(fileInfo.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown\n");
    }


    // prints file permissions
    printf("Permissions: ");

    if (fileInfo.st_mode & S_IRUSR) {
        printf("r"); // user read
    } else {
        printf("-");
    }

    if (fileInfo.st_mode & S_IWUSR) {
        printf("w"); // user write
    } else {
        printf("-");
    }

    if (fileInfo.st_mode & S_IXUSR) {
        printf("x"); // user execute
    } else {
        printf("-");
    }

    if (fileInfo.st_mode & S_IRGRP) {
        printf("r"); // group read
    } else {
        printf("-");
    }

    if (fileInfo.st_mode & S_IWGRP) {
        printf("w"); // group write
    } else {
        printf("-");
    }

    if (fileInfo.st_mode & S_IXGRP) {
        printf("x"); // group execute
    } else {
        printf("-");
    }

    if (fileInfo.st_mode & S_IROTH) {
        printf("r"); // others read
    } else {
        printf("-");
    }

    if (fileInfo.st_mode & S_IWOTH) {
        printf("w"); // others write
    } else {
        printf("-");
    }

    if (fileInfo.st_mode & S_IXOTH) {
        printf("x"); // others execute
    } else {
        printf("-");
    }
    printf("\n");

    // prints owner of the file aka user id
    printf("Owner UID: %d\n", fileInfo.st_uid);

    // size of file in bytes
    printf("File size: %ld bytes\n", fileInfo.st_size);

    // date and time of last modification 
    char timebuf[80]; // buffer to hold time format string
    struct tm *tm = localtime(&fileInfo.st_mtime); // to local time
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm); // formats year-month-day
    printf("Last modified: %s\n", timebuf);

    return 0;
}