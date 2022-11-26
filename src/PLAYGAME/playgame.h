#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Queue/strQueue.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include "../ADT/Array/array.h"
#include "../ADT/Array/arrayMap.h"
#include "../STRINGCOMP/stringcomp.h"
#include "../GAMERNG/rng.h"
#include "../BONUS/tictactoe.h"
// #include "../TOWEROFHANOI/towerofhanoi.h"
#include "../DINNERDASHGAME/dinerDash.h"

void Play(strQueue *antrian, TabStr listgame, TabMap *arr_sb);
/*Memainkan Game pada urutan teratas*/

void PlayGame(strQueue *antrian, TabStr listgame, TabMap *arr_sb);
/*Menampilkan game dalam antrian kemudian memainkan game pada urutan teratas*/

#endif