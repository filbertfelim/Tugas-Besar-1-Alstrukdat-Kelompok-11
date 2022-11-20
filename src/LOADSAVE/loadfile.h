#ifndef LOADFILE_H
#define LOADFILE_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include "../ADT/Array/array.h"
#include "../ADT/Map/map.h"
#include "../STRINGCOMP/stringcomp.h"

boolean loadFile(TabStr *listgame, TabStr *histgame, Map *SB_RNG, Map *SB_DD, Map *SB_HGMN, Map *SB_TOH, Map *SB_SOM, char *filename);
/*
    membaca file savefile dan memasukkan game ke dalam array game
*/

#endif