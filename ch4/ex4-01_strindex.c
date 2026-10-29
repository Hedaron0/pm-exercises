// Exercise 4-1
// strindex(s,t): return the position in s of the first occurrence of t,
// or -1 if s does not contain t.

#include <stdio.h>

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (t[k] == '\0')
            return i;
    }
    return -1;
}

int main(void)
{
    printf("%d\n", strindex("hello world", "world"));
    printf("%d\n", strindex("hello world", "bye"));
    printf("%d\n", strindex("aaab", "aab"));
    return 0;
}
