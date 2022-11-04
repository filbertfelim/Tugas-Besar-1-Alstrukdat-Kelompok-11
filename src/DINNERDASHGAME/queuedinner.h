#ifndef QUEUEDINNER_H
#define QUEUEDINNER_H

#include "../boolean.h"

#define IDX_UNDEF -1
#define CAPACITY_DINNER 20
#define HARGA 15000

/* Definisi elemen dan address */
typedef struct
{
    int makanan;
    int durasimakanan;
    int ketahanan;
    int harga;
} x;

typedef struct
{
    x buffer[CAPACITY_DINNER];
    int idxHead;
    int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD_DINNER(q) (q).idxHead
#define IDX_TAIL_DINNER(q) (q).idxTail
#define HEAD_DINNER(q) (q).buffer[(q).idxHead].makanan
#define TAIL_DINNER(q) (q).buffer[(q).idxTail].makanan

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, x val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueueMakanan(Queue q);

void displayQueueCook(Queue q);

void displayQueueServe(Queue q);

#endif
