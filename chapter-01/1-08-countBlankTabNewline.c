#include <stdio.h>

int main(void) {

    int c, bl, tab, nl;

    bl = 0;
    tab = 0;
    nl = 0;

    while((c = getchar()) != EOF) {

        if (c ==  ' ') {
            ++bl;
        }
        if (c == '\t') {
            ++tab;
        }
        if (c == '\n') {
            ++nl;
        }
    }

    printf("\nNumber of blanks: %d\n", bl);
    printf("Number of tabs: %d\n", tab);
    printf("Number of lines: %d\n", nl);
}
