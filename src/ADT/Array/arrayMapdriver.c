#include <stdio.h>
#include "arrayMap.h"

int main()
{
    TabMap T;
    MakeEmptyArrayMap(&T);
    printf("Jumlah maksimum map di array T : %d\n", MaxNbElArrayMap(T));
    if (IsEmptyArrayMap(T))
    {
        printf("Array map kosong!\n");
    }
    Map map1, map2, map3, map4;
    CreateEmptyMap(&map1);
    CreateEmptyMap(&map2);
    CreateEmptyMap(&map3);
    CreateEmptyMap(&map4);
    map4.Count = 100;

    // Mengisi array dengan map
    SetElArrayMap(&T, 0, map1);
    SetElArrayMap(&T, 1, map2);
    SetElArrayMap(&T, 2, map3);
    SetElArrayMap(&T, 3, map4);

    // NbElmt
    printf("Elemen T berjumlah: %d\n", NbElmtArrayMap(T));
    printf("Indeks pertama T adalah: %d\n", GetFirstIdxArrayMap(T));
    printf("Indeks terakhir T adalah: %d\n", GetLastIdxArrayMap(T));
    Map keempat = GetElmtArrayMap(T, 3);
    printf("Elemen ke-4 isi mapnya ada : %d\n", keempat.Count);
    return 0;
}