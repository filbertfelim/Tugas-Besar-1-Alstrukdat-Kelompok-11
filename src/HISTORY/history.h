#ifndef HISTORY_H
#define HISTORY_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Stack/stackhistory.h"
#include "../STRINGCOMP/stringcomp.h"

void history(StackHistory *SH, int n);
/*
    Menampilkan history game yang dimainkan sebanyak n game, jika n melebihi banyak history, maka akan menampilkan semuanya
*/

#endif