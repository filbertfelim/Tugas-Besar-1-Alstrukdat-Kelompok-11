#include "history.h"
#include <stdio.h>
#include <stdlib.h>

void history(StackHistory *SH, int n)
{
    printf("Berikut adalah daftar game terakhir yang dimainkan: \n");
    if(IsStackHistoryEmpty(*SH)){
        printf("Belum ada game yang dimainkan\n");
    }
    else{
        int i = 1;
        stackhistinfotype val; 
        StackHistory newStack;

        CreateEmptyStackHistory(&newStack);
        newStack = *SH;
        while (i <= n && !IsStackHistoryEmpty(newStack))
        {
            printf("%d. %s\n", i, InfoTopHistory(newStack));
            PopHistory(&newStack, &val);
            i++;
        }
    }
}
/*
    Menampilkan history game yang dimainkan sebanyak n game, jika n melebihi banyak history, maka akan menampilkan semuanya
*/