#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    char s1[] = "abcdefghijk";
    char s2[] = "hfkc";
    int first = any(s1, s2);
    printf("The first character of s2 occurs in position %d of s1\n", first);
    return 0;
}

int any(char s1[], char s2[]) {
    int i = 0, j = 0, first = -1;

    for(i = 0; s1[i] != '\0'; i++) {
        for(j = 0; s2[j] != '\0'; j++) {
            if(s1[i] == s2[j] && (first == -1 || i < first)) {
                first = i;
            }
        }
    }

    return first;
}
