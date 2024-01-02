/*
Write a function reverse(s), that reverses the
 character string s. Use it to write a program
  that reverses its input a line at a time.
*/

// libraries
#include <stdio.h>

// constants
#define MAXLENGTH 1000

// functions
int getLineLength(char currentLine[], int maxLength);

int main(void) {

    char currentLine[MAXLENGTH];
    char reversedLine[MAXLENGTH];
    int length;
    int start;
    int end;
    int i, j;

    while((length = getLineLength(currentLine, MAXLENGTH)) != 0) {

        for(i = 0; currentLine[i] == ' ' || currentLine[i] == '\t'; ++i) {
            ;
        }
        start = i;

        for(i = length-1; currentLine[i] == ' ' || currentLine[i] == '\t' || currentLine[i] == '\n' || currentLine[i] == EOF; --i) {
         ;
        }
        end = i;

        if(currentLine[0] != '\n') {
            for(i = end; i >= start; i--) {
                putchar(currentLine[i]);
            }
        printf("\n");
        }
    }

}

int getLineLength(char currentLine[], int maxLength) {

    int i;
    int letter;

    for(i = 0; i < maxLength - 1 && (letter = getchar()) != EOF && letter != '\n'; ++i) {
        currentLine[i] = letter;
    }
    if(letter == '\n') {
        currentLine[i] = letter;
        ++i;
    }

    return i;
}
