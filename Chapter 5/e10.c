#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
#define NUMBER '0'
#define UNKNOWN '1'

int getop(char []);
void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: expr [args]");
    } else {
        int type;
        double op2;

        while(--argc > 0) {
            char *current = *++argv;
            int type = getop(current);
            switch(type) {
                case NUMBER:
                    push(atof(current));
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
                default:
                    printf("error: unknown command %s\n", current);
                    break;
            }
        }

        printf("%.8g\n", pop());
    }

    return 0;
}

int getop(char *s) {
    int c, d;

    while((c = *s++) == ' ' || c == '\t')
        ;

    if(!isdigit(c) && c != '.' && c != '-')
        return c;

    if(c == '-') {
        d = *s++;
        if(d != '\0')
            *s--;
        if(!isdigit(d))
            return c;
    }

    if(isdigit(c) || c == '-')
        while(isdigit(c = *s++))
            ;

    if(c == '.')
        while(isdigit(c = *s++))
            ;

    if(c == '\0')
        return NUMBER;
    else
        return UNKNOWN;
}

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
