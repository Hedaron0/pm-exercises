// Exercise 1-23
// Remove all comments from a C program.
// Quoted strings and character constants must stay the same. Comments do not nest.
// usage: ex1-23_remove_comments < program.c

#include <stdio.h>

void skip_comment(void);
void copy_quote(int quote);

int main(void)
{
    int c, d;

    while ((c = getchar()) != EOF) {
        if (c == '/') {
            d = getchar();
            if (d == '*') {
                skip_comment();
            }
            else if (d == '/') { // line comment
                while ((c = getchar()) != EOF && c != '\n')
                    ;
                putchar('\n');
            }
            else {
                putchar(c);
                if (d != EOF)
                    putchar(d);
            }
        }
        else if (c == '"' || c == '\'') {
            copy_quote(c);
        }
        else {
            putchar(c);
        }
    }
    return 0;
}

// read until */
void skip_comment(void)
{
    int c, prev;

    prev = 0;
    while ((c = getchar()) != EOF) {
        if (prev == '*' && c == '/')
            return;
        prev = c;
    }
}

// copy "..." or '...' as it is, \" does not end the string
void copy_quote(int quote)
{
    int c;

    putchar(quote);
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == '\\') {
            c = getchar();
            if (c != EOF)
                putchar(c);
        }
        else if (c == quote) {
            return;
        }
    }
}
