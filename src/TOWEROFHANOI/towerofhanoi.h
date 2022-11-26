#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Stack/stackhanoi.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"

void scoredisplay(int step, int *score);

void checkmoves(char t1, char t2, Stack A, Stack B, Stack, C, boolean *check);

boolean checkwin(Stack C);

void displaytowerhanoi(Stack A, Stack B, Stack C);

void towerofhanoi(int *skor);
#endif