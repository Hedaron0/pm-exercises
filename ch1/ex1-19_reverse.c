// Exercise 1-19
// Write a function reverse(s) that reverses the string s.
// Use it to reverse the input a line at a time.

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int maxline);
void reverse(char s[]);

int main(void)
{
    char line[MAXLINE];

    while (mgetline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

void reverse(char s[])
{
    int i, j;
    char temp;

    j = 0;
    while (s[j] != '\0') {
        ++j;
    }
    --j;
    if (j >= 0 && s[j] == '\n') { // keep the newline at the end
        --j;
    }

    i = 0;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i;
        --j;
    }
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
