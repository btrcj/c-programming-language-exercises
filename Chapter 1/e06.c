#include <stdio.h>

int main() {
    int c, value = 1;
    
    while(value) {
        c = getchar();
        value = (c != EOF);
        printf("%d\n", value);
    }

    return 0;
}
