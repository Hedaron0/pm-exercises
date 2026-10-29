// Exercise 1-6
// Verify that the expression getchar() != EOF is 0 or 1.
// (Ctrl+Z then Enter to send EOF on Windows)

#include <stdio.h>

int main(void)
{
    int c;

    while (1) {
        c = getchar();
        printf("getchar() != EOF is %d\n", c != EOF);
        if (c == EOF)
            break;
    }
    return 0;
}
