#include "skipgame.h"

void SkipGame(strQueue *GameQueue, TabStr listgame, TabMap *arr_sb, int n, StackHistory *stackhist)
{
    // Menampilkan antrian Game
    printf("Berikut adalah daftar Game-mu: \n");
    if (!isQueueEmpty(*GameQueue))
    {
        int i;
        int listNum = 0;
        for (i = GameQueue->idxHead; i < (GameQueue->idxHead + lengthQueue(*GameQueue)); i++)
        {
            printf("%d. %s\n", listNum + 1, GameQueue->buffer[i]);
            listNum++;
        }
    }
    else
    {
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    // Proses Skip dengan dequeue dan play game setelah dequeue
    char *tempDequeue;
    int i;
    for (i = 0; i < n; i++)
    {
        if (!isQueueEmpty(*GameQueue))
        {
            STRdequeue(GameQueue, tempDequeue);
        }
    }

    if (!isQueueEmpty(*GameQueue))
    {
        Play(GameQueue, listgame, arr_sb, stackhist);
    }
    else
    {
        printf("Tidak ada permainan di dalam daftar Game-mu.\n");
    }
}
/*
Melewatkan game sebanyak n kali, lalu memainkan game
*/