#include <stdio.h>
#include "stack.h"

int main()
{
    Stack s;
    CreateEmptyStack(&s);
    if (IsStackEmpty(s))
    {
        printf("Stack kosong\n");
    }

    // isi stack
    Push(&s, "contoh1");
    Push(&s, "contoh2");
    Push(&s, "contoh3");
    Push(&s, "contoh4");
    printf("Isi top stack : %s\n", InfoTop(s));

    int i;
    printf("Isi stack dimulai dari top:\n");
    for (i = s.TOP; i >= 0; i--)
    {
        printf("%s\n", s.T[i]);
    }
    char *hasilpop;
    // pop stack
    Pop(&s, &hasilpop);
    printf("Elemen yang di-pop : %s\n", hasilpop);
    printf("Isi stack setelah di pop dimulai dari top:\n");
    for (i = s.TOP; i >= 0; i--)
    {
        printf("%s\n", s.T[i]);
    }
    return 0;
}