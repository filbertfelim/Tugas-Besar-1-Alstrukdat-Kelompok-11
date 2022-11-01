#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "./ADT/Array/array.h"
#include "./ADT/Queue/queue.h"
#include "./ADT/Mesinkar_kata/mesin_kar.h"
#include "./ADT/Mesinkar_kata/mesin_kata.h"
#include "STRINGCOMP/stringcomp.h"
// #include "./CREATEGAME/creategame.h"
// #include "./LISTGAME/listgame.h"
#include "./START/start.h"
#include "boolean.h"

int main()
{
    printf("Selamat datang\n");
    printf("ENTER COMMAND: ");
    char *command;
    scanf("%s", command);
    while (!compare_strings(command, "START") && !compare_strings(command, "LOAD"))
    {
        printf("Perintah yang bisa digunakan hanya START DAN LOAD\n");
        printf("ENTER COMMAND: ");
        scanf("%s", command);
    }
    if (compare_strings(command, "START"))
    {
        TabStr game;
        MakeEmpty(&game);
        STARTGAME(&game);
        int i;
        for (i = 0; i < game.Neff; i++)
        {
            printf("%s\n", game.TI[i]);
        }
    }
    else
    {
        ; // command LOADGAME;
    }

    return 0;
}