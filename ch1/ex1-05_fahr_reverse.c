// Exercise 1-5
// Print the temperature table in reverse order, from 300 degrees to 0.

#include <stdio.h>

void translate(void) {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;
    while (fahr >= lower) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr - step;
    }
}

// same thing with for (from the book)
void translate_for(void) {
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}

int main(void)
{
    translate();
    printf("\n");
    translate_for();
    return 0;
}
