#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("signed char max:    %d\n", CHAR_MAX);
    printf("signed char min:   %d\n", CHAR_MIN);
    printf("unsigned char max:  %u\n", UCHAR_MAX);

    printf("\n");

    printf("signed short max:    %d\n", SHRT_MAX);
    printf("signed short min:   %d\n", SHRT_MIN);
    printf("unsigned short max:  %u\n", USHRT_MAX);

    printf("\n");

    printf("signed int max:    %d\n", INT_MAX);
    printf("signed int min:   %d\n", INT_MIN);
    printf("unsigned int max:  %u\n", UINT_MAX);

    printf("\n");

    printf("signed long max:    %ld\n", LONG_MAX);
    printf("signed long min:   %ld\n", LONG_MIN);
    printf("unsigned long max:  %lu\n", ULONG_MAX);

    printf("\n\n");

    printf("Note: for floating point numbers, the minimum displayed here is the minimum representable value greater than 0\n\n");

    printf("float max: %e\n", FLT_MAX);
    printf("float min: %e\n", FLT_MIN);

    printf("\n");

    printf("double max: %e\n", DBL_MAX);
    printf("double min: %e\n", DBL_MIN);
    return 0;
}
