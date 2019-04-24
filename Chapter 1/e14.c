#include <stdio.h>

int main() {
    int c, i, j, white = 0, other = 0;
    int digits[10];
    for(i=0; i<10; i++){
        digits[i] = 0;
    }

    while((c = getchar()) != EOF){
        if(c >= '0' && c <= '9') {
            digits[c - '0']++;
        }else if(c == ' ' || c == '\n' || c == '\t'){
            white++;
        }else{
            other++;
        }
    }

    for(i=0; i<10; i++){
        printf("%11d ", i);
        for(j=0; j<digits[i]; j++){
            printf("*");
        }
        printf("\n");
    }

    printf("White space ");
    for(i=0; i<white; i++){
        printf("*");
    }
    printf("\n");

    printf("     Others ");
    for(i=0; i<other; i++){
        printf("*");
    }
    printf("\n");

    return 0;
}
