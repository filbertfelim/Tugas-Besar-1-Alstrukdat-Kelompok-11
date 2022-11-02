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
#include "./HELP/help.h"
#include "boolean.h"

int main()
{
    printf("Selamat datang\n");
    printf("ENTER COMMAND: ");
    char *command;
    command = STARTINPUT();
    while (!compare_strings(command, "START") && !compare_strings(command, "LOAD"))
    {
        printf("Perintah yang bisa digunakan hanya START DAN LOAD\n\n");
        printf("ENTER COMMAND: ");
        command = STARTINPUT();
    }
    if (compare_strings(command, "START"))
    {
        TabStr game;
        MakeEmpty(&game);
        STARTGAME(&game);
    }
    else
    {
        printf("LOAD\n"); // command LOADGAME;
    }
    printf("ENTER COMMAND: ");
    command = STARTINPUT();
    while (!compare_strings(command, "QUIT"))
    {
        if (compare_strings(command, "CREATE GAME"))
        {
            ;
        }
        else if (compare_strings(command, "LIST GAME"))
        {
            ;
        }
        else if (compare_strings(command, "DELETE GAME"))
        {
            ;
        }
        else if (compare_strings(command, "QUEUE GAME"))
        {
            ;
        }
        else if (compare_strings(command, "PLAY GAME"))
        {
            ;
        }
        else if (compare_strings(command, "SKIP GAME"))
        {
            ;
        }
        else if (compare_strings(command, "HELP"))
        {
            help();
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n\n");
        }
        printf("ENTER COMMAND: ");
        command = STARTINPUT();
    }
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
    return 0;
}