// Exercise 2-1
// Find the ranges of char, short, int and long (signed and unsigned),
// from the standard headers and by direct computation.
// computing: ~0 = all bits 1 = unsigned max, >> 1 = signed max, -max - 1 = signed min

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    unsigned char uc = 0;
    unsigned short us = 0;
    unsigned int ui = 0;
    unsigned long ul = 0;
    long maxl;

    printf("--- from limits.h ---\n");
    printf("signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %u\n", UCHAR_MAX);
    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %u\n", USHRT_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: 0 to %u\n", UINT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);

    uc = ~uc;
    us = ~us;
    ui = ~ui;
    ul = ~ul;
    maxl = ul >> 1;

    printf("--- computed ---\n");
    printf("signed char: %d to %d\n", -(int)(uc >> 1) - 1, uc >> 1);
    printf("unsigned char: 0 to %u\n", uc);
    printf("short: %d to %d\n", -(int)(us >> 1) - 1, us >> 1);
    printf("unsigned short: 0 to %u\n", us);
    printf("int: %d to %d\n", -(int)(ui >> 1) - 1, (int)(ui >> 1));
    printf("unsigned int: 0 to %u\n", ui);
    printf("long: %ld to %ld\n", -maxl - 1, maxl);
    printf("unsigned long: 0 to %lu\n", ul);

    printf("--- float.h ---\n");
    printf("float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double: %e to %e\n", DBL_MIN, DBL_MAX);

    printf("--- sizeof ---\n");
    printf("char %zu, short %zu, int %zu, long %zu, float %zu, double %zu\n",
        sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(float), sizeof(double));
    return 0;
}
