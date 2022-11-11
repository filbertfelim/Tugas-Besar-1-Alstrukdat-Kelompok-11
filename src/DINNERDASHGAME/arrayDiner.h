#include "../boolean.h"

#ifndef ARRAYDINER_H
#define ARRAYDINER_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
    int makanan;
    int durasimasak;
    int ketahanan;
    int harga;
} ElTypeArrayDiner;

typedef int IdxType;

typedef struct
{
    ElTypeArrayDiner TI[IdxMax - IdxMin + 1]; /* memori tempat penyimpan elemen (container) */
    int Neff;                                 /* banyaknya elemen efektif */
} arrayDiner;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah arrayDiner, cara deklarasi dan akses: */
/* Deklarasi : T : arrayDiner */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen arrayDiner
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Array kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create array kosong */
void MakeEmptyArray(arrayDiner *T);
/* I.S. sembarang */
/* F.S. Terbentuk array T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray(arrayDiner T);
/* Mengirimkan banyaknya elemen efektif array */
/* Mengirimkan nol jika array kosong */
/* *** Daya tampung container *** */
int MaxNbElArray(arrayDiner T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh array */
/* *** Selektor INDEKS *** */
IdxType GetFirstDinerIdx(arrayDiner T);
/* Prekondisi : array T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastDinerIdx(arrayDiner T);
/* Prekondisi : array T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElTypeArrayDiner GetArrayElmt(arrayDiner T, IdxType i);
/* Prekondisi : array tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen array yang ke-i */

/* *** Selektor SET : Mengubah nilai array dan elemen array *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetArray(arrayDiner Tin, arrayDiner *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment Tout -> Tin */
void SetElArray(arrayDiner *T, IdxType i, ElTypeArrayDiner v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen array yang ke-i sehingga bernilai v */
void SetNeffArray(arrayDiner *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
void DeleteEl(arrayDiner *T, int idx);
/* I.S. T terdefinisi dan tidak kosong*/
/* F.S. Elemen T di posisi idx terhapus*/

/* ********** Test Indeks yang valid ********** */
boolean IsArrayIdxValid(arrayDiner T, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran array */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsArrayIdxEff(arrayDiner T, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk array */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test array kosong *** */
boolean IsArrayEmpty(arrayDiner T);
/* Mengirimkan true jika array T kosong, mengirimkan false jika tidak */
/* *** Test array penuh *** */
boolean IsArrayFull(arrayDiner T);
/* Mengirimkan true jika array T penuh, mengirimkan false jika tidak */

/* ********** SEARCH ********** */
boolean IsInArray(arrayDiner T, int ID);
/* Mengirimkan true jika makanan dengan ID ada dalam T, false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiArray(arrayDiner T);
/* Proses : Menuliskan isi array dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : Makanan, Durasi Masak, Ketahanan, dan Harga dari tiap makanan dalam T akan diprint */
/* Jika T kosong : Hanya menulis "Array kosong" */
#endif