#include "../DINNERDASHGAME/queuedinner.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD_DINNER(*q) = IDX_UNDEF;
    IDX_TAIL_DINNER(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return (IDX_HEAD_DINNER(q) == IDX_UNDEF && IDX_TAIL_DINNER(q) == IDX_UNDEF);
}
boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return (IDX_TAIL_DINNER(q) - IDX_HEAD_DINNER(q) == CAPACITY_DINNER - 1);
}
int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL_DINNER(q) - IDX_HEAD_DINNER(q) + 1);
    }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, x val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
{
    if (isEmpty(*q))
    {
        IDX_HEAD_DINNER(*q) = 0;
        IDX_TAIL_DINNER(*q) = 0;
    }
    else
    {
        IDX_TAIL_DINNER(*q) = (IDX_TAIL_DINNER(*q) + 1) % CAPACITY_DINNER;
    }
    (*q).buffer[IDX_TAIL_DINNER(*q)].makanan = val.makanan;
    (*q).buffer[IDX_TAIL_DINNER(*q)].durasimakanan = val.durasimakanan;
    (*q).buffer[IDX_TAIL_DINNER(*q)].ketahanan = val.ketahanan;
    (*q).buffer[IDX_TAIL_DINNER(*q)].harga = val.harga;
}
void dequeue(Queue *q)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
{
    if (length(*q) == 1)
    {
        IDX_HEAD_DINNER(*q) = IDX_UNDEF;
        IDX_TAIL_DINNER(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD_DINNER(*q) = (IDX_HEAD_DINNER(*q) + 1) % CAPACITY_DINNER;
    }
}
void displayQueueMakanan(Queue q)
{
    printf("\nDaftar Pesanan\n");
    printf("Makanan\t | Durasi Makanan\t | Ketahanan\t | Harga\n");
    printf("----------------------------------------------------\n");
    int i;
    for (i = IDX_HEAD_DINNER(q); i <= IDX_TAIL_DINNER(q); i++)
    {
        printf("M%d\t | %d\t\t\t | %d\t\t | %d\n", q.buffer[i].makanan, q.buffer[i].durasimakanan, q.buffer[i].ketahanan, q.buffer[i].harga);
    }
}
void displayQueueCook(Queue q)
{
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan\t | Sisa Durasi Memasak\n");
    printf("--------------------------------\n");
    if (!isEmpty(q))
    {
        int i;
        for (i = IDX_HEAD_DINNER(q); i <= IDX_TAIL_DINNER(q); i++)
        {
            printf("M%d\t | %d\n", q.buffer[i].makanan, q.buffer[i].durasimakanan);
        }
    }
    else
    {
        printf("\t|\n");
    }
}
void displayQueueServe(Queue q)
{
    printf("\nDaftar Makanan yang siap disajikan\n");
    printf("Makanan\t | Sisa ketahanan makanan\n");
    printf("--------------------------------\n");
    if (!isEmpty(q))
    {
        int i;
        for (i = IDX_HEAD_DINNER(q); i <= IDX_TAIL_DINNER(q); i++)
        {
            printf("M%d\t | %d\n", q.buffer[i].makanan, q.buffer[i].durasimakanan);
        }
    }
    else
    {
        printf("\t|\n");
    }
}