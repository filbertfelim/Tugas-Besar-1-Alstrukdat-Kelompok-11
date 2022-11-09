#include <stdio.h>
#include <stdlib.h>
#include "savefile.h"

void SAVE(TabStr listgame, char *file)
{
    FILE *txt;
    char *filename = (char *)malloc(50 * sizeof(char));
    filename = filetodir(file);
    txt = fopen(filename, "w+");
    char *numgame = (char *)malloc(5 * sizeof(char));
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
    free(filename);
    free(numgame);
}
/*
    menyimpan daftar game ke dalam file savefile.txt
*/