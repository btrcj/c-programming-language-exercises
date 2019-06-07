#include <stdio.h>

int strend(char *s, char *t);

int main() {
    int result = strend("Should return one", " one");
    printf("%d\n", result);
    result = strend("Should not return one", "one.");
    printf("%d\n", result);
    return 0;
}

int strend(char *s, char *t) {
    char *u = t;
    while(*s != '\0')
        s++;
    while(*t != '\0')
        t++;
    while(*s == *t) {
        s--;
        t--;
    }
    if(u < t) return 0;
    else return 1;
}
