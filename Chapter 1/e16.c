#include <stdio.h>

#define MAXLINE 10

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int currentLength, longestLength = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while((currentLength = getLine(line, MAXLINE)) > 0) {
        if(currentLength > longestLength) {
            longestLength = currentLength;
            copy(longest, line);
        }
    }

    if(longestLength > 0) {
        printf("Longest length: %d\n", longestLength);
        printf("Line: %s", longest);
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

void copy(char to[], char from[]) {
    int i = 0;
    while((to[i] = from[i]) != '\0') {
        i++;
    }
}
