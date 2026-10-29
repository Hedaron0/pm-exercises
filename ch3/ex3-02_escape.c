// Exercise 3-2
// escape(s,t): copy t to s, turning characters like newline and tab into
// visible escape sequences (\n, \t) as they go. Use a switch.
// unescape(s,t): the opposite direction, turning \n and \t back into the
// real characters.

#include <stdio.h>

void escape(char s[], char t[])
{
    int i, j;

    j = 0;
    for (i = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;

    j = 0;
    for (i = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\') {
            switch (t[i + 1]) {
                case 'n':
                    s[j++] = '\n';
                    i++;
                    break;
                case 't':
                    s[j++] = '\t';
                    i++;
                    break;
                case '\\':
                    s[j++] = '\\';
                    i++;
                    break;
                default:
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main(void)
{
    char line[] = "line1\tend\nline2";
    char buf[100];

    escape(buf, line);
    printf("escaped: %s\n", buf);

    unescape(line, buf);
    printf("unescaped: %s\n", line);

    return 0;
}
