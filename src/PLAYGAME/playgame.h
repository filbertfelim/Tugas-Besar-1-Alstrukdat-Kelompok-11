#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Queue/strQueue.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include "../ADT/Array/array.h"
#include "../ADT/Array/arrayMap.h"
#include "../ADT/LinkedList/listdp.h"
#include "../ADT/Stack/stack.h"
#include "../ADT/Stack/stackhistory.h"
#include "../STRINGCOMP/stringcomp.h"
#include "../GAMERNG/rng.h"
#include "../BONUS/tictactoe.h"
#include "../DINNERDASHGAME/dinerDash.h"
#include "../TOWEROFHANOI/towerofhanoi.h"
#include "../HANGMAN/hangman.h"
#include "../SnakeOnMeteor/SnakeOnMeteor.h"

void Play(strQueue *antrian, TabStr listgame, TabMap *arr_sb, StackHistory *stackhist);
/*Memainkan Game pada urutan teratas*/

void PlayGame(strQueue *antrian, TabStr listgame, TabMap *arr_sb, StackHistory *stackhist);
/*Menampilkan game dalam antrian kemudian memainkan game pada urutan teratas*/

#endif