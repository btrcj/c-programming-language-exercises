#include <stdio.h>

#define MAXLINE 10

int getLine(char line[], int maxline);

int main() {
    int currentLength;
    char line[MAXLINE];

    while((currentLength = getTrimmedLine(line, MAXLINE)) > 0) {
        if(line[0] != '\n') {
            printf("%s", line);
        }
    }

    return 0;
}

int getTrimmedLine(char line[], int maxline) {
    int c, i = 0, currentPos = 0;

    while((c = getchar()) != EOF && c != '\n') {
        if(i < maxline-1) {
            line[i] = c;
            currentPos = i+1;
        }
        i++;
    }

    int j = currentPos - 1;
    while(j >= 0 && (line[j] == ' ' || line[j] == '\t')) {
        j--;
    }
    j++;    

    if(c == '\n') {
        if(j == maxline - 1) {
            j--;
        }
        line[j] = c;
        j++;
    }

    line[j] = '\0';

    return j;
}
