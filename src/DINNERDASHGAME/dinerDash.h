#ifndef DINNERDASH_H
#define DINNERDASH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../DINNERDASHGAME/queueDiner.h"
#include "../DINNERDASHGAME/arrayDiner.h"
#include "../STRINGCOMP/stringcomp.h"
#include "mesin_kata.h"
#include "mesin_kar.h"

void PrintGame(int Saldo, Queue OrderList, arrayDiner Cook, arrayDiner Serve);

void Cook(Queue OrderList, arrayDiner *Cook, int IDMakanan);

void Serve(Queue *OrderList, arrayDiner *Serve, int IDMakanan, int *jumlahTerlayani);

void TambahOrder(Queue *OrderList, int *customerID);

void NextPutaran(Queue *OrderList, arrayDiner *Cook, arrayDiner *Serve);

void Skip(Queue *OrderList, arrayDiner *Cook, arrayDiner *Serve);

void dinerdash();


#endif