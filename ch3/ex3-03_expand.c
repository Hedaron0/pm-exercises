// Exercise 3-3
// expand(s1,s2): expand shorthand like a-z in s1 into the full list abc..z
// in s2. Does not handle leading/trailing '-' as a literal dash, just the
// normal case.

#include <stdio.h>

void expand(char s1[], char s2[])
{
    int i, j, c;

    i = j = 0;
    while (s1[i] != '\0') {
        if (s1[i + 1] == '-' && s1[i + 2] != '\0' && s1[i + 2] > s1[i]) {
            for (c = s1[i]; c <= s1[i + 2]; c++)
                s2[j++] = c;
            i += 3;
        } else {
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0';
}

int main(void)
{
    char out[100];

    expand("a-z", out);
    printf("a-z -> %s\n", out);

    expand("a-z0-9", out);
    printf("a-z0-9 -> %s\n", out);

    expand("abc", out);
    printf("abc -> %s\n", out);

    return 0;
}
