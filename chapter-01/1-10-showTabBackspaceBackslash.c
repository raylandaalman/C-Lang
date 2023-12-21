#include <stdio.h>

int main(void) {

    int c;
    int checker;

    checker = 0;

    while((c = getchar()) != EOF) {

        if (c == '\t') {
            printf("\\t");
            ++checker;
        }

        if (c == '\b') {
            printf("\\b");
            ++checker;
        }

        if (c == '\\') {
            printf("\\\\");
            ++checker;
        }

        if (checker == 0) {
            putchar(c);
        }

        checker = 0;
    }
}
