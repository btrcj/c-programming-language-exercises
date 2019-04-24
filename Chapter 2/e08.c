#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int n);

int main() {
    unsigned x = 4415;
    unsigned z = rightrot(x, 4);
    printf("%u\n", z);
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    unsigned y = x >> n;
    unsigned ones = ~(~0 << n);
    int shift = sizeof(x) * CHAR_BIT - n;
    unsigned leftmost = (x & ones) << shift;
    return leftmost | y;
}
