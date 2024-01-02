/*

Write a program to remove trailing blanks and tabs
 from each line of input, and to delete entirely
  blank lines

*/

// get length of line
//  check if input contains ' ' '\t' '\n'

#include <stdio.h>

#define MAXLENGTH 1000

int getStringLength(char currentString[], int maxLength);


int main(void) {

    char currentString[MAXLENGTH];
    int length;
    int endOfSentence;
    int firstWordState;
    int i;

    while((length = getStringLength(currentString, MAXLENGTH)) > 0) {
        for(endOfSentence = length; endOfSentence != ' ' && endOfSentence != '\t'; --endOfSentence) ;
        if(currentString[0] != '\n') {
            printf("\n");
            for(i = 0; i < MAXLENGTH - 1 && i < endOfSentence; ++i) {
                else putchar(i);
            }
        }
}


int getStringLength(char currentString[], int maxLength) {

    int letter, i;

    for(i = 0; i < maxLength - 1 && (letter = getchar()) != EOF && letter != '\n'; ++i) {
        currentString[i] = letter;
    }
    if( letter == '\n') {
        currentString[i] = '\n';
        ++i;
    }
    return i;
}
