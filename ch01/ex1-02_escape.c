// Exercise 1-2
// What happens when the printf string contains \c, where c is not a known escape?
//
// result: the compiler gives a warning (unrecognized escape sequence)
// and just prints the character without the backslash. \c -> c

#include <stdio.h>

int main(void)
{
    printf("tab:[\t]\n");
    printf("backslash: \\  quote: \"\n");
    printf("unknown: [\c] [\q]\n");
    return 0;
}
