#include <stdio.h>

int main(void) {
    int c;
    int a;

    c = getchar();
    a = -1;

    printf("EOF = %d\n", EOF);

    while (c != EOF) {

        putchar(c);
        //printf("  --> %d\n", c);
        // printf("\n EOF = %d", EOF);
        c = getchar();
    }
}
