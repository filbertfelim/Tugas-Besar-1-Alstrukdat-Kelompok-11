#include "creategame.h"
#include <stdio.h>
#include <stdlib.h>

void CreateGame(TabStr *T, TabMap *arr_sb)
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    char *namagame;
    namagame = STARTINPUT();
    namagame = touppercase(namagame);
    boolean exists = false;
    int i = 0;
    while (!exists && i < (*T).Neff)
    {
        if (compare_strings((*T).TI[i], namagame))
        {
            exists = true;
        }
        else
        {
            i++;
        }
    }
    if (exists)
    {
        printf("Game sudah ada di list, silahkan menambahkan game yang lain.\n\n");
    }
    else
    {
        if (!IsFull(*T))
        {
            (*T).TI[(*T).Neff] = namagame;
            (*T).Neff++;
            Map sb;
            CreateEmptyMap(&sb);
            SetElArrayMap(arr_sb, (*arr_sb).NeffArrayMap, sb);
            printf("Game berhasil ditambahkan.\n\n");
        }
        else
        {
            printf("List game telah penuh, silahkan delete game terlebih dahulu untuk menambah game baru.\n\n");
        }
    }
}
/*
    Membuat suatu game dan memasukkannya ke dalam daftar game
*/