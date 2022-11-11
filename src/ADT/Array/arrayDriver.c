#include "array.h"
#include <stdio.h>

int main()
{
    TabStr T;
    MakeEmpty(&T);
    printf("Jumlah maksimum elemen T: %d\n", MaxNbEl(T));
    if (IsEmpty(T))
    {
        printf("Array kosong!\n");
    }
    // Isi Array
    char firstEl[] = "Test1";
    char secondEl[] = "Test2";
    char thirdEl[] = "Test3";
    char lastEl[] = "Test4";
    SetEl(&T, 1, firstEl);
    SetEl(&T, 2, secondEl);
    SetEl(&T, 3, thirdEl);
    SetEl(&T, 4, lastEl);
    TulisIsi(T);

    // NbElmt
    printf("Elemen T berjumlah: %d\n", NbElmt(T));
    printf("Indeks pertama T adalah: %d\n", GetFirstIdx(T));
    printf("Indeks terakhir T adalah: %d\n", GetLastIdx(T));
    char *Third = GetElmt(T, 3);
    printf("Elemen ke-3 : %s\n", Third);

    // SetTab
    printf("\nNew Array: \n");
    TabStr newTab;
    MakeEmpty(&newTab);
    SetTab(T, &newTab);
    TulisIsi(newTab);

    // Test indeks
    if (IsIdxValid(T, 1000))
    {
        printf("Indeks Valid!\n");
    }
    else
    {
        printf("Indeks tidak valid!\n");
    }

    if (IsIdxEff(newTab, 2))
    {
        printf("Indeks terdefinisi!\n");
    }
    else
    {
        printf("Indeks tidak terdefinisi!\n");
    }

    // isFull
    if (!IsFull(newTab))
    {
        printf("Tabel belum penuh!\n");
    }

    return 0;
}