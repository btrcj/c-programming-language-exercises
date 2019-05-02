#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
    char s[30];
    char t[] = "aaa\tttn\nnnn";
    escape(s, t);
    printf("%s\n", s);

    char u[30];
    char v[] = "aaa\\aa\\tnn\\nnt";
    unescape(u, v);
    printf("%s\n", u);

    return 0;
}

void escape(char s[], char t[]) {
    int i, j = 0;
    for(i = 0; t[i] != '\0'; i++) {
        switch(t[i]) {
            case '\n':
                s[j] = '\\';
                j++;
                s[j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                j++;
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
        }
        j++;
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j = 0, escape = 0;

    for(i = 0; t[i] != '\0'; i++) {
        switch(t[i]) {
            case '\\':
                escape = 1;
                break;
            case 't':
                if(escape > 0) {
                    s[j] = '\t';
                    escape = 0;
                } else {
                    s[j] = t[i];
                }
                j++;
                break;
            case 'n':
               if(escape > 0) {
                    s[j] = '\n';
                    escape = 0;
                } else {
                    s[j] = t[i];
                }
                j++;
                break;
            default:
                if(escape > 0) {
                    s[j] = '\\';
                    j++;
                    escape = 0;
                }
                s[j] = t[i];
                j++;
        }
    }
    s[j] = '\0';
}
