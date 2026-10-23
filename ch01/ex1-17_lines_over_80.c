// Exercise 1-17
// Print all input lines that are longer than 80 characters.

#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int main(void)
{
    int c, i;
    int len = 0;
    char line[MAXLINE];

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (len > LIMIT) {
                for (i = 0; i < len && i < MAXLINE; ++i) {
                    putchar(line[i]);
                }
                putchar('\n');
            }
            len = 0;
        }
        else {
            if (len < MAXLINE) {
                line[len] = c;
            }
            ++len;
        }
    }

    if (len > LIMIT) {
        for (i = 0; i < len && i < MAXLINE; ++i) {
            putchar(line[i]);
        }
        putchar('\n');
    }
    return 0;
}
