#include <stdio.h>

int main(void) {

    int c;

    c = getchar() != EOF;
    printf("Evaluating c != EOF | c is: %d\n", c);

    c = getchar() == EOF;
    printf("Evaluation c == EOF | c is: %d\n", c);
}
