#include <stdio.h>
#include <string.h>
#include <ctype.h>

void itoa(int n, char *s);
int atoi(char *s);
void reverse(char *s);
int strindex(char *s, char *t);

int main() {
    int a = -54978;
    char s[10];
    itoa(a, s);
    printf("%s\n", s);

    char t[] = " +94265";
    int b = atoi(t);
    printf("%d\n", b);

    char u[] = "try to reverse";
    reverse(u);
    printf("%s\n", u);

    char v[] = "larger string";
    char w[] = "str";
    int c = strindex(v, w);
    printf("%d\n", c);
    return 0;
}

// Adaptation from chapter 3 exercise 4
void itoa(int n, char *s) {
    int sign = n;
    char *start = s;

    do {
        int d = n % 10;
        if(sign < 0)
            d = -d;
        *s++ = d + '0';
    } while((n /= 10) != 0);

    if(sign < 0)
        *s++ = '-';
    
    *s = '\0';

    reverse(start);
}

// Adaptation from page 61
int atoi(char *s) {
    int n, sign;

    while(isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if(*s == '+'|| *s == '-')
        s++;
    for(n=0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

// Adaptation from page 62
void reverse(char *s) {
    int c;
    char *p = s + strlen(s) - 1;

    for( ; s < p; s++, p--) {
        c = *s;
        *s = *p;
        *p = c;
    }
}

// Adaptation from page 69
int strindex(char *s, char *t) {
    int i;
    char *p, *q;
    for(i=0; *(s+i) != '\0'; i++) {
        for(p=(s+i), q=t; *q != '\0' && *p == *q; p++, q++)
            ;
        if(q > t && *q == '\0')
            return i;
    }
    return -1;
}
