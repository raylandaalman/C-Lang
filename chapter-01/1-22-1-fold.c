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
#define MAXCOLUMNS 80
#define TABLENGTH 8

int getLength(char inputString[], int maxLength);

int main(void) {

    char inputString[MAXLENGTH];
    char foldString[MAXLENGTH];

    int i, j;

    int length;
    int columnLocation;
    int lastBlank;
    int wordLength;

    while((length = getLength(inputString, MAXLENGTH)) > 0) {

        columnLocation = 0;
        lastBlank = -1;

        for(i = 0; inputString[i] != '\n'; ++i) {

            if(inputString[i] == ' ' && columnLocation < MAXCOLUMNS) {
                foldString[i] = inputString[i];
                lastBlank = i;
                ++columnLocation;
            } else if(inputString[i] == ' ' && columnLocation >= MAXCOLUMNS) {
                foldString[i] = '\n';
                columnLocation = 0;
                lastBlank = i;
            }

            if(inputString[i] == '\t' && (columnLocation + TABLENGTH) < MAXCOLUMNS) {
                foldString[i] = '\t';
                columnLocation = columnLocation + TABLENGTH;
                lastBlank = i;
                printf("Column Location: %d\n", columnLocation);
            } else if(inputString[i] == '\t' && (columnLocation + TABLENGTH) >= MAXCOLUMNS) {
                foldString[i] = '\n';
                columnLocation = 0;
                lastBlank = i;
            }

            if(inputString[i] != ' ' && inputString[i] != '\t') {

                wordLength = 0;

                for(j = i; inputString[j] != ' ' && inputString[j] != '\t' && inputString[j] != '\n' && inputString[j] != '\0'; ++j) {
                 //printf("Value of i: %d, Value of j: %d\n", i, j);
                 ++wordLength;
                }

                //printf("World Length: %d\n", wordLength);
                //printf("Value of i: %d, Value of j: %d\n", i, j);

                if((columnLocation + wordLength) <= MAXCOLUMNS) {
                    for(i; i < j; ++i) {
                        foldString[i] = inputString[i];
                        ++columnLocation;
                    }
                } else if((columnLocation + wordLength) > MAXCOLUMNS) {
                    foldString[lastBlank] = '\n';
                    columnLocation = 0;
                    for(i; i < j; ++i) {
                        foldString[i] = inputString[i];
                        ++columnLocation;
                    }
                }
            --i;
            //printf("End: Value of i: %d, Value of j: %d\n", i, j);
            }
        }
        if(inputString[i] == '\n') {
            foldString[i] = '\n';
            ++i;
        }
        foldString[i] = '\0';

        printf("\nInput String:\n%s\n\n", inputString);
        printf("Fold String:\n%s\n\n", foldString);
    }
}

int getLength(char inputString[], int maxLength) {

    int i;
    int letter;

    for(i = 0; i < maxLength - 1 && (letter = getchar()) != EOF && letter != '\n'; ++i) {
        inputString[i] = letter;
    }
    if(letter == '\n') {
        inputString[i] = letter;
        ++i;
    }

    inputString[i] = '\0';
    return i;
}
