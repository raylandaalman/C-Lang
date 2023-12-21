#include <stdio.h>

int main(void) {

    int c;
    int character;

    for (character = 1; (c = getchar()) != EOF; ++character) {
        if (c != ' ') {
            putchar(c);
        }

        if (c == ' ') {
            if (character != 1) {
                putchar(c);
            }
            character = 0;
        }
    }
}
