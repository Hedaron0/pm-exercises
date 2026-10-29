// Exercise 4-2
// Extend atof to handle scientific notation, like 1.5e-3 or 2E6.

#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
    double val, power;
    int i, sign, exp, esign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        esign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
        while (exp-- > 0)
            val = (esign == 1) ? val * 10.0 : val / 10.0;
    }

    return val;
}

int main(void)
{
    printf("%g\n", atof("1.5e-3"));
    printf("%g\n", atof("2E6"));
    printf("%g\n", atof("-3.25"));
    return 0;
}
