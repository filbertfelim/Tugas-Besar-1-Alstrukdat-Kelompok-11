#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "./ADT/Array/array.h"
#include "./ADT/Map/map.h"
#include "./ADT/Queue/queue.h"
#include "./ADT/Mesinkar_kata/mesin_kar.h"
#include "./ADT/Mesinkar_kata/mesin_kata.h"
#include "STRINGCOMP/stringcomp.h"
#include "./CREATEGAME/creategame.h"
#include "./LISTGAME/listgame.h"
#include "./START/start.h"
#include "boolean.h"

int main()
{
    printf("Selamat datang\n");
    printf("ENTER COMMAND: ");
    char *command;
    scanf("%s\n", &command);
    while (compare_strings(command, "START") || compare_strings(command, "LOAD"))
    {
        scanf("%s\n", &command);
    }
    if (compare_strings(command, "START"))
    {
        STARTGAME();
    }
    else
    {
        ;
    }
    return 0;
}