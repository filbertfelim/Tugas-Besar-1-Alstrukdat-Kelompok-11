#ifndef DINNERDASH_H
#define DINNERDASH_H

#include <stdio.h>
#include "../ADT/Queue/queue.h"
#include <stdlib.h>
#include "../boolean.h"
#include <time.h>

#define HARGA 15000

/* Definisi elemen dan address */
typedef struct {
    int makanan;
    int durasimemasak;
    int ketahanan;
    int harga;
} ElType;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead].idmakanan
#define     TAIL(q) (q).buffer[(q).idxTail].idmakanan

void ADD(Queue *q); //menambah menu ke queue
void COOK(Queue qM, Queue *q, int food); //membuat makanan
void SERVE(Queue *q, int food); //menyajikan makanan makanan
void COOKTIME(Queue *q); //mengurangi waktu memasak
boolean isEnd(Queue q, int ctr);    //cek apakah sudah sampai akhir queue
void commandCek(char *cc, int *, int *food); //cek command
void runDinnerDash();   //run game


#endif