#include <stdio.h>

int htoi(char h[], int n);

int main() {
    char s1[] = "0xa13d";
    char s2[] = "0Xa13d";
    char s3[] = "A90F";
    char s4[] = "5bF79";

    int i1 = htoi(s1, 6);
    int i2 = htoi(s2, 6);
    int i3 = htoi(s3, 4);
    int i4 = htoi(s4, 5);

    printf("%s in hexadecimal is %d in decimal\n", s1, i1);
    printf("%s in hexadecimal is %d in decimal\n", s2, i2);
    printf("%s in hexadecimal is %d in decimal\n", s3, i3);
    printf("%s in hexadecimal is %d in decimal\n", s4, i4);

    return 0;
}

int htoi(char h[], int n) {
    int start = 0, result = 0, i = n-1, power = 1, current;

    if(h[0] == '0' && (h[1] == 'x' || h[1] == 'X')) {
        start = 2;
    }

    while(i >= start) {
        if(h[i] >= '0' && h[i] <= '9') {
            current = h[i] - '0';
        } else if(h[i] >= 'a' && h[i] <= 'f') {
            current = h[i] - 'a' + 10;
        } else if(h[i] >= 'A' && h[i] <= 'F') {
            current = h[i] - 'A' + 10;
        } else {
            /* Not a valid hexadecimal */
            return -1;
        }

        result += current*power;
        power = power*16;
        i--;
    }

    return result;
}
