#include <stdio.h>

#define MAXLINE 10

int getLine(char line[], int maxline);
int checkConditions(int i, int maxline, int c);

int main() {
    char line[MAXLINE];
    char longest[MAXLINE];

    while(getLine(line, MAXLINE) > 0) {
        printf("%s", line);
    }

    return 0;
}

int getLine(char line[], int maxline) {
    int c, i;

    for(i=0; checkConditions(i, maxline, (c = getchar())); i++){
        line[i] = c;
    }

    if(c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

int checkConditions(int i, int maxline, int c) {
    if(i < maxline-1) {
        if(c != EOF) {
            if(c != '\n') {
                return 1;
            }
        }
    }

    return 0;
}
