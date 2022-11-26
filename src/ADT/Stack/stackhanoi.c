#include <stdio.h>
#include "stackhanoi.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackH(Stack *S)
{
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmptyH(Stack S)
{
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFullH(Stack S)
{
    return (Top(S) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushH(Stack *S, stackinfotype X, int el)
{
    Top(*S) += 1;
    InfoTop(*S).tower = X;
    InfoTop(*S).elhanoi = el;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopH(Stack *S, stackinfotype *X)
{
    X(*tower) = InfoTop(*S).tower;
    X(*elhanoi) = InfoTop(*S).elhanoi;
    InfoTop(*S).tower = "   |   ";
    InfoTop(*S).elhanoi = 6;
    Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

/* ************ Operasi Tambahan ************ */
boolean IsStackEqual(Stack S1, Stack S2)
/* Mengirim true jika S1 sama dengan S2 yaitu jika S1 dan S2 memiliki elemen yang sama dan urutan yang sama */
{
    if (S1.tower != S2.tower)
    {
        return false;
    }
    else
    {
        int i = 0;
        boolean found = false;
        while (i < MaxElHanoi && !found)
        {
            if (S1.tower[i] != S2.tower[i])
            {
                found = true;
            }
            else
            {
                i++;
            }
        }
        return !found;
    }
}
