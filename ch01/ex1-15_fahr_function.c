// Exercise 1-15
// Rewrite the temperature conversion program to use a function for conversion.

#include <stdio.h>

float celsius(float fahr);

int main(void)
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, celsius(fahr));
    return 0;
}

float celsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}
