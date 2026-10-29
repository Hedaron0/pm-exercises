// Exercise 1-22
// Fold long input lines after the last blank before column n.
// If there is no blank before column n, the word is cut at column n.

#include <stdio.h>

#define MAXCOL 40

int main(void)
{
    char line[MAXCOL];
    int c, pos, i, j, lastblank;

    pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            for (i = 0; i < pos; ++i)
                putchar(line[i]);
            putchar('\n');
            pos = 0;
        }
        else {
            line[pos++] = c;
            if (pos == MAXCOL) {
                lastblank = -1;
                for (i = pos - 1; i >= 0; --i) {
                    if (line[i] == ' ' || line[i] == '\t') {
                        lastblank = i;
                        break;
                    }
                }

                if (lastblank == -1) { // no blank, cut the long word
                    for (i = 0; i < pos; ++i)
                        putchar(line[i]);
                    putchar('\n');
                    pos = 0;
                }
                else {
                    for (i = 0; i < lastblank; ++i)
                        putchar(line[i]);
                    putchar('\n');
                    // move the rest of the word to the start
                    j = 0;
                    for (i = lastblank + 1; i < pos; ++i)
                        line[j++] = line[i];
                    pos = j;
                }
            }
        }
    }
    if (pos > 0) {
        for (i = 0; i < pos; ++i)
            putchar(line[i]);
        putchar('\n');
    }
    return 0;
}
