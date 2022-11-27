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
#include "../START/start.h"

boolean loadfilekata(TabStr *listkata, char *filename);
void addWord(TabStr listkata, char *filename);
int randomidx(TabStr T);
void MenuStart(TabStr *listkata, char *filename);
void hangman(char *filename, int *skor);

#endif