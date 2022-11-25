#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Stack/stacktower.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include "../ADT/Mesinkar_kata/mesin_kar.h"

int optimalmoves();
void blank(int x);
void stars(int x);
void displaytowerhanoi(int x, Stackhanoi A, Stackhanoi B, Stackhanoi C);
void towerofhanoi();
#endif