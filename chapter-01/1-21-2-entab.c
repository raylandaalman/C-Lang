/*

First not-fully-working solution

Write a program 'entab' that replaces strings
 of blanks by the minimum number of tabs and
  blanks to achieve the same spacing.

Use the same tab stops as for 'detab'.

When either a tab or a single blank would suffice
 to reach a tab stop, which should be given
  preference?

*/

#include <stdio.h>

#define MAXLENGTH 1000
#define TABWIDTH 8

int getLineLength(char currentLine[MAXLENGTH], int maxLength);
void entabFunction(char currentLine[MAXLENGTH], char entabLine[MAXLENGTH], int tabWidth);
int addRemainingSpaces(char entabLine[MAXLENGTH], int tabWidth, int remainingSpaces, int j);


int main(void) {

int letter;
int length;

char currentLine[MAXLENGTH];
char entabLine[MAXLENGTH];

    while((length = getLineLength(currentLine, MAXLENGTH)) > 0) {
        entabFunction(currentLine, entabLine, TABWIDTH);

        printf("\nCurrent Line:\n%s", currentLine);
        printf("\nEntab   Line:\n%s\n", entabLine);
    }

}

int getLineLength(char currentLine[MAXLENGTH], int maxLength) {

    int i;
    int letter;

    for(i = 0; i < MAXLENGTH - 1 && (letter = getchar()) != EOF && letter != '\n'; ++i) {
        currentLine[i] = letter;
    }

    if (letter == '\n') {
        currentLine[i] = letter;
        ++i;
    }

    currentLine[i] = '\0';
    return i;

}

void entabFunction(char currentLine[MAXLENGTH], char entabLine[MAXLENGTH], int tabWidth) {

    int i, j;
    int sequentialSpaces;
    int columnLocation;
    int remainingSpaces;

    sequentialSpaces = j = 0;

    for(i = 0; currentLine[i] != '\n'; ++i) {
        ++columnLocation;

        if(columnLocation == tabWidth) {
            columnLocation = 0;
        }

        if(currentLine[i] == ' ') {
            ++sequentialSpaces;
        }

        if(sequentialSpaces == tabWidth) {
            entabLine[j] = '\t';
            sequentialSpaces = 0;
            ++j;
        }

        if(currentLine[i] == '\t') {

            if(sequentialSpaces != 0) {
                j = addRemainingSpaces(entabLine, tabWidth, sequentialSpaces, j);
            } else {
                entabLine[j] = '\t';
                ++j;
            }
        }

        if(currentLine[i] != ' ' && currentLine[i] != '\t') {
            if(sequentialSpaces != 0) {
                j = addRemainingSpaces(entabLine, tabWidth, sequentialSpaces, j);
            }

            entabLine[j] = currentLine[i];
            ++j;
            sequentialSpaces = 0;
        }
    }


    if(sequentialSpaces != 0) {
        j = addRemainingSpaces(entabLine, tabWidth, sequentialSpaces, j);
    }

    if(currentLine[i] == '\n') {
        entabLine[j] == '\n';
        ++j;
    }
    entabLine[j] = '\0';
    sequentialSpaces = 0;
}

int addRemainingSpaces(char entabLine[MAXLENGTH], int tabWidth, int remainingSpaces, int j) {


    while(remainingSpaces > 0) {
        entabLine[j] = ' ';
        --remainingSpaces;
        ++j;
    }

    return j;
}
