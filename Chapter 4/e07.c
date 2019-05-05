#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char s[]);

int bufp = 0;
char buf[BUFSIZE];

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) {
    for(int i=strlen(s) - 1; i >= 0; i--) {
        ungetch(s[i]);
    }
}

int main() {
    ungets("hello");
    for(int i=0; i<5; i++) {
        printf("%c", getch());
    }
    printf("\n");
    return 0;
}
