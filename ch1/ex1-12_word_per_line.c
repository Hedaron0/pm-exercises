// Exercise 1-12
// Print the input one word per line.

#include <stdio.h>

#define IN 1  // inside a word
#define OUT 0 // outside a word

int main(void)
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else {
            putchar(c);
            state = IN;
        }
    }
    return 0;
}
