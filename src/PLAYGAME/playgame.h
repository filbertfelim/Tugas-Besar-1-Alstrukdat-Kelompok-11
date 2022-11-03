#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <stdio.h>
#include "../ADT/Queue/strQueue.h"
#include "mesin_kata.h"
#include "array.h"
#include "stringcomp.h"
#include "rng.h"
#include "dinnerdash.h"

void Play(strQueue *antrian);
/*Memainkan Game pada urutan teratas*/

void PlayGame(strQueue *antrian);
/*Menampilkan game dalam antrian kemudian memainkan game pada urutan teratas*/

#endif