#include <stdio.h>
#include <stdlib.h>
#include "start.h"


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
    COPYGAME();
    int i = GetCC() - '0';
    typedef struct{
    char TI*[i-1]; /* memori tempat penyimpan elemen (container) */
    } TabStr;
    TabStr *game = (TabStr *) malloc(sizeof(TabStr));
    for (int j = 0; j < i; j++)
    {
        ADVGAME();
        COPYGAME();
        game->TI[j] = (char *) malloc(sizeof(char) * (CKata.Length + 1));
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
        currentWord.TabKata[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}