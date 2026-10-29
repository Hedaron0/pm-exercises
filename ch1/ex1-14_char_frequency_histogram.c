// Exercise 1-14
// Print a histogram of the frequencies of different characters in the input.

#include <stdio.h>

int main(void)
{
    int c, i, j;
    int count[256];

    for (i = 0; i < 256; ++i) {
        count[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++count[c];
    }

    printf("Character Frequency Histogram:\n");
    for (i = 0; i < 256; ++i) {
        if (count[i] == 0) {
            continue;
        }
        if (i == '\n') {
            printf(" \\n : ");
        }
        else if (i == '\t') {
            printf(" \\t : ");
        }
        else {
            printf("  %c : ", i);
        }
        for (j = 0; j < count[i]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
