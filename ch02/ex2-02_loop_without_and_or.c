// Exercise 2-2
// Write a loop equivalent to this for loop without using && or ||:
//
//   for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
//       s[i] = c;
//
// the checks are done in the same order, so getchar() is not called when the array is full

#include <stdio.h>

#define MAXLINE 1000

int main(void)
{
    char s[MAXLINE];
    int i, c;
    int lim = MAXLINE;

    i = 0;
    while (i < lim - 1) {
        c = getchar();
        if (c == '\n')
            break;
        if (c == EOF)
            break;
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    printf("read %d characters: %s\n", i, s);
    return 0;
}
