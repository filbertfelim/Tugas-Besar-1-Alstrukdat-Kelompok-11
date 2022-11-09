#include "deletegame.h"
#include <stdio.h>
#include <stdlib.h>

void DeleteGame(TabStr *T, strQueue *GameQueue)
{
    LISTGAME(T);
    printf("Masukkan nomor game yang akan dihapus: ");
    char *idx_input;
    idx_input = STARTINPUT();
    int idx;
    idx = strtointinput(idx_input, str_len(idx_input));
    boolean inqueue;
    inqueue = false;
    int x;
    x = (*GameQueue).idxHead;
    char *gamename;
    while ((x < (*GameQueue).idxHead + lengthQueue(*GameQueue)) && !inqueue)
    {
        if (compare_strings(T->TI[idx - 1], (*GameQueue).buffer[x]))
        {
            inqueue = true;
        }
        x++;
    }
    if (idx > T->Neff || idx <= 5 || inqueue)
    {

        printf("\nGame gagal dihapus\n\n");
    }
    else
    {
        int i;
        for (i = idx - 1; i < T->Neff; i++)
        {
            (*T).TI[i] = (*T).TI[i + 1];
        }
        (*T).Neff -= 1;
        printf("\nGame berhasil dihapus\n\n");
    }
}
/*
    Menghapus game berdasarkan inputan urutan game
*/
