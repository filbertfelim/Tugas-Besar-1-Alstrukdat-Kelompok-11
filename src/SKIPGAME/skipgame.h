#ifndef SKIPGAME_H
#define SKIPGAME_H

#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../ADT/Queue/strQueue.h"
#include "../ADT/Array/array.h"
#include "../ADT/Array/arrayMap.h"
#include "../PLAYGAME/playgame.h"

void SkipGame(strQueue *GameQueue, TabStr listgame, TabMap *arr_sb, int n);
/*
Melewatkan game sebanyak n kali, lalu memainkan game
*/

#endif