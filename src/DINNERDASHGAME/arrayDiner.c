#include "arrayDiner.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArray(arrayDiner *T){
    T->Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray(arrayDiner T){
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElArray(arrayDiner T){
    return (IdxMax - IdxMin + 1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstDinerIdx(arrayDiner T){
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastDinerIdx(arrayDiner T){
    return NbElmtArray(T);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElTypeArrayDiner GetArrayElmt(arrayDiner T, IdxType i){
    return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetArray(arrayDiner Tin, arrayDiner *Tout){
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
void SetElArray(arrayDiner *T, IdxType i, ElTypeArrayDiner v){
    (*T).TI[i] = v;
    if (i == GetLastDinerIdx(*T) + 1)
    {
        (*T).Neff++;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeffArray(arrayDiner *T, IdxType N){
    (*T).Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsArrayIdxValid(arrayDiner T, IdxType i){
    return ((i >= IdxMin) && (i <= IdxMax));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsArrayIdxEff(arrayDiner T, IdxType i){
    return ((i >= GetFirstDinerIdx(T)) && (i <= GetLastDinerIdx(T)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsArrayEmpty(arrayDiner T){
    return (NbElmtArray(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsArrayFull(arrayDiner T){
    return (NbElmtArray(T) == MaxNbElArray(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiArray(arrayDiner T){
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
            printf("Harga, ", T.TI[i].harga);
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */