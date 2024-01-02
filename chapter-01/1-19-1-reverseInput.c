#include <stdio.h>

#define MAXLENGTH 1000

int getLineLength(char currentLine[], int maxLength);
void reverseCurrentLine(char from[], char to[]);
void removeLeadingBlanks(char array[]);
void removeTrailingBlanks(char array[]);

int main(void) {

    char currentLine[MAXLENGTH];
    char reverseLine[MAXLENGTH];
    int length, i;

    while(length = (getLineLength(currentLine, MAXLENGTH)) > 0) {
        //if(currentLine[0] != '\n') {
        //    printf("Current String: %s", currentLine);
        //}

        removeLeadingBlanks(currentLine);
        removeTrailingBlanks(currentLine);
        reverseCurrentLine(currentLine, reverseLine);

        //if(currentLine[0] != '\n') {
        //    printf("\nCurrent String: %s", currentLine);
        //    printf("%s", currentLine);
        //}
        if(reverseLine[0] != '\n') {
            //printf("Reverse String: %s", reverseLine);
            printf("%s", reverseLine);
        }
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
        i++;
    }
    currentLine[i] = '\0';

    return i;
}


void removeLeadingBlanks(char array[]) {

    int i, j;

    for(i = 0; array[i] == ' ' || array[i] == '\t'; ++i) {
        ;
    }

    j = 0;
    if(i == 0) {
        return;
    } else {
        while(array[i] != '\n') {
            array[j] = array[i];
            ++j;
            ++i;
            //printf("\nArray: %s", array);
        }
        if(array[i] == '\n') {
            array[j] = '\n';
            array[j+1] = '\0';
            //printf("\nArray: %s", array);
        }
    }
}

void removeTrailingBlanks(char array[]) {

    int i;

    for(i = 0; array[i] != '\0'; ++i) {
        ;
    }
    i = i - 2;
    //printf("\nValue of trailing blanks i: %d\n", i);

    while(array[i] == ' ' || array[i] == '\t') {
        --i;
    }
    //printf("\nValue of trailing blanks i: %d\n", i);
    array[i+1] = '\n';
    array[i+2] = '\0';
}

void reverseCurrentLine(char from[], char to[]) {

    int i, j;

    if(from[0] != '\n') {

        for(i = 0; from[i] != '\0'; ++i) {
            ;
        }

        i = i - 2;
        j = 0;

        for(i; i >= 0 ; --i) {
            to[j] = from[i];
            ++j;
        }

        to[j] = '\n';
        to[j+1] = '\0';

    } else {
        to[0] = '\n';
        to[1] = '\0';
    }
}
