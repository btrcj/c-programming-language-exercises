#include <stdio.h>

float fahrenheitToCelsius(float fahr);

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("FAHRENHEIT CELSIUS\n");

    fahr = lower;
    while(fahr <= upper){
        celsius = fahrenheitToCelsius(fahr);
        printf("%10.0f %7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

float fahrenheitToCelsius(float fahr) {
    return (5.0 / 9.0)*(fahr - 32);
}
