#ifndef DINNERDASH_H
#define DINNERDASH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../DINERDASHGAME/queuedinner.h"
#include "../boolean.h"

void ADD(Queue *q); //menambah menu ke queue
void COOK(Queue qM, Queue *q, int food); //membuat makanan
void SERVE(Queue *q, int food); //menyajikan makanan makanan
void COOKTIME(Queue *q); //mengurangi waktu memasak
boolean isEnd(Queue q, int ctr);    //cek apakah sudah sampai akhir queue
void commandCek(char *cc, int *, int *food); //cek command
void runDinnerDash();   //run game


#endif