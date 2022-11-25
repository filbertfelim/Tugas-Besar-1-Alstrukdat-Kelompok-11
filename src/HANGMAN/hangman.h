#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/Array/array.h"
#include "../boolean.h"
#include "../ADT/Mesinkar_kata/mesin_kar.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include "../STRINGCOMP/stringcomp.h"

void printBody(int mistakes, char* body);
void hangman();
void MenuStart(TabStr *listgame, char *filename, char *file);
void printWord(TabStr *listgame, char *guess);

#endif