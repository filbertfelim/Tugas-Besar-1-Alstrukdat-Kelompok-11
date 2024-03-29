#include <stdio.h>
#include <stdlib.h>
#include "start.h"

static FILE *pita;
static int retval;

void STARTGAME(TabStr *T, TabMap *arr_sb)
/* I.S. Sembarang
   F.S. Menampilkan tampilan awal permainan
   Proses : Akuisisi file config.txt (config awal)
   START merupakan salah satu command yang dimasukkan pertama kali oleh pemain ke BNMO.
   Setelah menekan Enter, dibaca file konfigurasi default yang berisi list game yang dapat dimainkan.*/
{
    MakeEmpty(T);
    START();
    CopyWord();
    int i = strtoint(currentWord.TabWord); // konversi char ke int
    (*T).Neff = i;
    int idx;
    int j;
    for (j = 0; j < (*T).Neff; j++)
    {
        ADV();
        CopyWord();
        char *gamestring;
        gamestring = (char *)malloc(currentWord.Length * sizeof(char));
        for (idx = 0; idx < currentWord.Length; idx++)
        {
            *(gamestring + idx) = currentWord.TabWord[idx];
        }
        *(gamestring + currentWord.Length) = '\0';
        (*T).TI[j] = gamestring;
    }

    Map SB;
    int banyaksb;
    for (banyaksb = 0; banyaksb < (*T).Neff; banyaksb++)
    {
        CreateEmptyMap(&SB);
        SetElArrayMap(arr_sb, banyaksb, SB);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
}
