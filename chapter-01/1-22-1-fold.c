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
#define TABLENGTH 8

int getLineLength(char string[], int maxLength);


int main(void) {

    char currentString[MAXLENGTH];
    char foldString[MAXLENGTH];
    int columnPosition;
    int tabBreakLength;
    int blankLocation;
    int offset;
    int length;
    int i;
    int j;

    tabBreakLength = TABLENGTH;
    columnPosition = 0;
    blankLocation = 0;
    offset = 0;
    j = 0;

    while((length = getLineLength(currentString, MAXLENGTH)) > 0) {

        for(i = 0; currentString[i] != '\0'; ++i) {

            if(tabBreakLength <= 0) {
                tabBreakLength = TABLENGTH;
            }

            if(currentString[i] == ' ') {
                blankLocation = i + offset;
                foldString[j] = currentString[i];
                ++columnPosition;
                ++j;
                --tabBreakLength;
            } else if(currentString[i] == '\t') {
                blankLocation = i + offset;
                foldString[j] = currentString[i];
                columnPosition = columnPosition + tabBreakLength;
                tabBreakLength = TABLENGTH;
                ++j;
            } else if(currentString[i] == '\n') {
                foldString[j] = currentString[i];
                columnPosition = 0;
                tabBreakLength = TABLENGTH;
                blankLocation = 0;
                ++j;
            } else {
                foldString[j] = currentString[i];
                //printf("i: %3d, j: %3d\n", i, j);
                ++columnPosition;
                ++j;
                --tabBreakLength;
                //printf("columnPosition: %2d\n", columnPosition);
            }

            if(columnPosition > COLUMNWIDTH) {
                if(blankLocation == 0) {
                    foldString[j-1] = '\n';
                    foldString[j] = currentString[i];
                    ++j;
                    ++offset;
                    columnPosition = 1;
                    tabBreakLength = TABLENGTH - 1;
                    //printf("Column Location: %d\n", columnPosition);
                } else {
                    foldString[blankLocation] = '\n';
                    columnPosition = i - blankLocation;
                    blankLocation = 0;
                }
                /*
                printf("- LINE BREAK: Current letter: ");
                putchar(currentString[i]);
                printf("\n");
                */
            }
            //printf("Blank Location: %d\n", blankLocation);
            /*
            printf("Column Position: %2d | Letter: ", columnPosition);
            putchar(currentString[i]);
            printf("\n");
            */
            //printf("Value of i: %d\n", i);
        }
        foldString[j] = '\0';
        /*
        for(i = 0; currentString[i] != '\0'; ++i) {
            printf("\ncharacter: ");
            putchar(currentString[i]);
        }
        */
        printf("\nProvided String:\n%s\n\n", currentString);
        printf("Folded String:\n%s\n", foldString);
    }
}

int getLineLength(char string[], int maxLength) {

    int i;
    int letter;

    for(i = 0; i < maxLength && (letter = getchar()) != EOF; ++i) {
        string[i] = letter;
    }
    string[i] = '\0';
    return i;
}
