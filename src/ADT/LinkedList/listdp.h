/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan addresslist adalah pointer */
/* listinfotype adalah integer */

#ifndef SnakeListDP_H
#define SnakeListDP_H
#include "../../boolean.h"

#define ListNil NULL

/* Definisi Type Data */
typedef struct
{
	int posX;
	int posY;
} Point;

typedef Point listinfotype;
typedef struct tElmtlist *addresslist;
typedef struct tElmtlist
{
	listinfotype info;
	addresslist next;
	addresslist prev;
} ElmtList;
typedef struct
{
	addresslist Head;
	addresslist Tail;
} List;

/* Definisi list : */
/* List kosong : Head(L) = ListNil dan Tail(L) = ListNil */
/* Setiap elemen dengan addresslist P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Tail(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define Head(L) ((L).Head)
#define Tail(L) ((L).Tail)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty(List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListEmpty(List *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addresslist Alokasi(listinfotype X);
/* Mengirimkan addresslist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak ListNil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=ListNil, Prev(P)=ListNil */
/* Jika alokasi gagal, mengirimkan ListNil. */
void Dealokasi(addresslist P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addresslist P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addresslist Search(List L, listinfotype X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addresslist elemen tersebut. */
/* Jika tidak ada, mengirimkan ListNil */

int posInList(List L, listinfotype X);
/* Mengembalikan posisi sebuah elemen X dalam list */
/* Elemen X pasti ada di dalam List */

/****************** PRIMITIF BERDASARKAN ListNilAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVHead(List *L, listinfotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan ListNilai X jika alokasi berhasil */
void InsVTail(List *L, listinfotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berListNilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVHead(List *L, listinfotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: ListNilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVTail(List *L, listinfotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: ListNilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertHead(List *L, addresslist P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addresslist P sebagai elemen pertama */
void InsertTail(List *L, addresslist P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter(List *L, addresslist P, addresslist Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore(List *L, addresslist P, addresslist Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelHead(List *L, addresslist *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Head element yg baru adalah suksesor elemen pertama yang lama */
void DelTail(List *L, addresslist *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Tail element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP(List *L, listinfotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddresslist P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter(List *L, addresslist *Pdel, addresslist Prec);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore(List *L, addresslist *Pdel, addresslist Succ);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward(List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berListNilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward(List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen berListNilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif