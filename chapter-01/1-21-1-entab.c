/*

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

int getLineLength(char currentLine[], int maxLength);
void entabFunction(char currentLine[], char entabLine[], int tabWidth);



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



int getLineLength(char currentLine[], int maxLength) {

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



void entabFunction(char currentLine[], char entabLine[], int tabWidth) {

    int i, j;
    int spaceWidth;

    j = 0;
    spaceWidth = 0;

    for(i = 0; currentLine[i] != '\n'; ++i) {

        if(currentLine[i] == ' ') {
            ++spaceWidth;
            if(spaceWidth == tabWidth) {
                entabLine[j] = '\t';
                spaceWidth = 0;
                ++j;
            }
        } else if(currentLine[i] == '\t') {
            if(spaceWidth > 0) {
                entabLine[j] = '\t';
                spaceWidth = 0;
                ++j;
            } else {
                entabLine[j] = '\t';
                ++j;
            }
        } else {
            if(spaceWidth > 0) {
                while(spaceWidth > 0) {
                    entabLine[j] = ' ';
                    --spaceWidth;
                    ++j;
                }
            }
            entabLine[j] = currentLine[i];
            spaceWidth = 0;
            ++j;
        }
    }

    if(spaceWidth > 0) {
        while(spaceWidth > 0) {
            entabLine[j] = ' ';
            ++j;
            --spaceWidth;
        }
    }

    if(currentLine[i] == '\n') {
        entabLine[j] = currentLine[i];
        ++j;
    }

    entabLine[j] = '\0';
}
