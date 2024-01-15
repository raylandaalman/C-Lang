/*

Write a program to 'fold' long input lines
 into two or more shorter lines after the last
  non-blank character that occurs before the n-th
   column of input.

Make sure your program does something intelligent
 with very long lines, and if there are no blansk
  or tabs before the specified column.

*/

#include <stdio.h>

#define MAXLENGTH 1000
#define COLUMNWIDTH 80
#define TABWIDTH 8

int getLength(char currentString[], int maxLength);

int main(void) {

    char currentString[MAXLENGTH];
    char foldedString[MAXLENGTH];

    int i, j;
    int length;
    int columnLocation;
    int lastSpace;
    int wordState;
    int wordLength;

    while((length = getLength(currentString, MAXLENGTH)) > 0 ) {

        columnLocation = 0;
        lastSpace = -1;

        printf("Current String:\n%s\n\n", currentString);

        for(i = 0; currentString[i] != '\n'; ++i) {
            if(currentString[i] == ' ' && columnLocation < COLUMNWIDTH) {
                foldedString[i] = currentString[i];
                lastSpace = i;
                ++columnLocation;
            } else if(currentString[i] == ' ' && columnLocation >= COLUMNWIDTH) {
                foldedString[i] = '\n';
                columnLocation = 0;
            }

            if(currentString[i] == '\t' && (columnLocation + TABWIDTH) < COLUMNWIDTH) {
                foldedString[i] = '\t';
                columnLocation = columnLocation + TABWIDTH;
            } else if(currentString[i] == '\t' && (columnLocation + TABWIDTH) >= COLUMNWIDTH) {
                foldedString[i] = '\n';
                columnLocation = 0;
            }


            if(currentString[i] != ' ' && currentString[i] != '\t') {

                wordLength = 0;

                printf("Value of i: %d\n", i);
                j = i;
                printf("The value of currentString[j] = %d\n", currentString[j+2]);

                return 0;
                for(j = i; currentString[j] != ' ' && currentString[j] != '\t' && currentString[j] != '\n'; ++j) {
                    ++wordLength;
                    printf("test\n");
                }

                printf("Word Length: %d\n", wordLength);

                if((columnLocation + wordLength) < COLUMNWIDTH) {
                    for(i; i <= j; ++i) {
                        foldedString[i] = currentString[i];
                    }
                    columnLocation = columnLocation + wordLength;
                } else if((columnLocation + wordLength) >= COLUMNWIDTH) {
                    if(lastSpace == -1) {
                        for(i = 0; i < j; ++j) {
                            foldedString[i] = currentString[i];
                        }
                    }
                    } else {
                        foldedString[lastSpace] = '\n';
                        for(i; i < j; ++i) {
                            foldedString[i] = currentString[i];
                        }
                        columnLocation = wordLength - 1;
                }
            }
        }
        printf("Provided String:\n%s\n\n", currentString);
        printf("Folded String:\n%s\n\n", foldedString);
    }
}

int getLength(char currentString[], int maxLength) {

    int letter;
    int i;

    for(i = 0; i < maxLength - 1 && (letter = getchar()) != '\n'; ++i) {
        currentString[i] = letter;
    }

    if(currentString[i] == '\n') {
        currentString[i] = '\n';
        ++i;
    }

    currentString[i] = '\0';
    ++i;

    return i;

}
