#include <stdio.h>
#include <stdlib.h>
#include "start.h"
#include "../ADT/Array/array.h"

static FILE *pita;
static int retval;

void STARTGAME(TabStr *T)
/* I.S. Sembarang
   F.S. Menampilkan tampilan awal permainan
   Proses : Akuisisi file config.txt (config awal)
   START merupakan salah satu command yang dimasukkan pertama kali oleh pemain ke BNMO.
   Setelah menekan Enter, dibaca file konfigurasi default yang berisi list game yang dapat dimainkan.*/
{
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    START();
    int i = GetCC() - '0'; // konversi char ke int
    (*T).Neff = i;
    ADV();
    int idx;
    int j;
    for (j = 0; j < (*T).Neff; j++)
    {
        ADV();
        CopyWord();
        idx = 0;
        char *gamestring;
        gamestring = (char *)malloc(currentWord.Length * sizeof(char));
        for (idx; idx < currentWord.Length; idx++)
        {
            *(gamestring + idx) = currentWord.TabWord[idx];
        }
        *(gamestring + currentWord.Length) = '\0';
        (*T).TI[j] = gamestring;
    }
}

// void ADVGAME()
// {
//     retval = fscanf(pita, "%c", &currentChar);
// }

// void COPYGAME()
// {
//     int i = 0;
//     while ((currentChar != MARK) && (i < NMax))
//     {
//         currentWord.TabWord[i] = currentChar;
//         ADV();
//         i++;
//     }
//     currentWord.Length = i;
// }
