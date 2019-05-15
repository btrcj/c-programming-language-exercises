#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if(sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[]) {
    int i, c, d;
    static int buf = EOF;

    while((s[0] = c = (buf == EOF ? getchar() : buf)) == ' ' || c == '\t')
        buf = EOF;
    s[1] = '\0';

    buf = EOF;

    if(!isdigit(c) && c != '.' && c != '-')
        return c;

    if(c == '-') {
        d = buf == EOF ? getchar() : buf;
        buf = EOF;
        if(d != EOF)
            buf = d;
        if(!isdigit(d))
            return c;
    }

    i = 0;
    if(isdigit(c) || c == '-')
        while(isdigit(s[++i] = c = (buf == EOF ? getchar() : buf)))
            buf = EOF;
    if(c == '.')
        while(isdigit(s[++i] = c = (buf == EOF ? getchar() : buf)))
            buf = EOF;
    s[i] = '\0';
    if(c != EOF)
        buf = c;
    return NUMBER;
}

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
