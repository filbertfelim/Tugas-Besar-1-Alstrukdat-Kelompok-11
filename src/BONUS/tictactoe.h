#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/Mesinkar_kata/mesin_kata.h"

#ifndef TICTACTOE_H
#define TICTACTOE_H

void PrintBoard();
int checkboard();
void resetboard();
void playermove();
void computermove();
char checkwin();
void printwin(char winner);
#endif