#include <stdio.h>

#define MAXLINE 10

int getLine(char line[], int maxline);

int main() {
    int currentLength;
    char line[MAXLINE];

    while((currentLength = getLine(line, MAXLINE)) > 0) {
        if(currentLength > 5) {
            printf("%s", line);
        }
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
