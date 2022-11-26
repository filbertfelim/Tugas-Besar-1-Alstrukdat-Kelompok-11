#ifndef LOADFILE_H
#define LOADFILE_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Mesinkar_kata/mesin_kata.h"
#include "../ADT/Array/array.h"
#include "../ADT/Array/arrayMap.h"
#include "../ADT/Stack/stackhistory.h"
#include "../ADT/Map/map.h"
#include "../STRINGCOMP/stringcomp.h"

boolean loadFile(TabStr *listgame, TabMap *listsb, StackHistory *stackhist, char *filename);
/*
    membaca file savefile dan memasukkan game ke dalam array game
*/

#endif