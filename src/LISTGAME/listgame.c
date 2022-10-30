#include <stdio.h>
#include "listgame.h"

void LISTGAME()
/*  Menampilakn daftar game yang tersedia */
{
    printf("Berikut adalah daftar game yang tersedia\n");
    int i = 0;
    for (i; i < game->Neff; i++)
    {
        printf("%d. %s\n", i + 1, game->TI[i]);
    }
}