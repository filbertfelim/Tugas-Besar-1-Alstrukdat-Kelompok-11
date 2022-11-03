#include "skipgame.h"

void SkipGame(strQueue *GameQueue, int n)
{
    // Menampilkan antrian Game
    printf("Berikut adalah daftar Game-mu: \n");
    if (!isQueueEmpty(*GameQueue))
    {
        int i;
        for (i = 0; i < lengthQueue(*GameQueue); i++)
        {
            printf("%d. %s\n", i + 1, GameQueue->buffer[i]);
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
        Play(GameQueue);
    }
    else
    {
        printf("Tidak ada permainan di dalam daftar Game-mu.\n");
    }
}