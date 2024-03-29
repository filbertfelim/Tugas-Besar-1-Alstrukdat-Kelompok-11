#include <stdio.h>
#include "resethistory.h"
#include "../ADT/Stack/stackhistory.h"
#include "../STRINGCOMP/stringcomp.h"
#include "../ADT/Mesinkar_kata/mesin_kar.h"

void resethistory(StackHistory *SH)
{
    printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY?(YA/TIDAK) ");
    char *command;
    command = STARTINPUT();
    if (compare_strings(command, "YA"))
    {
        while (!IsStackHistoryEmpty(*SH))
        {
            stackhistinfotype val;
            PopHistory(SH, &val);
        }
        printf("\nHISTORY BERHASIL DI-RESET.\n");
    }
    else if (compare_strings(command, "TIDAK"))
    {
        printf("\nRESET HISTORY DIBATALKAN. Berikut adalah daftar Game yang telah dimainkan:\n");
        int n = countStackHistory(*SH);
        PrintStackHistory(SH, n);
    }
    else
    {
        printf("\nINPUT TIDAK VALID. Silakan coba lagi masukkan input yang valid!\n");
    }
}