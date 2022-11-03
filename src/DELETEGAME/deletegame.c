#include "deletegame.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include "../STRINGCOMP/stringcomp.h"
#include "../LISTGAME/listgame.h"
#include <stdio.h>
#include <stdlib.h>

void DeleteGame(TabStr *T)
{
    LISTGAME(T);
    printf("Masukkan nomor game yang akan dihapus: ");
    char *idx_input;
    idx_input = STARTINPUT();
    int idx;
    idx = strtointinput(idx_input, str_len(idx_input));
    if (idx > T->Neff || idx <= 5)
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
