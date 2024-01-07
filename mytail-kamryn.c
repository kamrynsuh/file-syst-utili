#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// reference: https://www.geeksforgeeks.org/implement-your-own-tail-read-last-n-lines-of-a-huge-file/

void process (FILE *fileName, long count);
void result (FILE *fileName, off_t pos);

int main (int argc, char *argv[]) {
    printf("These are the last %s lines of %s: ", argv[1], argv[2]);

    FILE *fp;
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    process(fp, atol(argv[1]));
    return 0;
}

void result (FILE *fileName, off_t pos) {
    int fileRead;
    int file = fileno(fileName);
    char str[100];

    lseek(file, (pos), SEEK_SET);
    while ((fileRead = read(file, str, 100)) > 0) {
        printf("%s", str);
    }
}

void process (FILE *fileName, long count) {
    long num = 0;
    fseek(fileName, 0, SEEK_END);
    off_t pos;
    off_t begin = pos;
    off_t last = pos;
    pos = ftell(fileName);

    for (begin; begin >= 0; begin--) {
        if ((last - begin) > 1 && fgetc(fileName) == '\n') {
            num++;
            if (num == count) {
                break;
            }
        }
        pos--;
        fseek(fileName, pos, SEEK_SET);
    }

    result(fileName, pos);
    fclose(fileName);
}