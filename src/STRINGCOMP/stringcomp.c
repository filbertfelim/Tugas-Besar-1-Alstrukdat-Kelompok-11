#include "stringcomp.h"
#include <stdio.h>
#include "../boolean.h"

int compare_strings(char a[], char b[])
{
    int c = 0;

    while (a[c] == b[c])
    {
        if (a[c] == '\0' || b[c] == '\0')
            break;
        c++;
    }

    if (a[c] == '\0' && b[c] == '\0')
        return true;
    else
        return false;
}