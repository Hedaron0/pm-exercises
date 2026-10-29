// Exercise 3-6
// itoa(n,s,w): convert n to string s, then pad with blanks on the left so
// the result is at least w characters wide (right-justified).

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

void itoa(int n, char s[], int w)
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
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char s[40];

    itoa(42, s, 6);
    printf("[%s]\n", s);

    itoa(-7, s, 5);
    printf("[%s]\n", s);

    itoa(123456, s, 3);
    printf("[%s]\n", s);

    return 0;
}
