/* Does not handle // comments */

#include <stdio.h>
#define PROGRAM 0
#define STRING 1
#define ESCAPE 2
#define START_COMMENT 3
#define COMMENT 4
#define END_COMMENT 5

int main() {
    int c, stringChar, state = PROGRAM;

    while((c = getchar()) != EOF) {
        if(state == PROGRAM) {
            if(c == '/') {
                state = START_COMMENT;
            } else if(c == '\"' || c == '\'') {
                state = STRING;
                stringChar = c;
                putchar(c);
            } else {
                putchar(c);
            }
        } else if(state == STRING) {
            if(c == '\\') {
                state = ESCAPE;
            } else if(c == stringChar) {
                state = PROGRAM;
            }
            putchar(c);
        } else if(state == ESCAPE) {
            putchar(c);
            state = STRING;
        } else if(state == START_COMMENT) {
            if(c == '*') {
                state = COMMENT;
            } else {
                putchar('/');
                putchar(c);
                state = PROGRAM;
            }    
        } else if(state == COMMENT) {
            if(c == '*') {
                state = END_COMMENT;
            }
        } else if(state == END_COMMENT) {
            if(c == '/') {
                state = PROGRAM;
            } else {
                state = COMMENT;
            }
        }
    }

    return 0;
}
