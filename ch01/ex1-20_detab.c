// Exercise 1-20
// detab: replace tabs with the right number of blanks to the next tab stop.
// Should n be a variable or a symbolic parameter?
// -> symbolic parameter (#define), it does not change while the program runs.

#include <stdio.h>

#define TABSTOP 8

int main(void)
{
    int c, col;

    col = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            do {
                putchar(' ');
                ++col;
            } while (col % TABSTOP != 0);
        }
        else if (c == '\n') {
            putchar(c);
            col = 0;
        }
        else {
            putchar(c);
            ++col;
        }
    }
    return 0;
}
