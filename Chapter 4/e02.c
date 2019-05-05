#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
    char s[] = "123.45";
    char t[] = "123.45e-6";
    char u[] = "123.45e6";
    char v[] = "123.45e+6";
    printf("%f\n", atof(s));
    printf("%f\n", atof(t));
    printf("%f\n", atof(u));
    printf("%f\n", atof(v));
    return 0;
}

double atof(char s[]) {
    double val, power;
    int i, j, sign, exponent, exponentSign, factor;

    for(i=0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if(s[i] == 'e') {
        i++;
        exponentSign = (s[i] == '-') ? -1 : 1;
        if(s[i] == '+' || s[i] == '-')
            i++;
        for(exponent = 0; isdigit(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');
        for(j=0, factor = 1; j < exponent; j++)
            factor = 10 * factor;
        if(exponentSign == 1)
            return (sign * val / power) * factor;
        else
            return (sign * val / power) / factor;
    }

    return sign * val / power;
}
