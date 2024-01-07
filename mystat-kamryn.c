#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 
// reference: Wanwan Li's code in Lecture 19 Operating Systems
// reference: OPERATING SYSTEMS THREE EASY PIECES REMZI H. ARPACI-DUSSEAU 39.8 code

int main(int argc, char *argv[]) {
    struct stat dirInfo;
    if (stat(argv[1], &dirInfo) < 0) {
        return 1;
    }
    printf("File Information of %s\n", argv[1]);
    printf("File Size: %ld Bytes\n", dirInfo.st_size);
    printf("Number of Blocks Allocated: %ld\n", dirInfo.st_blocks);
    printf("Number of Links: %ld\n", dirInfo.st_nlink);
    printf("File Permissions: ");
    printf( (S_ISDIR(dirInfo.st_mode)) ? "d" : "-");
    printf( (dirInfo.st_mode & S_IRUSR) ? "r" : "-");
    printf( (dirInfo.st_mode & S_IWUSR) ? "w" : "-");
    printf( (dirInfo.st_mode & S_IXUSR) ? "x" : "-");
    printf( (dirInfo.st_mode & S_IRGRP) ? "r" : "-");
    printf( (dirInfo.st_mode & S_IWGRP) ? "w" : "-");
    printf( (dirInfo.st_mode & S_IXGRP) ? "x" : "-");
    printf( (dirInfo.st_mode & S_IROTH) ? "r" : "-");
    printf( (dirInfo.st_mode & S_IWOTH) ? "w" : "-");
    printf( (dirInfo.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    printf("File inode: %ld\n", dirInfo.st_ino);
}