/*
Write a program to print a histogram of the lengths of words in its input.

X: axis, lengths of words
Y: axis, frequency
*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {

    int c, state, wordLength, i, j;
    c = state = wordLength = i = j = 0;

    int letters[20];
    for (i = 0; i < 20; ++i) {
        letters[i] = 0;
    }

    while((c = getchar()) != EOF) {

        /* Finding the value of characters.
        printf("\nThe character of \"");
        putchar(c);
        printf("\" is: %d", c);

        a-z = 97 to 122
        A-Z = 65 to 90
        */

        // Checking of the input is a letter, and adding word length to array
        if ((c >= 97 && c <= 122 ) || (c >= 65 && c <= 90)) {
            state = IN;
            ++wordLength;
        } else if (state == IN && c == '\'') {
            ;
        } else if (state == IN) {
            state == OUT;
            if (wordLength > 20) {
                ++letters[19];
                wordLength = 0;
            } else {
                ++letters[wordLength-1];
                wordLength = 0;
            }
        }

    }
    /*
    for(i = 0; i < 20; i++) {
        printf("\nIndex %d: %d", i, letters[i]);
    }
    */

    // Printing graph
    printf("\n\nFrequency\n");
    for (i = 20; i > 0; --i) {
        printf("%3d |", i);
        for (j = 0; j < 20; ++j) {
            if (i <= letters[j]) {
                printf("   *");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }

    printf("     ");
    for (i = 0; i < 20; ++i) {
        printf("----");
    }
    printf("\n      ");
    for (i = 1; i < 21; ++i) {
        printf(" %2d ", i);
    }
    printf("\b+\n     Letters\n\n");
}
