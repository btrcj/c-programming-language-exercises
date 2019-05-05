#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MATH '1'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

double peek();
void duplicate();
void swap();
void clear();
void mathFunction(char s[]);

int sp = 0;
double val[MAXVAL];
int bufp = 0;
char buf[BUFSIZE];

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

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getop(char s[]) {
    int i, c, d;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if(isalpha(c)) {
        i = 0;
        s[i] = c;
        while(isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if(c != EOF)
            ungetch(c);
        return MATH;
    }

    if(!isdigit(c) && c != '.' && c != '-')
        return c;

    if(c == '-') {
        if((d = getch()) == ' ')
            return c;
        else if(d != EOF)
            ungetch(d);
    }

    i = 0;
    if(isdigit(c) || c == '-')
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

double peek() {
    if(sp > 0)
        return val[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicate() {
    if(sp > 0) {
        push(val[sp - 1]);
    } else {
        printf("error: stack empty\n");
    }
}

void swap() {
    if(sp > 1) {
        int a = pop();
        int b = pop();
        push(a);
        push(b);
    } else {
        printf("error: need two numbers in the stack\n");
    }
}

void clear() {
    sp = 0;
}

void mathFunction(char s[]) {
    if(sp > 0) {
        if(strcmp(s, "sin") == 0)
            push(sin(pop()));
        else if(strcmp(s, "cos") == 0)
            push(cos(pop()));
        else if(strcmp(s, "tan") == 0)
            push(tan(pop()));
        else if(strcmp(s, "exp") == 0)
            push(exp(pop()));
        else if(strcmp(s, "pow") == 0) {
            if(sp > 1) {
                int y = pop();
                push(pow(pop(), y));
            } else
                printf("error: need two numbers in the stack\n");
        } else
            printf("error: unknown command\n");
    } else {
        printf("error: stack empty\n");
    }
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
           case '$':
                printf("\t%.8g\n", peek());
                break;
            case '&':
                duplicate();
                break;
            case '#':
                swap();
                break;
            case '!':
                clear();
                break;
            case MATH:
                mathFunction(s);
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
