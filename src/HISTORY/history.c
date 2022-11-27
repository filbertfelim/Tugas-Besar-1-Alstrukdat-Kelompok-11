#include "history.h"
#include <stdio.h>
#include <stdlib.h>

void history(StackHistory *SH, int n)
{
    if (IsStackHistoryEmpty(*SH) || n < 1)
    {
        printf("\nBerikut adalah daftar game terakhir yang dimainkan: \n\n");
    }
    else
    {
        printf("\nBerikut adalah daftar game terakhir yang dimainkan: \n");
        PrintStackHistory(SH, n);
    }
}
/*
    Menampilkan history game yang dimainkan sebanyak n game, jika n melebihi banyak history, maka akan menampilkan semuanya
*/