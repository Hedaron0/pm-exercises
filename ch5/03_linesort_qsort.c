// 5.6 Pointer Arrays; Pointers to Pointers
// Sort input lines. Lines are kept in one big buffer (alloc from 5.4)
// and lineptr[] holds a pointer to each line, so qsort only swaps
// pointers, not the lines themselves.
// Run: 03_linesort_qsort < ..\inputs\sample.txt

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   // max number of lines
#define MAXLEN 1000     // max length of one line
#define ALLOCSIZE 10000 // size of the line buffer

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *v[], int left, int right);
void swap(char *v[], int i, int j);
int mgetline(char *s, int lim);
char *alloc(int n);

int main(void)
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mgetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        if (line[len - 1] == '\n')
            line[len - 1] = '\0';   // delete newline
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

// sort v[left]...v[right] into increasing order
void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)   // fewer than two elements
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

// swap two pointers, the strings stay where they are
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int mgetline(char *s, int lim)
{
    int c;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;   // next free position

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n + 1) {   // +1 for the '\0'
        allocp += n + 1;
        return allocp - n - 1;
    } else
        return NULL;
}
