#include <stdio.h>
#include "stackhistory.h"

int main()
{
    StackHistory s;
    CreateEmptyStackHistory(&s);
    if (IsStackHistoryEmpty(s))
    {
        printf("Stack history kosong\n");
    }

    // isi stack
    PushHistory(&s, "contoh1");
    PushHistory(&s, "contoh2");
    PushHistory(&s, "contoh3");
    PushHistory(&s, "contoh4");
    printf("Isi top stack : %s\n", InfoTopHistory(s));

    int i;
    printf("Isi stack dimulai dari top:\n");
    PrintStackHistory(&s, s.TOPHISTORY + 1);
    char *hasilpop;
    // pop stack
    PopHistory(&s, &hasilpop);
    printf("Elemen yang di-pop : %s\n", hasilpop);
    printf("Isi stack setelah di pop dimulai dari top:\n");
    PrintStackHistory(&s, s.TOPHISTORY + 1);
    return 0;
}