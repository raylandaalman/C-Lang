/*
Revise the main routine of the longest-line program so
 it will correctly print the length of arbritarily long
  input lines, and as much as possible of the text
*/


#include <stdio.h>

#define MAXIMUM 1000


int getCurrentLine(char currentString[], int maximum);
void copyString(char to[], char from[]);



int main(void) {

    int currentLength;
    int biggestLength;

    biggestLength = 0;

    char currentString[MAXIMUM];
    char biggestString[MAXIMUM];

    while((currentLength = getCurrentLine(currentString, MAXIMUM)) > 0) {
        if (currentLength > biggestLength) {
            biggestLength = currentLength;
            copyString(biggestString, currentString);
        }
    }
    if (biggestLength > 0) {
        printf("\nLongest Line:\t%s", biggestString);
        printf("Number of characters:\t%d characters\n", biggestLength - 1);
    }

}



int getCurrentLine(char currentString[], int maximum) {
    int letter, i;

    for(i = 0; i < maximum - 1 && (letter = getchar()) != EOF && letter != '\n'; ++i) {
        currentString[i] = letter;
    }
    if (letter == '\n') {
        currentString[i] = letter;
        ++i;
    }
    currentString[i] = '\0';
    return i;
}


void copyString(char to[], char from[]) {
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0') {
        ++i;
    }
}
