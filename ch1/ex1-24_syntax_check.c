// Exercise 1-24
// Check a C program for basic syntax errors: unbalanced (), [], {}.
// Brackets inside comments, strings and character constants are skipped.
// I used an array as a stack: push ( [ {, and ) ] } must match the last one.
// usage: ex1-24_syntax_check < program.c

#include <stdio.h>

#define MAXSTACK 100

char stack[MAXSTACK];
int top = 0;
int line = 1;
int errors = 0;

void skip_comment(void);
void skip_quote(int quote);
void check_close(int c);

int main(void)
{
    int c, d;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++line;
        }
        else if (c == '/') {
            d = getchar();
            if (d == '*')
                skip_comment();
            else if (d != EOF)
                ungetc(d, stdin); // not a comment, check d again
        }
        else if (c == '"' || c == '\'') {
            skip_quote(c);
        }
        else if (c == '(' || c == '[' || c == '{') {
            if (top < MAXSTACK)
                stack[top++] = c;
        }
        else if (c == ')' || c == ']' || c == '}') {
            check_close(c);
        }
    }

    if (top > 0) {
        printf("%d bracket(s) not closed, last one is '%c'\n", top, stack[top - 1]);
        ++errors;
    }
    if (errors == 0)
        printf("no errors\n");
    else
        printf("%d error(s)\n", errors);
    return 0;
}

void skip_comment(void)
{
    int c, prev;

    prev = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++line;
        if (prev == '*' && c == '/')
            return;
        prev = c;
    }
    printf("comment not closed\n");
    ++errors;
}

void skip_quote(int quote)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\\') {
            getchar(); // skip the escaped character
        }
        else if (c == quote) {
            return;
        }
        else if (c == '\n') {
            printf("line %d: quote not closed\n", line);
            ++line;
            ++errors;
            return;
        }
    }
}

void check_close(int c)
{
    int open;

    if (top == 0) {
        printf("line %d: '%c' without opening\n", line, c);
        ++errors;
        return;
    }
    open = stack[--top];
    if ((open == '(' && c != ')') || (open == '[' && c != ']') || (open == '{' && c != '}')) {
        printf("line %d: '%c' does not match '%c'\n", line, c, open);
        ++errors;
    }
}
