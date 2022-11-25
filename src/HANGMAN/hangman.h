#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <../ADT/array/array.h>
#include <../boolean.h>
#include <../ADT/Mesinkar_kata/mesin_kar.h>
#include <../ADT/Mesinkar_kata/mesin_kata.h>
#define chances 10;

void printBody(int mistakes, char* body);
void hangman();
void printWord(char* guess, int len);

#endif