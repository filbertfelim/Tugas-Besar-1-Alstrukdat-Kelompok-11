#include <stdio.h>
#include <stdlib.h>
#include "scoreboard.h"

void scoreboard(TabMap arr_sb, TabStr listgame)
{
    int idxgame, idxname;
    int namelen_max, namelen;
    int scorelen_max, scorelen;
    char *str_score = (char *)malloc(10 * sizeof(char));

    for (idxgame = 0; idxgame < arr_sb.NeffArrayMap; idxgame++)
    {
        if (arr_sb.TIMap[idxgame].Count == 0)
        {
            printf("**** SCOREBOARD GAME %s ****\n", listgame.TI[idxgame]);
            printf("| NAMA\t\t| SKOR\t  |\n");
            printf("---- SCOREBOARD KOSONG ----\n");
        }
        else
        {
            // mengecek panjang max dari nama dan skor tiap scoreboard untuk printing
            sprintf(str_score, "%d", arr_sb.TIMap[idxgame].Elements[0].Value);
            scorelen_max = str_len(str_score);
            namelen_max = str_len(arr_sb.TIMap[idxgame].Elements[0].Key);
            for (idxname = 1; idxname < arr_sb.TIMap[idxgame].Count; idxname++)
            {
                sprintf(str_score, "%d", arr_sb.TIMap[idxgame].Elements[idxname].Value);
                if (str_len(str_score) > scorelen_max)
                {
                    scorelen_max = str_len(str_score);
                }
                if (str_len(arr_sb.TIMap[idxgame].Elements[idxname].Key) > namelen_max)
                {
                    namelen_max = str_len(arr_sb.TIMap[idxgame].Elements[idxname].Key);
                }
            }
            printf("**** SCOREBOARD GAME %s ****\n", listgame.TI[idxgame]);
            printf("| NAMA");
            printf("%*s", namelen_max - 4 + 1, "");
            printf("| SKOR");
            if (scorelen_max < 4)
            {
                printf("%*s", 1, "");
                scorelen_max = 4;
            }
            else
            {
                printf("%*s", scorelen_max - 4 + 1, "");
            }
            printf("|\n");
            for (idxname = 0; idxname < arr_sb.TIMap[idxgame].Count; idxname++)
            {
                namelen = str_len(arr_sb.TIMap[idxgame].Elements[idxname].Key);
                sprintf(str_score, "%d", arr_sb.TIMap[idxgame].Elements[idxname].Value);
                scorelen = str_len(str_score);
                printf("| %s", arr_sb.TIMap[idxgame].Elements[idxname].Key);
                printf("%*s", namelen_max - namelen + 1, "");
                printf("| %d", arr_sb.TIMap[idxgame].Elements[idxname].Value);
                printf("%*s", scorelen_max - scorelen + 1, "");
                printf("|\n");
            }
        }
        printf("\n");
    }
}
/*
    Menampilkan scoreboard dari semua game di list game
*/

void resetscoreboard(TabStr listgame, TabMap *arr_sb)
{
    char *numinput;
    char *strinput;
    int nomorGame;
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    int i;
    for (i = 0; i < listgame.Neff; i++)
    {
        printf("%d. %s\n", i + 1, listgame.TI[i]);
    }
    printf("\n");
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    numinput = STARTINPUT();
    nomorGame = strtointinput(numinput, str_len(numinput));
    printf("\n");
    while (nomorGame > listgame.Neff)
    {
        printf("Angka yang dimasukkan tidak valid!\n");
        printf("SCOREBOARD YANG INGIN DIHAPUS: ");
        numinput = STARTINPUT();
        nomorGame = strtointinput(numinput, str_len(numinput));
        printf("\n");
    }
    if (nomorGame == 0)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
    }
    else
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ", listgame.TI[nomorGame - 1]);
    }
    strinput = STARTINPUT();
    while (!compare_strings(strinput, "YA") && !compare_strings(strinput, "TIDAK"))
    {
        printf("Input tidak valid!\n\n");
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
        strinput = STARTINPUT();
    }
    if (compare_strings(strinput, "YA"))
    {
        if (nomorGame == 0)
        {
            int idx;
            for (idx = 0; idx < (*arr_sb).NeffArrayMap; idx++)
            {
                CreateEmptyMap(&(*arr_sb).TIMap[idx]);
            }
        }
        else
        {
            CreateEmptyMap(&(*arr_sb).TIMap[nomorGame - 1]);
        }
        printf("Scoreboard berhasil di-reset.\n\n");
    }
    else
    {
        printf("Scoreboard tidak di-reset.\n\n");
    }
}