// Exercise 1-18
// Remove trailing blanks and tabs from each line, and delete entirely blank lines.

#include <stdio.h>

#define MAXLINE 1000

int main(void)
{
    int c, i;
    int len = 0;
    char line[MAXLINE];

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t')) {
                --len;
            }
            if (len > 0) {
                for (i = 0; i < len; ++i) {
                    putchar(line[i]);
                }
                putchar('\n');
            }
            len = 0;
        }
        else {
            if (len < MAXLINE) {
                line[len] = c;
                ++len;
            }
        }
    }

    // last line without '\n'
    while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t')) {
        --len;
    }
    if (len > 0) {
        for (i = 0; i < len; ++i) {
            putchar(line[i]);
        }
        putchar('\n');
    }
    return 0;
}
