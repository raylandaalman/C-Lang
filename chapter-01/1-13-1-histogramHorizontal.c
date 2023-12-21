/*
Write a program to print a histogram of the lengths of words in its input.

Histogram will be vertical:
Y-axis: Word length
X-axis: Word requence
*/

#include <stdio.h>

int main(void) {

    int c, i, j, word;
    int wlength[20];

    word = 0;

    for (i = 0; i < 20; ++i)
        wlength[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t' || c == ',' || c == ';' || c == '.' || c == '!') {
            if (word > 20) {
                ++wlength[19];
                word = 0;
            } else {
                ++wlength[word - 1];
                word = 0;
            }
        } else if ( c == '\'' || c == '-'){
            ;
        } else {
            ++word;
        }
    }

    printf("\nLetters\n");

    for (i = 19; i >= 0; --i) {
        printf("%2d |", i+1);
        for (j = wlength[i]; j > 0; j--) {
            printf("****");
        }
        printf("\n");
    }

    printf("    ");
    for (i = 0; i < 20; ++i){
        printf("----");
    }
    printf("\nFreq:");
    for (i = 0; i < 20; ++i)
        printf(" %2d ", i+1);
    printf("\n");
}

    /*
    printf("\nWord count:");
    for (i = 0; i < 20; ++i) {
            printf(" %2d", wlength[i]);
    }
    printf("\n            ");
    for (i = 0; i < 20; ++i) {
        printf("%2d ", i+1);
    }
    printf("\b+\n\n");
    */
