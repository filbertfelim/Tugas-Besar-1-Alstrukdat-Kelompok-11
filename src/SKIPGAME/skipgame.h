#ifndef SKIPGAME_H
#define SKIPGAME_H

#include "../../boolean.h"
#include "../ADT/Queue/int_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "playgame.h"


void SkipGame(intQueue *GameQueue, int n, TabStr GameList);
/*
Melewatkan game sebanyak n kali, lalu memainkan game
*/

#endif