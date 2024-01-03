/*

Write a program 'detab' that replaces tabs
 in the input with the proper number of blanks
  to space the next tab stop.

Assume a fixed set of tab stops, say every
 n colums. Should n be a variable or a symbolic
  parameter?

*/

#include <stdio.h>

#define TABWIDTH 8
#define MAXLENGTH 1000

int getLineLength(char string[], int length);
void detabLine(char tab[], char detab[], int tabWidth);

int main(void) {

    char currentString[MAXLENGTH];
    char detabString[MAXLENGTH];
    int length;
    int spaces;

    while((length = getLineLength(currentString, MAXLENGTH)) > 0) {

        detabLine(currentString, detabString, TABWIDTH);

        printf("\nCurrentString:\n%s", currentString);
        printf("\nDetabString:\n%s", detabString);

    }

}

int getLineLength(char string[], int length) {

    int i;
    int letter;

    for(i = 0; i < length-1 && (letter = getchar()) != EOF && letter != '\n'; ++i) {
        string[i] = letter;
    }
    if(letter == '\n') {
        string[i] = letter;
        ++i;
    }
    string[i] = '\0';
    return i;
}

void detabLine(char tab[], char detab[], int tabWidth) {

    int i;
    int j;
    int spaces;
    int columnCounter;

    spaces = 0;
    j = 0;

    for(i = 0; tab[i] != '\0'; ++i) {
        if(columnCounter >= tabWidth) {
            columnCounter = 0;
        }
        if(tab[i] == ' ') {
            detab[j] = tab[i];
            ++j;
            ++columnCounter;
        } else if(tab[i] == '\t') {
            spaces = tabWidth - columnCounter;
            while(spaces > 0) {
                detab[j] = ' ';
                ++j;
                --spaces;
            }
            columnCounter = 0;
        } else {
            detab[j] = tab[i];
            ++j;
            ++columnCounter;
        }
    }

    if(tab[i] == '\0') {
        detab[j] = '\0';
    }
}
