#include "arrayDiner.h"
#include <stdio.h>

int main()
{
    arrayDiner A;
    MakeEmptyArray(&A);
    printf("Jumlah maksimum elemen array: %d\n", MaxNbElArray(A));
    if (IsArrayEmpty(A))
    {
        printf("Array kosong!\n");
    }
    // Isi Array
    int i;
    ElTypeArrayDiner temp;
    for (i = 0; i < 5; i++)
    {
        temp.makanan = i;
        temp.durasimasak = i + 1;
        temp.ketahanan = i + 1;
        temp.harga = i + 15000;
        SetElArray(&A, GetFirstDinerIdx(A) + i, temp);
    }
    printf("Elemen array berjumlah: %d\n", NbElmtArray(A));
    printf("Indeks pertama array adalah: %d\n", GetFirstDinerIdx(A));
    printf("Indeks terakhir array adalah: %d\n", GetLastDinerIdx(A));

    ElTypeArrayDiner secondEl = GetArrayElmt(A, 2);
    printf("Elemen ke-2: \n");
    printf("Makanan: %d, Durasi Masak: %d, Ketahanan: %d, Harga: %d\n\n", secondEl.makanan, secondEl.durasimasak, secondEl.ketahanan, secondEl.harga);
    if (IsInArray(A, 1))
    {
        printf("Makanan dengan ID 1 ada di dalam array.\n");
    }
    else
    {
        printf("Makanan dengan ID 1 tidak ada di dalam array.\n");
    }
    TulisIsiArray(A);
    DeleteEl(&A, 1); // Hapus Elemen Pertama
    // Tes SetArray
    arrayDiner newArray;
    MakeEmptyArray(&newArray);
    printf("New Array: \n");
    TulisIsiArray(newArray);
    SetArray(A, &newArray);
    TulisIsiArray(newArray);

    if (IsArrayIdxValid(A, 10))
    {
        printf("Indeks 10 valid untuk array A.\n");
    }
    if (IsArrayIdxEff(A, 10))
    {
        printf("Indeks 10 terdefinisi untuk array A.\n");
    }
    else
    {
        printf("Indeks 10 tidak terdefinisi untuk array A.\n");
    }
    return 0;
}