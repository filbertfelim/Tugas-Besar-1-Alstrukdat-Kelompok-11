#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
{
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S)
{
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(Stack S)
{
    return (Top(S) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, stackinfotype X)
{
    Top(*S) += 1;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, stackinfotype *X)
{
    *X = InfoTop(*S);
    Top(*S) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

boolean compareStack(Stack S1, Stack S2)
{
    if (IsStackEmpty(S1) && IsStackEmpty(S2))
    {
        return true;
    }
    else if (IsStackEmpty(S1) || IsStackEmpty(S2))
    {
        return false;
    }
    else
    {
        stackinfotype X1, X2;
        Pop(&S1, &X1);
        Pop(&S2, &X2);
        if (X1 != X2)
        {
            return false;
        }
        else
        {
            return compareStack(S1, S2);
        }
    }
}
