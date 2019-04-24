#include <stdio.h>

int bitcount(int x);

int main() {
    int bits = bitcount(95387);
    printf("%d\n", bits);
    return 0;
}

int bitcount(int x) {
    int bits = 0;
    while(x != 0) {
        x &= x-1;
        bits++;
    }
    return bits;
}

/* Why?
    1. If x is odd, it will end in 1 and x-1 will have all the same bits but end in 0. So x &= x-1 will remove that last 1
    2. If x is even, x-1 will have the same bits up to the last 1 bit of x.  
        This bit in x-1 will be 0, and all bits to the right of this bit will be 1. So x &= x-1 will remove that last 1

    This is true for positive and negative numbers
*/
