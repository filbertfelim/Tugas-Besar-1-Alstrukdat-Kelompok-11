#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include "../ADT/Mesinkar_kata/mesin_kar.h"

void PrintBoard();
int checkboard();
void resetboard();
void playermove();
void computermove();
char checkwin();
void printwin(char winner);
void tictactoe(int *skor);
#endif