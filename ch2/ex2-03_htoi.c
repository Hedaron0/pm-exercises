// Exercise 2-3
// Write htoi(s): convert a string of hex digits (with optional 0x or 0X) to an integer.
// returns -1 if there is a character that is not a hex digit

#include <stdio.h>

int htoi(char s[]) {
    int i = 0;
    int n = 0;
    int digit;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9')
            digit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            digit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            digit = s[i] - 'A' + 10;
        else
            return -1;

        n = n * 16 + digit;
        i++;
    }

    return n;
}

int main(void)
{
    printf("1F -> %d\n", htoi("1F"));
    printf("0x1f -> %d\n", htoi("0x1f"));
    printf("0XFF -> %d\n", htoi("0XFF"));
    printf("7a3 -> %d\n", htoi("7a3"));
    printf("0 -> %d\n", htoi("0"));
    printf("12G -> %d\n", htoi("12G"));
    return 0;
}
