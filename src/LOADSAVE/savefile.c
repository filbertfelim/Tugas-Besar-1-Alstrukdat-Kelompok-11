#include <stdio.h>
#include <stdlib.h>
#include "savefile.h"

void SAVE(TabStr listgame, StackHistory histgame, TabMap arr_sb, char *file)
{
    FILE *txt;
    char *filename = (char *)malloc(50 * sizeof(char));
    filename = filetodir(file);
    txt = fopen(filename, "w+");
    char *numgame = (char *)malloc(5 * sizeof(char));
    int i;

    // menulis daftar di list game
    sprintf(numgame, "%d", listgame.Neff);
    fprintf(txt, "%s\n", numgame);
    for (i = 0; i < NbElmt(listgame); i++)
    {
        fprintf(txt, "%s\n", listgame.TI[i]);
    }
    // menulis daftar di history game
    sprintf(numgame, "%d", histgame.TOPHISTORY + 1);
    fprintf(txt, "%s\n", numgame);
    for (i = 0; i <= histgame.TOPHISTORY; i++)
    {
        fprintf(txt, "%s\n", histgame.T[i]);
    }

    // menulis daftar scoreboard
    int idxsb;
    for (idxsb = 0; idxsb < arr_sb.NeffArrayMap - 1; idxsb++)
    {
        sprintf(numgame, "%d", arr_sb.TIMap[idxsb].Count);
        fprintf(txt, "%s\n", numgame);
        for (i = 0; i < arr_sb.TIMap[idxsb].Count; i++)
        {
            fprintf(txt, "%s %d\n", arr_sb.TIMap[idxsb].Elements[i].Key, arr_sb.TIMap[idxsb].Elements[i].Value);
        }
    }
    sprintf(numgame, "%d", arr_sb.TIMap[idxsb].Count);
    if (arr_sb.TIMap[idxsb].Count == 0)
    {
        fprintf(txt, "%s", numgame);
    }
    else if (arr_sb.TIMap[idxsb].Count == 1)
    {
        fprintf(txt, "%s\n", numgame);
        fprintf(txt, "%s %d", arr_sb.TIMap[idxsb].Elements[0].Key, arr_sb.TIMap[idxsb].Elements[0].Value);
    }
    else
    {
        fprintf(txt, "%s\n", numgame);
        for (i = 0; i < arr_sb.TIMap[idxsb].Count - 1; i++)
        {
            fprintf(txt, "%s %d\n", arr_sb.TIMap[idxsb].Elements[i].Key, arr_sb.TIMap[idxsb].Elements[i].Value);
        }
        fprintf(txt, "%s %d", arr_sb.TIMap[idxsb].Elements[i].Key, arr_sb.TIMap[idxsb].Elements[i].Value);
    }

    fclose(txt);
    printf("Save file berhasil disimpan.\n");
    free(filename);
    free(numgame);
}
/*
    menyimpan daftar game ke dalam file savefile.txt
*/