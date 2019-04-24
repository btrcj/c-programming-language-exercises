#include <stdio.h>

int lower(int c);

int main() {
    char x = lower('x');
    char y = lower('Y');
    printf("%c %c\n", x, y);
    return 0;
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? (c -'A' + 'a') : c;
}
