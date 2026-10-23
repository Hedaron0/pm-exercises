// Exercise 1-9
// Copy input to output, replacing each string of one or more blanks by a single blank.

#include <stdio.h>

int main(void)
{
    int c;
    int previousBlank = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (previousBlank == 0) {
                putchar(c);
                previousBlank = 1;
            }
        }
        else {
            putchar(c);
            previousBlank = 0;
        }
    }
    return 0;
}
