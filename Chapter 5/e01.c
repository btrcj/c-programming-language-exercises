#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define ARRSIZE 10

int getch(void);
void ungetch(int);
int getint(int *pn);

int array[ARRSIZE];

int main() {
    int n;
    for(n = 0; n < ARRSIZE && getint(&array[n]) != EOF; n++)
        ;
    printf("\nOutput:\n");
    for(n = 0; n < ARRSIZE; n++)
        printf("%d\n", array[n]);
    return 0;
}

int getint(int *pn) {
    int c, sign;
    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-') {
        char d = getch();
        if(!isdigit(d)) {
            ungetch(d);
            ungetch(c);
            return 0;
        } else {
            c = d;
        }
    }
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * (*pn) + (c - '0');
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}

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
