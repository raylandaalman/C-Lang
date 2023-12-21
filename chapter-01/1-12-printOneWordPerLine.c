#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {

    int c, state;

    state = 0;

    while ((c = getchar()) != EOF) {

        if (c != ' ' && c != '\t') {
            state = IN;
            putchar(c);
        } else if (state == IN) {
            state = OUT;
            printf("\n");
        }

    }
}
