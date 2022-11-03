#include "../DINNERDASHGAME/queuedinner.h"
#include <stdio.h>
#include <stdlib.h>

#define IDX_UNDEF -1
#define CAPACITY 20
#define HARGA 15000

/* Definisi elemen dan address */
typedef struct {
    int makanan;
    int durasimakanan;
    int ketahanan;
    int harga;
} ElType;

typedef struct {
	ElType buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead].makanan
#define     TAIL(q) (q).buffer[(q).idxTail].makanan

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return (IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY -1);
}
int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (isEmpty(q)) {
        return 0;
    } else {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
{
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    (*q).buffer[IDX_TAIL(*q)].makanan = val.makanan;
    (*q).buffer[IDX_TAIL(*q)].durasimakanan = val.durasimakanan;
    (*q).buffer[IDX_TAIL(*q)].ketahanan = val.ketahanan;
    (*q).buffer[IDX_TAIL(*q)].harga = val.harga;
}
void dequeue(Queue *q)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
{
    if (length(*q) == 1) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}
void displayQueueMakanan(Queue q)
{
    printf("\nDaftar Pesanan\n");
    printf("Makanan\t | Durasi Makanan\t | Ketahanan\t | Harga\n");
    printf("----------------------------------------------------\n");
    int i;
    for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
        printf("%d\t | %d\t\t\t | %d\t\t | %d\n", q.buffer[i].makanan, q.buffer[i].durasimakanan, q.buffer[i].ketahanan, q.buffer[i].harga);
    }
}
void displayQueueCook(Queue q)
{
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan\t | Sisa Durasi Memasak\n");
    printf("--------------------------------\n");
    if (!isEmpty(q)) {
        int i;
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            printf("%d\t | %d\n", q.buffer[i].makanan, q.buffer[i].durasimakanan);
        }
    }
    else {
        printf("\t|\n");
    } 
}
void displayQueueServe(Queue q)
{
    printf("\nDaftar Makanan yang siap disajikan\n");
    printf("Makanan\t | Sisa Durasi Memasak\n");
    printf("--------------------------------\n");
    if (!isEmpty(q)) {
        int i;
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            if (q.buffer[i].durasimakanan == 0) {
                printf("%d\t | %d\n", q.buffer[i].makanan, q.buffer[i].durasimakanan);
            }
        }
    }
}
