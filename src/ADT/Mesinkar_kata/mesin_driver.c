#include <stdio.h>
#include "mesin_kata.h"
#include "../../START/start.h"

// membaca file konfigurasi
int main()
{
    STARTWORD();
    while (!EndWord)
    {
        for (int i = 0; i < currentWord.Length; i++)
        {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");
        ADVWORD();
    }
    return 0;
}