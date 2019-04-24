#include <stdio.h>

#define MAXLINE 1024
#define WIDTH 10

int getLine(char line[], int maxline);
void printFolded(char line[], int length);

int main() {
    int currentLength;
    char line[MAXLINE];

    while((currentLength = getLine(line, MAXLINE)) > 0) {
        printFolded(line, currentLength);
    }

    return 0;
}

int getLine(char line[], int maxline) {
    int c, i = 0, currentPos = 0;

    while((c = getchar()) != EOF && c != '\n') {
        if(i < maxline-1) {
            line[i] = c;
            currentPos = i+1;
        }
        i++;
    }    

    if(c == '\n') {
        if(currentPos == maxline - 1) {
            currentPos--;
        }
        line[currentPos] = c;
        currentPos++;
        i++;
    }

    line[currentPos] = '\0';

    return i;
}

void printFolded(char line[], int length) {
    if(length <= WIDTH) {
        printf("%s", line);
    } else {
        int start=0, i=0, lastSpace=-1, currentWidth=0, j;
        while(i <= length) {
            currentWidth++;
            if(line[i] == ' ' || line[i] == '\t') {
                lastSpace = i;
            }
            if(currentWidth == WIDTH || i == length) {
                if(lastSpace != -1) {
                    for(j=start; j<lastSpace; j++) {
                        putchar(line[j]);
                    }
                    putchar('\n');
                    i = lastSpace + 1;
                    start = i;
                    lastSpace = -1;
                } else {
                    for(j=start; j<i-1; j++) {
                        putchar(line[j]);
                    }
                    if(i < length) {
                        putchar('-');
                    }
                    putchar('\n');
                    start = i;
                }
                currentWidth = 0;
                if(i == length) {
                    i++;
                }
            } else {
                i++;
            }
        }
    }
}
