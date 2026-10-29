// Exercise 1-13
// Print a histogram of the lengths of words in the input.
// Horizontal first, then vertical. One bar per word.

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORDS 100

int main(void)
{
    int c, state, len, nwords, i, row, max;
    int lengths[MAXWORDS];

    state = OUT;
    len = 0;
    nwords = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN && nwords < MAXWORDS) {
                lengths[nwords++] = len;
            }
            state = OUT;
            len = 0;
        }
        else {
            state = IN;
            ++len;
        }
    }
    if (state == IN && nwords < MAXWORDS) {
        lengths[nwords++] = len;
    }

    printf("Horizontal:\n");
    for (i = 0; i < nwords; ++i) {
        for (row = 0; row < lengths[i]; ++row) {
            putchar('*');
        }
        putchar('\n');
    }

    max = 0;
    for (i = 0; i < nwords; ++i) {
        if (lengths[i] > max) {
            max = lengths[i];
        }
    }

    printf("\nVertical:\n");
    for (row = max; row >= 1; --row) {
        for (i = 0; i < nwords; ++i) {
            if (lengths[i] >= row) {
                printf("* ");
            }
            else {
                printf("  ");
            }
        }
        putchar('\n');
    }
    return 0;
}
