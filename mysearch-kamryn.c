#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>  
#include <unistd.h>
#include <sys/stat.h>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

// reference: Wanwan Li's code in Lecture 19 Operating Systems

void result(char *pathName);

int main (int argc, char *argv[]) {
    DIR *dirInfo;
    char *pathName;

    if (argc > 1) {
        pathName = argv[1];
    }  
    else {
        pathName = ".";
    }

    dirInfo = opendir(pathName);
    
    char c[FILENAME_MAX];
    GetCurrentDir(c, FILENAME_MAX);
    printf("Current Path %s\n", c);

    if (argc > 2) {
        printf("Error");
        exit(EXIT_FAILURE);
    }

    if (argc == 2) {
        pathName = argv[1];
    }
    result(pathName);
    printf("Search has finished!\n");
}

void result(char *pathName) {
    struct stat dir;
    DIR *dPath;
    dPath = opendir(pathName);
    //////////////////////////
    struct dirent *dirInfo;
    dirInfo = readdir(dPath);
    
    while (dirInfo != NULL) {
        if (strcmp(dirInfo->d_name, ".") != 0 && strcmp(dirInfo->d_name, "..") != 0) { 
            printf("%s\n", dirInfo->d_name);
            stat(dirInfo->d_name, &dir);
            if (S_ISDIR(dir.st_mode)) {
                char str[1024];
                strcpy(str, pathName);
                strcat(str, "/");
                strcat(str, dirInfo->d_name);
                result(str);
            }
        }
        dirInfo = readdir(dPath); 
    }
    closedir(dPath);
    printf("%s\n", pathName);
}