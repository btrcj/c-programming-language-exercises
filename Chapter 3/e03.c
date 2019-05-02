#include <stdio.h>

void expand(char s1[], char s2[]);

int main() {
    char s1[] = "c-f 0-5 vcxa-gv0-40c a-c- f- -m a-c-e p-";
    char s2[100];
    expand(s1, s2);
    printf("%s\n", s1);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[]) {
    int i = 0, j = 0, dash = 0;

    for(i = 0; s1[i] != '\0'; i++) {
        if(dash == 1) {
            if(
                s1[i-2] <= s1[i] && (
                    (s1[i-2] >= 'a' && s1[i-2] <= 'z' && s1[i] >= 'a' && s1[i] <= 'z') || 
                    (s1[i-2] >= '0' && s1[i-2] <= '9' && s1[i] >= '0' && s1[i] <= '9')
                )
            ) {
                int k = s1[i-2] + 1;
                while(k <= s1[i]) {
                    s2[j] = k;
                    k++;
                    j++;
                }
            } else {
                s2[j] = '-';
                j++;
                s2[j] = s1[i];
                j++;
            }
            dash = 0;
        } else if(s1[i] == '-') {
            dash = 1;
        } else {
            s2[j] = s1[i];
            j++;
        }
    }

    if(dash == 1) {
        s2[j] = '-';
        j++;
    }

    s2[j] = '\0';
}
