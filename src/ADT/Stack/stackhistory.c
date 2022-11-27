#include <stdio.h>
#include "stackhistory.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackHistory(StackHistory *SH)
{
    TopHistory(*SH) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackHistoryEmpty(StackHistory SH)
{
    return (TopHistory(SH) == Nil);
}

/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackHistoryFull(StackHistory SH)
{
    return (TopHistory(SH) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushHistory(StackHistory *SH, stackhistinfotype X)
{
    TopHistory(*SH) += 1;
    InfoTopHistory(*SH) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopHistory(StackHistory *SH, stackhistinfotype *X)
{
    *X = InfoTopHistory(*SH);
    TopHistory(*SH) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void PrintStackHistory(StackHistory *SH, int n)
{
    int i = 1;
    stackhistinfotype val;
    StackHistory newStack;
    CreateEmptyStackHistory(&newStack);
    newStack = *SH;
    while (i <= n && !IsStackHistoryEmpty(newStack))
    {
        printf("%d. %s\n", i, InfoTopHistory(newStack));
        PopHistory(&newStack, &val);
        i++;
    }
}
/* Menulis seluruh elemen Stack S ke layar */
/* I.S. S mungkin kosong */
/* F.S. Jika S tidak kosong, semua elemen Stack diprint */

int countStackHistory(StackHistory SH)
{
    stackhistinfotype val;
    StackHistory newStack;
    CreateEmptyStackHistory(&newStack);
    newStack = SH;

    int count = 0;
    while (!IsStackHistoryEmpty(newStack))
    {
        PopHistory(&newStack, &val);
        count++;
    }
    return count;
}
/* Mengembalikan banyaknya/jumlah alamat dalam StackHistory SH ke layar */
/* I.S. SH mungkin kosong */
/* F.S. Jika SH tidak kosong, semua elemen StackHistory diprint */
