// Exercise 1-10
// Copy input to output, replacing each tab by \t, each backspace by \b
// and each backslash by \.

#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
    return 0;
}
