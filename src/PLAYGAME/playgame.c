#include "playgame.h"

void Play(strQueue *antrian)
{
    gamename temp;
    int skor;
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
    else if (compare_strings(toPlay, "TICTACTOE"))
    {
        printf("Loading TICTACTOE....\n");
        tictactoe();
    }
    else if (compare_strings(toPlay, "DINOSAUR IN EARTH") || compare_strings(toPlay, "RISEWOMAN") || compare_strings(toPlay, "EIFFEL TOWER"))
    {
        printf("Game %s tidak dapat dimainkan. Silakan pilih game lain.\n", toPlay);
    }
    else
    {
        srand(time(NULL));
        int skor = rand() % 100 + 1;
        printf("Skor : %d\n", skor);
    }
    STRdequeue(antrian, temp);
}
/*Memainkan Game pada urutan teratas*/

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
/*Menampilkan game dalam antrian kemudian memainkan game pada urutan teratas*/