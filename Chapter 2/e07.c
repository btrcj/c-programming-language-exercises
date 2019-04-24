#include <stdio.h>

int invert(int x, int p, int n);

int main() {
    int x = 2511;
    int z = invert(x, 7, 5);
    printf("%d\n", z);
    return 0;
}

int invert(int x, int p, int n) {
    int nOnes = ~(~0 << n);
    int mask = nOnes << (p-n+1);
    int invertedBits = ~(x & mask) & mask;
    int xWithZeros = x & ~mask;
    return xWithZeros | invertedBits;
}
