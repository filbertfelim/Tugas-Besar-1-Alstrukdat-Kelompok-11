#include "history.h"
#include <stdio.h>
#include <stdlib.h>

void history(Stack *S, int n)
{
    printf("Berikut adalah daftar game terakhir yang dimainkan: \n");
    if(IsStackEmpty(*S)){
        printf("Belum ada game yang dimainkan\n");
    }
    else{
        int i = 1;
        stackinfotype val; 
        Stack newStack;

        CreateEmptyStack(&newStack);
        newStack = *S;
        while (i <= n && !IsStackEmpty(newStack))
        {
            printf("%d. %s\n", i, InfoTop(newStack));
            Pop(&newStack, &val);
            i++;
        }
    }
}
/*
    Menampilkan history game yang dimainkan sebanyak n game, jika n melebihi banyak history, maka akan menampilkan semuanya
*/