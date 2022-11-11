#include "queueDiner.h"

#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi: */
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

boolean IsQueueMember(Queue OrderList, int IDMakanan){
    int i = 0;
    boolean found = false;
    int loc = OrderList.idxHead;
    while (i < length(OrderList) && !found){
        if (OrderList.buffer[loc].makanan == IDMakanan){
            found = true;
        }
        i++;
        loc++;
    }
    return found;
}

int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    if (IDX_HEAD_DINNER(q) <= IDX_TAIL_DINNER(q))
        {
            return (IDX_TAIL_DINNER(q) - IDX_HEAD_DINNER(q) + 1);
        }
        else
        {
            return (CAPACITY_DINNER - (IDX_HEAD_DINNER(q) - IDX_TAIL_DINNER(q)) + 1);
        }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElTypeQueueDiner val)
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
