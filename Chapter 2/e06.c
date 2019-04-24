#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
    int x = 207;
    int y = 6;
    int z = setbits(x, 6, 4, y);
    printf("%d\n", z);
    return 0;
}

int setbits(int x, int p, int n, int y) {
    int nOnes = ~(~0 << n);
    int mask = nOnes << (p-n+1);
    int field = (y & nOnes) << (p-n+1);
    return (x & ~mask) | field;
}
