#include "arrayDiner.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create array kosong */
void MakeEmptyArray(arrayDiner *T)
{
    T->Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk array T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray(arrayDiner T)
{
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif array */
/* Mengirimkan nol jika array kosong */
/* *** Daya tampung container *** */
int MaxNbElArray(arrayDiner T)
{
    return (IdxMax - IdxMin + 1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh array */
/* *** Selektor INDEKS *** */
IdxType GetFirstDinerIdx(arrayDiner T)
{
    return IdxMin;
}
/* Prekondisi : array T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastDinerIdx(arrayDiner T)
{
    return NbElmtArray(T);
}
/* Prekondisi : array T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElTypeArrayDiner GetArrayElmt(arrayDiner T, IdxType i)
{
    return T.TI[i];
}
/* Prekondisi : array tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen array yang ke-i */

/* *** Selektor SET : Mengubah nilai array dan elemen array *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetArray(arrayDiner Tin, arrayDiner *Tout)
{
    (*Tout).Neff = Tin.Neff;
    int i;
    for (i = IdxMin; i <= IdxMax; i++)
    {
        (*Tout).TI[i] = Tin.TI[i];
    }
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetElArray(arrayDiner *T, IdxType i, ElTypeArrayDiner v)
{
    (*T).TI[i] = v;
    if (i == GetLastDinerIdx(*T) + 1)
    {
        (*T).Neff++;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen array yang ke-i sehingga bernilai v */
void SetNeffArray(arrayDiner *T, IdxType N)
{
    (*T).Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

void DeleteEl(arrayDiner *T, int idx)
{
    int i;
    for (i = idx; i <= NbElmtArray(*T); i++)
    {
        (*T).TI[i] = (*T).TI[i + 1];
    }
    ((*T).Neff)--;
}
/* I.S. T terdefinisi dan tidak kosong*/
/* F.S. Elemen T di posisi idx terhapus*/

/* ********** Test Indeks yang valid ********** */
boolean IsArrayIdxValid(arrayDiner T, IdxType i)
{
    return ((i >= IdxMin) && (i <= IdxMax));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran array */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsArrayIdxEff(arrayDiner T, IdxType i)
{
    return ((i >= GetFirstDinerIdx(T)) && (i <= GetLastDinerIdx(T)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk array */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test array kosong *** */
boolean IsArrayEmpty(arrayDiner T)
{
    return (NbElmtArray(T) == 0);
}
/* Mengirimkan true jika array T kosong, mengirimkan false jika tidak */
/* *** Test array penuh *** */
boolean IsArrayFull(arrayDiner T)
{
    return (NbElmtArray(T) == MaxNbElArray(T));
}
/* Mengirimkan true jika array T penuh, mengirimkan false jika tidak */

/* ********** SEARCH ********** */
boolean IsInArray(arrayDiner T, int ID)
{
    int i = GetFirstDinerIdx(T);
    boolean found = false;
    while (i <= GetLastDinerIdx(T) && !found)
    {
        if (T.TI[i].makanan == ID)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}
/* Mengirimkan true jika makanan dengan ID ada dalam T, false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiArray(arrayDiner T)
{
    if (IsArrayEmpty(T))
    {
        printf("Array kosong\n");
    }
    else
    {
        int i;
        for (i = GetFirstDinerIdx(T); i <= GetLastDinerIdx(T); i++)
        {
            printf("Makanan:M%d, ", T.TI[i].makanan);
            printf("Durasi:%d, ", T.TI[i].durasimasak);
            printf("Ketahanan:%d, ", T.TI[i].ketahanan);
            printf("Harga: %d \n", T.TI[i].harga);
        }
        printf("\n");
    }
}
/* Proses : Menuliskan isi array dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : Makanan, Durasi Masak, Ketahanan, dan Harga dari tiap makanan dalam T akan diprint */
/* Jika T kosong : Hanya menulis "Array kosong" */