#include <stdio.h>

#define TAB 8

int main() {
    int c, tabs, remaining, i, nonSpaces = 0, spaces = 0;

    while((c = getchar()) != EOF) {
        if(c == ' '){
            spaces++;
        }else if(c == '\n'){
            putchar(c);
            spaces = 0;
            nonSpaces = 0;
        }else{
            if(spaces > 1){
                int toReachTab = TAB - (nonSpaces % TAB);
                if(spaces >= toReachTab){
                    putchar('\t');
                    spaces = spaces - toReachTab;
                }
                tabs = spaces / TAB;
                remaining = spaces % TAB;
                for(i=0; i<tabs; i++){
                    putchar('\t');
                }
                for(i=0; i<remaining; i++){
                    putchar(' ');
                }
                spaces = 0;
                nonSpaces = 0;
            }else if(spaces == 1){
                putchar(' ');
            }
            nonSpaces++;
            putchar(c);
        }
    }

    return 0;
}
