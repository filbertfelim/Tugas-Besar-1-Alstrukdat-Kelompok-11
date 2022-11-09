#include <stdio.h>
#include <stdlib.h>
#include "savefile.h"

void SAVE(TabStr listgame)
{
    FILE *txt;
    txt = fopen("../data/savefile.txt", "w");
    char *numgame;
    int i;
    sprintf(numgame, "%d", listgame.Neff);
    fprintf(txt, "%s\n", numgame);

    for (i = 0; i < NbElmt(listgame) - 1; i++)
    {
        fprintf(txt, "%s\n", listgame.TI[i]);
    }
    fprintf(txt, "%s", listgame.TI[NbElmt(listgame) - 1]);

    fclose(txt);
    printf("Save file berhasil disimpan.\n");
}
/*
    menyimpan daftar game ke dalam file savefile.txt
*/