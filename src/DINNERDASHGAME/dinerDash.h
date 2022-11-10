#ifndef DINNERDASH_H
#define DINNERDASH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queueDiner.h"
#include "arrayDiner.h"
#include "../STRINGCOMP/stringcomp.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"

void PrintGame(int Saldo, Queue OrderList, arrayDiner Cook, arrayDiner Serve);

void Cook(Queue OrderList, arrayDiner *Cook, int IDMakanan);

void Serve(Queue *OrderList, arrayDiner *Serve, int IDMakanan, int *jumlahTerlayani, int *Saldo);

void TambahOrder(Queue *OrderList, int *customerID);

void NextPutaran(Queue *OrderList, arrayDiner *Cook, arrayDiner *Serve, int *IDCustomer);

void Skip(Queue *OrderList, arrayDiner *Cook, arrayDiner *Serve, int *IDCustomer);

int FoodID(char *Second);
/* Menghasilkan hasil ID jika ID Valid, -999 jika ID Tidak Valid*/

void dinerdash();


#endif