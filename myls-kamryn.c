#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>  
#include <sys/stat.h>
typedef struct dirent Dir;
typedef struct stat DirInfo;
// reference: Wanwan Li's code in Lecture 19 Operating Systems


DirInfo getDirInfo (char* dir) {
    DirInfo dirInfo;
    stat(dir, &dirInfo);
    return dirInfo;
}

// prints out everything like in mystat.c
void results(char* fileName) {
    struct stat dirInfo;
    stat(fileName, &dirInfo);

    printf("--------------------------\n");
    printf("File Information of %s\n", (fileName));
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

int main (int argc, char *argv[]) {
    DIR* rootDir = opendir(".");
    Dir* dir = readdir(rootDir); 
    // When called without any arguments, the program should just print the file names.
    for (; dir != NULL; dir = readdir(rootDir)) {
        if (argc > 1) {
            // When invoked with the -l flag, the program should print out information about each file, such as the owner, group, permissions, and other information obtained from the stat() system call. 
            // If no directory is given, the program should just use the current working directory. 
            if (strcmp(argv[1], "-l") == 0) {
                results(dir->d_name);
            }
            // The program should take one additional argument, which is the directory to read, e.g., myls -l directory. 
            else if (argc > 2) {
                if (strcmp(argv[2], "-l") == 0) {
                    results(dir->d_name);
                }
            }
            else {
                printf("%s\n", dir->d_name);
            }
        }
        // When called without any arguments, the program should just print the file names.
        else {
            printf("%s\n", dir->d_name);
        }
    }
    closedir(rootDir); 
    return 0;
}