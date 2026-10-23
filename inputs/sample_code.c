#include <stdio.h>

/* a block comment
   over two lines */
int main(void)
{
    int a = 10 / 2;   // line comment
    char q = '\'';    /* char constant with an escaped quote */
    char s[] = "not /* a comment */ and not // a comment either";
    printf("%d %c %s\n", a, q, s);  /* comment */ printf("done\n");
    return 0;
}
