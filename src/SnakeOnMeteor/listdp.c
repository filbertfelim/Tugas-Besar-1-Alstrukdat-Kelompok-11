#include "listdp.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L)
{
    return (Head(L) == Nil && Tail(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L)
{
    Head(*L) = Nil;
    Tail(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi(infotype X)
{
    ElmtList *P;
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P).posX = X.posX;
        Info(P).posY = X.posY;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    else
    {
        return Nil;
    }

    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi(address P)
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X)
{
    address P = Head(L);
    boolean found = false;
    while ((P != Nil) && !found)
    {
        if (Info(P).posX == X.posX && Info(P).posY == X.posY)
        {
            found = true;
        }
        else
        {
            P = Next(P);
        }
    }
    if (found)
    {
        return P;
    }
    else
    {
        return Nil;
    }
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

int posInList(List L, infotype X)
{
    int pos = 0;
    address P = Head(L);
    while (Info(P).posX != X.posX || Info(P).posY != X.posY)
    {
        P = Next(P);
        pos++;
    }
    return pos;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVHead(List *L, infotype X)
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertHead(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVTail(List *L, infotype X)
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertTail(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVHead(List *L, infotype *X)
{
    address P;
    DelHead(L, &P);
    (*X) = Info(P);
    Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVTail(List *L, infotype *X)
{
    address P;
    DelTail(L, &P);
    (*X) = Info(P);
    Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertHead(List *L, address P)
{
    Next(P) = Head(*L);
    if (!IsEmpty(*L))
    {
        Prev(Head(*L)) = P;
    }
    else
    {
        Tail(*L) = P;
    }
    Head(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertTail(List *L, address P)
{
    if (IsEmpty(*L))
    {
        InsertHead(L, P);
    }
    else
    {
        Prev(P) = Tail(*L);
        Next(Tail(*L)) = P;
        Tail(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter(List *L, address P, address Prec)
{
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Next(Prec) = P;
    if (Next(P) == Nil)
    {
        Tail(*L) = P;
    }
    else
    {
        Prev(Next(P)) = P;
    }
}
/* I.S. Prec pastilah elemen list{} P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore(List *L, address P, address Succ)
{
    Prev(P) = Prev(Succ);
    Next(P) = Succ;
    Prev(Succ) = P;
    if (Prev(P) == Nil)
    {
        Head(*L) = P;
    }
    else
    {
        Next(Prev(P)) = P;
    }
}
/* I.S. Succ pastilah elemen list{} P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelHead(List *L, address *P)
{
    (*P) = Head(*L);
    Head(*L) = Next(*P);
    if (Next(*P) != Nil)
    {
        Prev(Head(*L)) = Nil;
    }
    else
    {
        Tail(*L) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Head element yg baru adalah suksesor elemen pertama yang lama */
void DelTail(List *L, address *P)
{
    (*P) = Tail(*L);
    Tail(*L) = Prev(*P);
    if (Prev(*P) != Nil)
    {
        Next(Tail(*L)) = Nil;
    }
    else
    {
        Head(*L) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Tail element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP(List *L, infotype X)
{
    address P = Search(*L, X);
    if (P != Nil)
    {
        if (P == Head(*L))
        {
            DelHead(L, &P);
        }
        else if (P == Tail(*L))
        {
            DelTail(L, &P);
        }
        else
        {
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        }
    }
    Dealokasi(P);
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter(List *L, address *Pdel, address Prec)
{
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(*Pdel);
    if (Next(Prec) != Nil)
    {
        Prev(Next(Prec)) = Prec;
    }
    else
    {
        Tail(*L) = Prec;
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore(List *L, address *Pdel, address Succ)
{
    (*Pdel) = Prev(Succ);
    Prev(Succ) = Prev(*Pdel);
    if (Prev(*Pdel) != Nil)
    {
        Next(Prev(*Pdel)) = Succ;
    }
    else
    {
        Head(*L) = Succ;
    }
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward(List L)
{
    if (IsEmpty(L))
    {
        printf("[]");
    }
    else
    {
        address P = Head(L);
        printf("[");
        while (P != Nil)
        {
            if (Next(P) == Nil)
            {
                printf("<%d,%d>", Info(P).posX, Info(P).posY);
            }
            else
            {
                printf("<%d,%d>,", Info(P).posX, Info(P).posY);
            }
            P = Next(P);
        }
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward(List L)
{
    if (IsEmpty(L))
    {
        printf("[]");
    }
    else
    {
        address P = Tail(L);
        printf("[");
        while (P != Nil)
        {
            if (Prev(P) == Nil)
            {
                printf("<%d,%d>", Info(P).posX, Info(P).posY);
            }
            else
            {
                printf("<%d,%d>,", Info(P).posX, Info(P).posY);
            }
            P = Prev(P);
        }
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */