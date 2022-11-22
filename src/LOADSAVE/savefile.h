#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Array/array.h"
#include "../ADT/Array/arrayMap.h"
#include "../ADT/Mesinkar_kata/mesin_kata.h"

void SAVE(TabStr listgame, TabStr histgame, TabMap arr_sb, char *file);
/*
    menyimpan daftar game ke dalam file savefile.txt
*/
#endif