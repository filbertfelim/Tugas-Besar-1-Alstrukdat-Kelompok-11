#include <stdio.h>
#include "strQueue.h"
#include <stdlib.h>

/* *** Kreator *** */
void CreateStrQueue(strQueue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isQueueEmpty(strQueue q)
{
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isQueueFull(strQueue q)
{
    return (IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY - 1);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthQueue(strQueue q)
{
    if (isQueueEmpty(q))
    {
        return 0;
    }
    else if (isQueueFull(q))
    {
        return CAPACITY;
    }
    else
    {
        if (IDX_HEAD(q) > IDX_TAIL(q))
        {
            return (CAPACITY + ((IDX_TAIL(q) - IDX_HEAD(q)) + 1));
        }
        else
        {
            return ((IDX_TAIL(q) - IDX_HEAD(q)) + 1);
        }
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void STRenqueue(strQueue *q, gamename val)
{
    if (isQueueEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        IDX_TAIL(*q) += 1;
    }
    TAIL(*q) = val;
}

/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void STRdequeue(strQueue *q, gamename val)
{
    val = (*q).buffer[0];
    if (lengthQueue(*q) == 1)
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q) += 1;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void strdisplayQueue(strQueue q)
{
    if (isQueueEmpty(q))
    {
        printf("[]\n");
    }
    else
    {
        printf("[");
        if (IDX_HEAD(q) <= IDX_TAIL(q))
        {
            int i;
            for (i = IDX_HEAD(q); i < IDX_TAIL(q); i++)
            {
                printf("%s,", q.buffer[i]);
            }
            printf("%s]\n", q.buffer[i]);
        }
        else
        {
            int i;
            for (i = IDX_HEAD(q); i < CAPACITY; i++)
            {
                printf("%s,", q.buffer[i]);
            }
            for (i = 0; i < IDX_TAIL(q); i++)
            {
                printf("%s,", q.buffer[i]);
            }
            printf("%s]\n", q.buffer[i]);
        }
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */