#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define ARRSIZE 10

int getch(void);
void ungetch(int);
int getfloat(double *pn);

double array[ARRSIZE];

int main() {
    int n;
    for(n = 0; n < ARRSIZE && getfloat(&array[n]) != EOF; n++)
        ;
    printf("\nOutput:\n");
    for(n = 0; n < ARRSIZE; n++)
        printf("%f\n", array[n]);
    return 0;
}

// Adaptation of atof() from chapter 4 exercise 2
int getfloat(double *pn) {
    double val, power;
    int c, sign, exponent, exponentSign, j, factor;

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

    for(val = 0.0; isdigit(c); c = getch())
        val = 10.0 * val + (c - '0');
    if(c == '.')
        c = getch();
    for(power = 1.0; isdigit(c); c = getch()) {
        val = 10.0 * val + (c - '0');
        power *= 10.0;
    }

    exponentSign = 1, factor = 1;

    if(c == 'e') {
        c = getch();
        exponentSign = (c == '-') ? -1 : 1;
        if(c == '+' || c == '-')
            c = getch();
        for(exponent = 0; isdigit(c); c = getch())
            exponent = 10 * exponent + (c - '0');
        for(j=0; j < exponent; j++)
            factor = 10 * factor;
    }

    if(exponentSign == 1)
        *pn = (sign * val / power) * factor;
    else
        *pn = (sign * val / power) / factor;

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
