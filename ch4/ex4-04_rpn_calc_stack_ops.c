// Exercise 4-4
// Same calculator, + commands to look at / mess with the stack:
// p = print top without popping, d = duplicate top, s = swap top two,
// c = clear whole stack.
// Try: 3 4 d * p c  (prints 4, then 12)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'
#define MAXVAL  100
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    int type;
    double op2, tmp;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case 'p':
            if (sp > 0)
                printf("\t%.8g\n", val[sp - 1]);
            else
                printf("error: stack empty\n");
            break;
        case 'd':
            if (sp > 0)
                push(val[sp - 1]);
            else
                printf("error: stack empty\n");
            break;
        case 's':
            if (sp >= 2) {
                tmp = val[sp - 1];
                val[sp - 1] = val[sp - 2];
                val[sp - 2] = tmp;
            } else {
                printf("error: need two values to swap\n");
            }
            break;
        case 'c':
            sp = 0;
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    printf("error: stack empty\n");
    return 0.0;
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i + 1] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

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
