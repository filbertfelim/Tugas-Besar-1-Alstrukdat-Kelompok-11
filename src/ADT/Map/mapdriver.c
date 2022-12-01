#include "map.h"
#include <stdio.h>

int main()
{
    Map m;
    CreateEmptyMap(&m);
    if (IsMapEmpty(m))
    {
        printf("Map kosong\n");
    }

    // Memasukkan contoh data ke dalam map
    Insert(&m, "contoh1", 1);
    Insert(&m, "contoh2", 2);
    Insert(&m, "contoh3", 3);
    Insert(&m, "contoh4", 4);
    printf("Banyak pair didalam map : %d\n", m.Count);
    int i;
    for (i = 0; i < m.Count; i++)
    {
        printf("Key dan value elemen ke-%d : %s dan %d\n", i + 1, m.Elements[i].Key, m.Elements[i].Value);
    }

    // Menghapus isi map
    Delete(&m, "contoh2");
    printf("Banyak pair didalam map : %d\n", m.Count);
    for (i = 0; i < m.Count; i++)
    {
        printf("Key dan value elemen ke-%d : %s dan %d\n", i + 1, m.Elements[i].Key, m.Elements[i].Value);
    }
    if (!IsMember(m, "contoh2"))
    {
        printf("Contoh2 sudah tidak ada di dalam map\n");
    }
    SortMapValueDesc(&m);
    for (i = 0; i < m.Count; i++)
    {
        printf("Key dan value elemen ke-%d setelah diurut menurun berdasarkan value : %s dan %d\n", i + 1, m.Elements[i].Key, m.Elements[i].Value);
    }
    return 0;
}