#include <stdio.h>

int main(void) {

    int c;
    int character;

    character = 0;

    while((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            ++character;
        }

        if (c == ' ') {
            if (character != 0) {
                putchar(c);
            }
            character = 0;
        }
    }
}
