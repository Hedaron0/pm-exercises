// Exercise 1-8
// Count blanks, tabs, and newlines.

#include <stdio.h>

int main(void)
{
    int c, blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;
    }
    printf("blanks: %d, tabs: %d, newlines: %d\n", blanks, tabs, newlines);
    return 0;
}
