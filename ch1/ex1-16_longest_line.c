// Exercise 1-16
// Change the longest line program so it prints the correct length of
// arbitrarily long lines, and as much of the text as possible.
// If the line did not fit in the array, keep reading and counting until '\n'.

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int c, len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    longest[0] = '\0';
    while ((len = mgetline(line, MAXLINE)) > 0) {
        if (line[len - 1] != '\n') {
            while ((c = getchar()) != EOF) {
                ++len;
                if (c == '\n') {
                    break;
                }
            }
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("Length: %d\n", max);
        printf("Text: %s", longest);
        putchar('\n');
    }
    return 0;
}

int mgetline(char line[], int maxline)
{
    int c = 0;
    int i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
