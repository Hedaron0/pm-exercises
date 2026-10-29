// Exercise 1-11
// How would you test the word count program? What inputs are most likely to find bugs?
//
// my test inputs:
// - empty input -> 0 0 0
// - only spaces / tabs / newlines -> 0 words
// - one word without a newline at the end
// - many spaces between two words (should still be 2 words)
// - words separated with tabs
// - "hello,world" -> 1 word, because only space, tab and newline end a word

#include <stdio.h>

#define IN 1  // inside a word
#define OUT 0 // outside a word

int main(void)
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}
