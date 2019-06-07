#include <stdio.h>

void strncopy(char *s, char *t, int n);
void strnconcat(char *s, char *t, int n);
int strncomp(char *s, char *t, int n);

int main() {
    char s[10];
    s[0] = 'a';
    s[1] = 'b';
    s[2] = '\0';
    char *t = "cdefghij";
    strnconcat(s, t, 3);
    printf("%s\n", s);

    char u[10];
    char *v = "abcdefghij";
    strncopy(u, v, 7);
    printf("%s\n", u);

    char *x = "abcde";
    char *y = "abcdz";
    int r = strncomp(x, y, 4);
    printf("%d\n", r);

    return 0;
}

void strncopy(char *s, char *t, int n) {
    int i = 0;
    while(i < n && (*s = *t) != '\0') {
        s++;
        t++;
        i++;
    }
    *s = '\0';
}

void strnconcat(char *s, char *t, int n) {
    while(*s != '\0')
        s++;
    int i = 0;
    while(i < n && (*s = *t) != '\0') {
        s++;
        t++;
        i++;
    }
    *s = '\0';
}

int strncomp(char *s, char *t, int n) {
    int i = 0;
    while(i < n && *s == *t) {
        if(*s == '\0' || i == n-1) return 0;
        s++;
        t++;
        i++;
    }
    return *s - *t;
}
