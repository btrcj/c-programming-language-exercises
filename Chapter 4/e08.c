#include <stdio.h>

int getch(void);
void ungetch(int);

int buf = EOF;

int getch(void) {
    int c;
    if(buf != EOF)
        c = buf;
    else
        c = getchar();
    buf = EOF;
    return c;
}

void ungetch(int c) {
    if(buf == EOF)
        buf = c;
    else
        printf("ungetch: too many characters\n");
}

int main() {
    ungetch('x');
    printf("%c\n", getch());
    return 0;
}
