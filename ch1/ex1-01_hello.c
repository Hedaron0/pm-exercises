// Exercise 1-1
// Run the "hello, world" program and leave out parts of it to see the errors.
//
// what I got in Visual Studio:
// - without #include <stdio.h> -> warning, 'printf' undefined; assuming extern returning int
// - without ; after printf      -> error C2143 missing ';' before '}'
// - without the closing "       -> error C2001 newline in constant
// - main written as mian        -> linker error, unresolved external symbol main

#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
    return 0;
}
