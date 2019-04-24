#include <stdio.h>

#define TAB 8

int main() {
    int c, width, i, offset = 0;

    while((c = getchar()) != EOF) {
        if(c == '\t'){
            width = TAB - (offset % TAB);
            for(i=0; i<width; i++) {
                putchar(' ');
            }
            offset = 0;
        }else if(c == '\n'){
            putchar(c);
            offset = 0;
        }else{
            putchar(c);
            offset++;
        }
    }

    return 0;
}
