#include "creategame.h"
#include <stdio.h>
#include <stdlib.h>

void CreateGame(TabStr *T)
{
    char *x;
    scanf("%s", &x);
    if (!IsFull(*T))
    {
        (*T).TI[(*T).Neff] = x;
        (*T).Neff++;
        printf("Game berhasil ditambahkan");
    }
}