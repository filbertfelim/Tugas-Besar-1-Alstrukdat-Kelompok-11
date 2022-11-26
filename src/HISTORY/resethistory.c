#include <stdio.h>
#include "resethistory.h"
#include "../ADT/Stack/stackhistory.h"
#include "../STRINGCOMP/stringcomp.h"
#include "../ADT/Mesinkar_kata/mesin_kar.h"

void resethistory(StackHistory *SH)
{
    printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY?");
    char *command;
    command = STARTINPUT();
    if (compare_strings(command, "YA")){
        while (!IsStackHistoryEmpty(*SH)){
            stackhistinfotype val;
            PopHistory(SH, &val);
        }
        printf("\nHISTORY BERHASIL DI RESET\n");
    }
    else if (compare_strings(command, "TIDAK")){
        printf("\nRESET HISTORY DIBATALKAN\n");
    }
    else{
        printf("\nINPUT TIDAK VALID\n");
    }
}