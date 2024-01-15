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
    int blankLocation;
    int tabBreakLength;
    int length;
    int i;

    columnPosition = 0;
    tabBreakLength = TABLENGTH;


    while((length = getLineLength(currentString, MAXLENGTH)) > 0) {

        for(i = 0; currentString[i] != '\0'; ++i) {

            if(tabBreakLength <= 0) {
                tabBreakLength = TABLENGTH;
            }

            if(currentString[i] == ' ') {
                blankLocation = i;
                foldString[i] = currentString[i];
                ++columnPosition;
                --tabBreakLength;
            } else if(currentString[i] == '\t') {
                blankLocation = i;
                foldString[i] = currentString[i];
                columnPosition = columnPosition + tabBreakLength;
                tabBreakLength = TABLENGTH;
            } else if(currentString[i] == '\n') {
                foldString[i] = currentString[i];
                columnPosition = 0;
                tabBreakLength = TABLENGTH;
            } else {
                foldString[i] = currentString[i];
                ++columnPosition;
                --tabBreakLength;
            }

            if(columnPosition > COLUMNWIDTH) {
                foldString[blankLocation] = '\n';
                columnPosition = i - blankLocation;
                /*
                printf("- LINE BREAK: Current letter: ");
                putchar(currentString[i]);
                printf("\n");
                */
            }

            /*
            printf("Column Position: %2d | Letter: ", columnPosition);
            putchar(currentString[i]);
            printf("\n");
            */
            //printf("Value of i: %d\n", i);
        }

        foldString[i] = '\0';

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
