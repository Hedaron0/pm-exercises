// Exercise 1-21
// entab: replace strings of blanks by the minimum number of tabs and blanks.
// When a tab or a single blank both reach the tab stop, which one?
// -> the blank, it looks the same and does not depend on the tab width.

#include <stdio.h>

#define TABSTOP 8

int main(void)
{
    int c, col, blanks;

    col = 0;
    blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
            ++col;
            if (col % TABSTOP == 0) { // reached a tab stop
                if (blanks == 1)
                    putchar(' ');
                else
                    putchar('\t');
                blanks = 0;
            }
        }
        else {
            while (blanks > 0) { // blanks that did not reach a tab stop
                putchar(' ');
                --blanks;
            }
            putchar(c);
            if (c == '\n')
                col = 0;
            else if (c == '\t')
                col = col + (TABSTOP - col % TABSTOP);
            else
                ++col;
        }
    }
    return 0;
}
