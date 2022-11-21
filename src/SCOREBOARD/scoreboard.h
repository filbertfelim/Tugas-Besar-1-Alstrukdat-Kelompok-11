#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include "../ADT/Map/map.h"
#include "../ADT/Array/array.h"
#include "../ADT/Array/arrayMap.h"
#include "../STRINGCOMP/stringcomp.h"

void scoreboard(TabMap arr_sb, TabStr listgame);
/*
    Menampilkan scoreboard dari semua game di list game
*/

void resetscoreboard(TabStr listgame, TabMap *arr_sb);
/*
    mereset scoreboard dari game yang dipilih
*/
#endif