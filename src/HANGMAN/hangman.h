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

boolean loadFile(TabStr *listgame, char *filename);
void addWord(TabStr listgame, char *file);
int random(TabStr T);
void printWord(TabStr *listkata, char *guess); 
void MenuStart(TabStr *listkata, char *filename);
void hangman(TabStr *listkata, char *filename);

#endif