/*
Write a program to print a histogram of the
 frequencies of different characters in its input
*/

#include <stdio.h>

#define IN 1
#define OUT 0


int main(void) {

    int letters[26];
    int c, i, j;

    for(i = 0; i < 26; ++i)
        letters[i] = 0;

    while((c = getchar()) != EOF) {
        if(c >= 65 && c <= 90) {
            c = c + 32;
        }
        if(c >= 97 && c<= 122) {
            ++letters[c-97];
        }
    }

    printf("\nFrequency\n");

    for(i = 20; i > 0; --i) {
        printf("%2d | ", i);
        for(j = 0; j < 26; ++j) {
            if(letters[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("    ");
    for(i = 0; i < 26; ++i) {
        printf("---");
    }

    printf("\n     ");
    for(i = 97; i < 123; ++i) {
        printf(" ");
        putchar(i);
        printf(" ");
    }
    printf("\b\n     Letters\n");
}
