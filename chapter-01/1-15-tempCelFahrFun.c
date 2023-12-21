#include <stdio.h>

float convertTemp(int);

int main(void) {

    int fahr;

    printf(" Fah    Cel \n");
    printf("-----  -----\n");

    for(fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf(" %3d   %5.1f\n", fahr, convertTemp(fahr));
}

float convertTemp(int fahr) {
    return ((5.0/9.0) * (fahr-32.0));
}
