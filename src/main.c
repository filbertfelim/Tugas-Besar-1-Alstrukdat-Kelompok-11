#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "./ADT/Array/array.h"
#include "./ADT/Queue/strQueue.h"
#include "./ADT/Mesinkar_kata/mesin_kar.h"
#include "./ADT/Mesinkar_kata/mesin_kata.h"
#include "./STRINGCOMP/stringcomp.h"
#include "./CREATEGAME/creategame.h"
#include "./LISTGAME/listgame.h"
#include "./DELETEGAME/deletegame.h"
#include "./QUEUEGAME/queuegame.h"
#include "./PLAYGAME/playgame.h"
#include "./DINNERDASHGAME/queuedinner.h"
#include "./DINNERDASHGAME/dinnerdash.h"
#include "./GAMERNG/rng.h"
#include "./SKIPGAME/skipgame.h"
#include "./COMMANDLAIN/commandlain.h"
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
    TabStr game;
    strQueue gamequeue;
    CreateStrQueue(&gamequeue);
    if (compare_strings(command, "START"))
    {
        MakeEmpty(&game);
        STARTGAME(&game);
    }
    else
    {
        MakeEmpty(&game);
        printf("LOAD\n"); // command LOADGAME
    }
    printf("ENTER COMMAND: ");
    command = STARTINPUT();
    char *first = FirstWord(command);
    char *scnd = SecondWord(command);
    while (!compare_strings(command, "QUIT"))
    {
        if (compare_strings(command, "CREATE GAME"))
        {
            CreateGame(&game);
        }
        else if (compare_strings(command, "LIST GAME"))
        {
            LISTGAME(&game);
        }
        else if (compare_strings(command, "DELETE GAME"))
        {
            DeleteGame(&game);
        }
        else if (compare_strings(command, "QUEUE GAME"))
        {
            QueueGame(&gamequeue, game);
        }
        else if (compare_strings(command, "PLAY GAME"))
        {
            PlayGame(&gamequeue);
        }
        else if (compare_strings(first, "SKIPGAME"))
        {
            SkipGame(&gamequeue, strtointinput(scnd, str_len(scnd)));
        }
        else if (compare_strings(command, "HELP"))
        {
            help();
        }
        else
        {
            commandlain();
        }
        printf("ENTER COMMAND: ");
        command = STARTINPUT();
        first = FirstWord(command);
        scnd = SecondWord(command);
    }
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
    return 0;
}