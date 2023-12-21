#include <stdio.h>

int main(void) {
    float fahr, celsius;
    int upper, lower, step;

    upper = 300;
    lower = 0;
    step = 20;

    fahr = lower;

    printf(" Cel   Fah\n");
    printf("-----  ---\n");

    while(fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        //printf("%3.0f %6.1f\n", fahr, celsius);
        printf("%5.1f %4.0f\n", celsius, fahr);
        fahr = fahr + step;
    }
}
