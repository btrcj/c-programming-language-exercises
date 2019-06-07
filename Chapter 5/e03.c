#include <stdio.h>

void strconcat(char *s, char *t);

int main() {
    char s[10] = "ab";
    char *t = "cdefghij";
    strconcat(s, t);
    printf("%s\n", s);
    return 0;
}

void strconcat(char *s, char *t) {
    while(*s != '\0')
        s++;
    while((*s = *t) != '\0') {
        s++;
        t++;
    }
}
