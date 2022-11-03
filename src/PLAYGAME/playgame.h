#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <stdio.h>
#include "int_queue.h"
#include "mesin_kata.h"
#include "array.h"
#include "stringcomp.h"
#include "rng.h"
#include "dinnerdash.h"

void Play(intQueue *antrian, TabStr GameList);
/*Memainkan Game pada urutan teratas*/

void PlayGame(intQueue *antrian, TabStr GameList);
/*Menampilkan game dalam antrian kemudian memainkan game pada urutan teratas*/

#endif