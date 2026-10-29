// 5.2 Pointers and Function Arguments
// C passes arguments by value, so swap(a, b) can't change a and b.
// We pass their addresses instead: swap(&a, &b).
// getint uses the same idea: it returns EOF/0/positive as status and
// puts the number it read into *pn.

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 10

void swap(int *px, int *py);
int getint(int *pn);
int getch(void);
void ungetch(int c);

int main(void)
{
    int a = 3, b = 7;
    int n, array[SIZE];
    int i, r;

    printf("before swap: a=%d b=%d\n", a, b);
    swap(&a, &b);
    printf("after swap:  a=%d b=%d\n", a, b);

    // read integers from input into the array
    // stop at EOF or at something that is not a number (getint returns 0)
    for (n = 0; n < SIZE && (r = getint(&array[n])) != EOF && r != 0; n++)
        ;
    for (i = 0; i < n; i++)
        printf("array[%d] = %d\n", i, array[i]);
    return 0;
}

void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

// getint: get next integer from input into *pn
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))   // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);   // it's not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

char buf[BUFSIZE];   // buffer for ungetch
int bufp = 0;        // next free position in buf

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
