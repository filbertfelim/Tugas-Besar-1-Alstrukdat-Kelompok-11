#ifndef DINNERDASH_H
#define DINNERDASH_H

#include "../DINNERDASHGAME/queuedinner.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../boolean.h"

void ADD(Queue *q);                          
// menambah menu ke queue
void COOK(Queue qM, Queue *q, int makanan);     
// membuat makanan
void SERVE(Queue *q, int makanan);              
// menyajikan makanan makanan
void COOKTIME(Queue *q);  
// mengurangi waktu memasak
boolean isEnd(Queue q, int counter);             
// cek apakah sudah sampai akhir queue
void commandCek(char *cc); 
// cek command
void runDinnerDash();                        
// run game

#endif