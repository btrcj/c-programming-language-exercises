#include <stdio.h>

#define MAXLINE 10

int getLine(char line[], int maxline);
void reverseLine(char line[], char reversed[]);

int main() {
    int currentLength;
    char line[MAXLINE];
    char reversed[MAXLINE];

    while((currentLength = getLine(line, MAXLINE)) > 0) {
        reverseLine(line, reversed);
        printf("%s", reversed);
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

void reverseLine(char line[], char reversed[]) {
    int i = 0, hasNewline = 0;
    while(line[i] != '\0' && line[i] != '\n') {
        i++;
    }
    if(line[i] == '\n') {
        hasNewline = 1;
    }
    i--;

    int j = 0;
    while(i >= 0) {
        reversed[j] = line[i];
        j++;
        i--;
    }

    if(hasNewline == 1) {
        reversed[j] = '\n';
        j++;
    }
    reversed[j] = '\0';
}
