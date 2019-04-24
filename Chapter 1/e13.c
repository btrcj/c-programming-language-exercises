#include <stdio.h>

#define MAX_WORD_LEN 10

int main() {
    int c, i, j, currentLen = 0;
    int count[MAX_WORD_LEN + 1];
    for(i=0; i<=MAX_WORD_LEN; i++){
        count[i] = 0;
    }

    while((c = getchar()) != EOF){
        if(c == '\n' || c == '\t' || c == ' '){
            count[currentLen]++;
            currentLen = 0;
        }else{
            currentLen++;
        }
    }

    /* Horizontal version */
    for(i=1; i<=MAX_WORD_LEN; i++){
        printf("%d ", i);
        for(j=0; j<count[i]; j++){
            printf("*");
        }
        printf("\n");
    }

    printf("\n----\n");

    /* Vertical version */
    int maxLen = 0;
    for(i=0; i<=MAX_WORD_LEN; i++){
        if(count[i] > maxLen){
            maxLen = count[i];
        }
    }

    for(j=maxLen; j>=0; j--){
        for(i=1; i<=MAX_WORD_LEN; i++){
            if(count[i] > j){
                printf("* ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }

    for(i=1; i<=MAX_WORD_LEN; i++){
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}
