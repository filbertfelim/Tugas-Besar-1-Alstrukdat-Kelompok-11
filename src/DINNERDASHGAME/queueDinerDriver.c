#include "queueDiner.h"
#include <stdio.h>

void TulisQueue(Queue Q)
{
    int i;
    for (i = IDX_HEAD_DINNER(Q); i < IDX_HEAD_DINNER(Q) + length(Q); i++)
    {
        printf("Makanan: %d, Durasi Masak: %d, Ketahanan: %d, Harga: %d\n", Q.buffer[i].makanan, Q.buffer[i].durasimakanan, Q.buffer[i].ketahanan, Q.buffer[i].harga);
    }
    printf("\n");
}

int main()
{
    Queue antrian;
    CreateQueue(&antrian);
    if (isEmpty(antrian))
    {
        printf("Queue antrian kosong!\n");
    }
    if (isFull(antrian))
    {
        printf("Queue antrian penuh!\n");
    }

    int i;
    for (i = 0; i < 3; i++)
    {
        ElTypeQueueDiner temp;
        temp.makanan = i;
        temp.ketahanan = i + 1;
        temp.harga = i + 10000;
        temp.durasimakanan = i + 1;
        enqueue(&antrian, temp);
    }

    TulisQueue(antrian); // Cek Hasil Enqueue
    if (IsQueueMember(antrian, 1))
    {
        printf("Makanan dengan ID %d ada di dalam antrian!\n");
    }
    else
    {
        printf("Makanan tidak ada dalam antrian!\n");
    }
    printf("Antrian memiliki %d item.\n", length(antrian));
    dequeue(&antrian);
    TulisQueue(antrian); // Cek Hasil Dequeue

    return 0;
}