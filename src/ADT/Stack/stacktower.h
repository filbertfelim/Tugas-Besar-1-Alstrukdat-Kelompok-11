/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackttower_H
#define stackttower_H

#include "../../boolean.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef int stacktowerinfotype;
typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
    stacktowerinfotype T[MaxEl]; /* tabel penyimpan elemen */
    address TOPTOWER;                 /* alamat TOP: elemen puncak */
} Stackhanoi;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopTower(S) (S).TOPTOWER
#define InfoTopTower(S) (S).T[(S).TOPTOWER]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackTower(Stackhanoi *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackTowerEmpty(Stackhanoi S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackTowerFull(Stackhanoi S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushTower(Stackhanoi *S, stacktowerinfotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopTower(Stackhanoi *S, stacktowerinfotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
boolean compareStack(Stackhanoi S1, Stackhanoi S2);
/* Mengirimkan true jika stack yang dibandingkan sama*/

int topless(Stackhanoi S);
#endif