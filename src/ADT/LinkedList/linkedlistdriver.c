#include "listdp.h"
#include <stdio.h>

int main()
{
    List L;
    CreateListEmpty(&L);
    if (IsListEmpty(L))
    {
        printf("List Kosong!\n\n");
    }

    // Insert + Alokasi
    listinfotype Point1;
    listinfotype Point2;
    listinfotype Point3;
    listinfotype Point4;
    listinfotype Point5;
    listinfotype Point6;
    Point1.posX = 1;
    Point2.posX = 2;
    Point3.posX = 3;
    Point4.posX = 4;
    Point5.posX = 5;
    Point6.posX = 6;
    Point1.posY = 1;
    Point2.posY = 2;
    Point3.posY = 3;
    Point4.posY = 4;
    Point5.posY = 5;
    Point6.posY = 6;

    // Insert Head & Tail
    InsVHead(&L, Point2);
    InsVHead(&L, Point1);
    InsVTail(&L, Point5);
    InsVTail(&L, Point6);

    // Insert After & Before + Search
    addresslist elemenSatu = Alokasi(Point3);
    addresslist elemenDua = Alokasi(Point4);
    InsertAfter(&L, elemenSatu, Search(L, Point2));
    InsertBefore(&L, elemenDua, Search(L, Point5));

    // Print
    printf("Forward: ");
    PrintForward(L);
    printf("\n");
    printf("Backward: ");
    PrintBackward(L);
    printf("\n");

    // posInList
    printf("Posisi Point <%d,%d> : %d\n\n", Point3.posX, Point3.posY, posInList(L, Point3));

    // Delete
    Point tempPos;
    DelVHead(&L, &tempPos);
    printf("Hasil Delete: \n");
    printf("tempPos: <%d,%d>\n", tempPos.posX, tempPos.posY);
    DelVTail(&L, &tempPos);
    printf("tempPos: <%d,%d>\n", tempPos.posX, tempPos.posY);
    printf("Setelah DelHead & DelTail: ");
    PrintForward(L);
    printf("\n");

    // DelP, DelAfter, DelBefore
    DelP(&L, Point2);
    addresslist deletedPoint;
    printf("Setelah DelP di Point<2,2> dan DelAfter:\n");
    DelAfter(&L, &deletedPoint, Search(L, Point3));
    printf("Point yang dihapus: <%d,%d>\n", (*deletedPoint).info.posX, (*deletedPoint).info.posY);
    PrintForward(L);
    printf("\n");

    printf("Setelah DelBefore:\n");
    DelBefore(&L, &deletedPoint, Search(L, Point5));
    printf("Point yang dihapus: <%d,%d>\n", (*deletedPoint).info.posX, (*deletedPoint).info.posY);
    PrintForward(L);
    printf("\n");
}