/*

Write a program to print all input lines that are
 longer than 80 characters.

*/

/*
Find length of line
  if line is more than 80 characters
    print line
*/

#include <stdio.h>

#define MAXLENGTH 1000
#define CHARLENGTH 40

int getLineLength(char currentLine[], int maxLength);




int main(void) {

    int length, i;
    char currentLine[MAXLENGTH];

    while((length = getLineLength(currentLine, MAXLENGTH)) > 0) {
        if(length > CHARLENGTH) {
            printf("\n--Line detected that is at least %d characters:\n\t", CHARLENGTH);
            for(i = 0; i < length; ++i) {
                putchar(currentLine[i]);
            }
            printf("\t--Length of line: %d\n\n", length-1);
        }
    }
}


int getLineLength(char currentLine[], int maxLength) {
    int letter;
    int i;

    for(i = 0; i < maxLength - 1 && (letter = getchar()) != EOF && letter != '\n'; ++i) {
        currentLine[i] = letter;
    }
    if(letter == '\n') {
        currentLine[i] = letter;
        i++;
    }
    currentLine[i] = '\0';

    return i;
}


