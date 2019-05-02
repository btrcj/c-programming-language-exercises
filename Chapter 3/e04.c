#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    int n = INT_MIN;
    char s[20];
    itoa(n, s);
    printf("%d\n", n);
    printf("%s\n", s);
    return 0;
}

// The one in the book doesn't work because if n is negative it does n = -n
// The maximum positive value is 2^(wordsize-1) - 1, so for n=-(2^(wordsize-1)), doing n = -n won't work
// For example if wordsize is 8, the range is [-128, 127]. 128 can't be expressed
void itoa(int n, char s[]) {
    int i, sign = n;

    i = 0;
    do {
        int d = n % 10;
        if(sign < 0)
            d = -d;
        s[i++] = d + '0';
    } while((n /= 10) != 0);

    if(sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';

    reverse(s);
}

// Page 62
void reverse(char s[]) {
    int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
