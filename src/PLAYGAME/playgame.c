#include "playgame.h"

void Play(strQueue *antrian)
{
    gamename temp;
    char *toPlay = antrian->buffer[antrian->idxHead];
    if (compare_strings(toPlay, "RNG"))
    {
        printf("Loading RNG....\n");
        rng();
    }
    else if (compare_strings(toPlay, "Diner DASH"))
    {
        printf("Loading Diner Dash....\n");
        dinnerdash();
    }
    else
    {
        printf("Game %s tidak dapat dimainkan. Silakan pilih game lain.\n", toPlay);
    }
    STRdequeue(antrian, temp);
}

void PlayGame(strQueue *antrian)
{
    printf("Berikut adalah daftar Game-mu: \n");
    if (!isQueueEmpty(*antrian))
    {
        int i;
        int listNum = 0;
        for (i = antrian->idxHead; i < (antrian->idxHead + lengthQueue(*antrian)); i++)
        {
            printf("%d. %s\n", listNum + 1, antrian->buffer[i]);
            listNum++;
        }
    }
    else
    {
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    if (!isQueueEmpty(*antrian))
    {
        Play(antrian);
    }
    else
    {
        printf("Tidak ada permainan di dalam daftar Game-mu.\n");
    }
}