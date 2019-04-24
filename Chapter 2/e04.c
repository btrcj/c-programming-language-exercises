#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "holaa hola que tal";
    char s2[] = "hola";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i = 0, j = 0, k = 0, in = 0;

    for(i = 0; s1[i] != '\0'; i++) {
        in = 0;
        for(j = 0; s2[j] != '\0' && in == 0; j++) {
            if(s1[i] == s2[j]) {
                in = 1;
            }
        }
        if(in == 0) {
            s1[k] = s1[i];
            k++;
        }
    }

    s1[k] = '\0';
}
