// Exercise 3-5
// itob(n,s,b): convert integer n into a base-b string in s (2 <= b <= 16).

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b)
{
    int i, sign, d;
    char digits[] = "0123456789abcdef";

    sign = n;
    if (sign < 0)
        n = -n;          // same INT_MIN caveat as ex3-4, not handled here

    i = 0;
    do {
        d = n % b;
        s[i++] = digits[d];
        n /= b;
    } while (n != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char s[40];

    itob(255, s, 16);
    printf("255 base16 -> %s\n", s);

    itob(10, s, 2);
    printf("10 base2 -> %s\n", s);

    itob(-9, s, 8);
    printf("-9 base8 -> %s\n", s);

    return 0;
}
