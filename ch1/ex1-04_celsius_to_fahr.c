// Exercise 1-4
// Print the Celsius to Fahrenheit table.

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 150;
    step = 10;

    printf("Celsius  Fahr\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * 9.0 / 5.0 + 32.0;
        printf("%7.0f %5.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
