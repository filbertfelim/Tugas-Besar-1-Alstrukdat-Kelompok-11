#include <stdio.h>
#include "stacktower.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackTower(Stackhanoi *S)
{
    TopTower(*S) = Nil;
    for (int i = 0; i < MaxEl; i++)
    {
        (*S).T[i] = 0;
    }
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackTowerEmpty(Stackhanoi S)
{
    return (TopTower(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackTowerFull(Stackhanoi S)
{
    return (TopTower(S) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushTower(Stackhanoi *S, stacktowerinfotype X)
{
    TopTower(*S) += 1;
    InfoTopTower(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopTower(Stackhanoi *S, stacktowerinfotype *X)
{
    *X = InfoTopTower(*S);
    InfoTopTower(*S) = 0;
    TopTower(*S) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

boolean compareStack(Stackhanoi S1, Stackhanoi S2)
{
    if (IsStackTowerEmpty(S1) && IsStackTowerEmpty(S2))
    {
        return true;
    }
    else if (IsStackTowerEmpty(S1) || IsStackTowerEmpty(S2))
    {
        return false;
    }
    else
    {
        stacktowerinfotype X1, X2;
        PopTower(&S1, &X1);
        PopTower(&S2, &X2);
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

int topless(Stackhanoi S)
{
    if (IsStackTowerEmpty(S))
    {
        return 0;
    }
    else
    {
        return InfoTopTower(S);
    }
}
