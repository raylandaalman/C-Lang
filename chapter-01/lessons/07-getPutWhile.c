#include <stdio.h>

int main(void) {
    int c;

    printf("EOF = %d\n", EOF);

    /*
    putchar(82);
    putchar(97);
    putchar(121);
    putchar(108);
    putchar(97);
    putchar(110);
    */

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
