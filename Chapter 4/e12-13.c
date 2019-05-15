#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[], int i);
void reverse(char s[], int i, int j);

int main() {
    int m = INT_MIN;
    int n = 98435;
    char s[20];
    itoa(n, s, 0);
    printf("%d : %s\n", n, s);
    itoa(m, s, 0);
    printf("%d : %s\n", m, s);
    return 0;
}

void itoa(int n, char s[], int i) {
    if(n / 10 != 0) {
        int d = n % 10;
        if(d < 0)
            d = -d;
        s[i] = d + '0';
        itoa(n/10, s, i+1);
    } else {
        if(n < 0) {
            s[i++] = -n + '0';
            s[i++] = '-';
        } else {
            s[i++] = n + '0';
        }
        s[i] = '\0';
        reverse(s, 0, strlen(s) - 1);
    }
}

void reverse(char s[], int i, int j) {
    if(i < j) {
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverse(s, i+1, j-1);
    }
}
