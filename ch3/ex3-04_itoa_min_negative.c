// Exercise 3-4
// Normal itoa negates n to build the digits. That breaks for the most
// negative int (e.g. -2147483648) because -n overflows right back to n.
// Fix: keep n negative and use n % 10 / n / 10 instead, those still work
// fine for negative n.

#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign, d;

    sign = n;
    i = 0;
    do {
        d = n % 10;
        if (d < 0)
            d = -d;
        s[i++] = d + '0';
        n /= 10;
    } while (n != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char s[20];

    itoa(INT_MIN, s);   // old version (negate n first) breaks right here
    printf("%s\n", s);

    itoa(123, s);
    printf("%s\n", s);

    itoa(-45, s);
    printf("%s\n", s);

    return 0;
}
