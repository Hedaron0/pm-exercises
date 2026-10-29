// 5.5 Character Pointers and Functions
// strcpy and strcmp written three ways: array index, pointer,
// and the short pointer version from the book.
// Names start with "my" so they don't clash with <string.h>.

#include <stdio.h>

void mystrcpy_array(char *s, char *t);
void mystrcpy_ptr(char *s, char *t);
void mystrcpy_short(char *s, char *t);
int mystrcmp_array(char *s, char *t);
int mystrcmp_ptr(char *s, char *t);

int main(void)
{
    char a[50], b[50], c[50];
    char *p = "now is the time";   // pointer to a string constant
    char amessage[] = "hello";     // array, can be changed

    mystrcpy_array(a, p);
    mystrcpy_ptr(b, p);
    mystrcpy_short(c, amessage);
    printf("%s\n%s\n%s\n", a, b, c);

    printf("cmp(abc, abc) = %d\n", mystrcmp_array("abc", "abc"));
    printf("cmp(abc, abd) = %d\n", mystrcmp_ptr("abc", "abd"));
    printf("cmp(b, a)     = %d\n", mystrcmp_ptr("b", "a"));
    return 0;
}

// copy t to s; array subscript version
void mystrcpy_array(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

// copy t to s; pointer version
void mystrcpy_ptr(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

// copy t to s; short version, '\0' is 0 so the loop stops by itself
void mystrcpy_short(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

// return <0 if s<t, 0 if s==t, >0 if s>t
int mystrcmp_array(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int mystrcmp_ptr(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
