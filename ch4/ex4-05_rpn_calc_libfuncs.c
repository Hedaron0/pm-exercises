// Exercise 4-5
// Same calculator, + access to library math functions (sin, cos, exp),
// table-driven so adding one more is just one more table row. pow needs
// two values off the stack so it's handled separately.
// Try: 2 pow (needs two numbers first), or: 1 sin

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP   100
#define NUMBER  '0'
#define NAME    300
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

struct {
    char *name;
    double (*fn)(double);
} funcs[] = {
    { "sin", sin },
    { "cos", cos },
    { "exp", exp },
    { NULL, NULL }
};

int main(void)
{
    int type, i, found;
    double op2;
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
        case NAME:
            if (strcmp(s, "pow") == 0) {
                op2 = pop();
                push(pow(pop(), op2));
                break;
            }
            found = 0;
            for (i = 0; funcs[i].name != NULL; i++) {
                if (strcmp(s, funcs[i].name) == 0) {
                    push(funcs[i].fn(pop()));
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("error: unknown function %s\n", s);
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

    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return NAME;
    }

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
