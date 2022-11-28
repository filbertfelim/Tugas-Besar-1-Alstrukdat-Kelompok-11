#include <stdio.h>
#include "displayColor.h"

void reset()
{
    printf("\033[0m");
}

void red()
{
    printf("\033[5;31m");
}

void green()
{
    printf("\033[1;32m");
}

void yellow()
{
    printf("\033[1;33m");
}

void cyan()
{
    printf("\033[1;36m");
}