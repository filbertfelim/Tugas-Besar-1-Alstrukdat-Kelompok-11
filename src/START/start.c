#include <stdio.h>
#include <stdlib.h>
#include "start.h"
#include "../ADT/Array/array.h"

static FILE *pita;
static int retval;

void STARTGAME()
/* I.S. Sembarang
   F.S. Menampilkan tampilan awal permainan
   Proses : Akuisisi file config.txt (config awal)
   START merupakan salah satu command yang dimasukkan pertama kali oleh pemain ke BNMO.
   Setelah menekan Enter, dibaca file konfigurasi default yang berisi list game yang dapat dimainkan.*/
{
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    START();
    int i = GetCC() - '0'; // konversi char ke int

    typedef struct
    {
        char *TI[i - 1]; /* memori tempat penyimpan elemen (container) */
        int Neff;        /* banyaknya elemen efektif */
    } TabStr;

    TabStr *game = (TabStr *)malloc((i - 1) * sizeof(TabStr));
    game->Neff = i - 1;

    for (int j = 0; j < game->Neff; j++)
    {
        ADVGAME();
        COPYGAME();
        game->TI[j] = currentWord.TabWord;
    }
}

void ADVGAME()
{
    retval = fscanf(pita, "%c", &currentChar);
}

void COPYGAME()
{
    int i = 0;
    while ((currentChar != MARK) && (i < NMax))
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}
