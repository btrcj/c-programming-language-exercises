#include <stdio.h>

int main() {
    int c, nl = 0, tab = 0, space = 0;

    while((c = getchar()) != EOF){
        if(c == '\n'){
            nl++;
        }else if(c == '\t'){
            tab++;
        }else if(c == ' '){
            space++;
        }
    }

    printf("New lines: %d\n", nl);
    printf("Tabs: %6d\n", tab);
    printf("Spaces: %4d\n", space);

    return 0;
}
