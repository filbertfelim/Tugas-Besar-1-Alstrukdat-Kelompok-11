#include <stdio.h>
#include "stacktower.h"

int main()
{
    Stackhanoi A, B;
    CreateEmptyStackTower(&A);
    CreateEmptyStackTower(&B);
    if (IsStackTowerEmpty(A))
    {
        printf("Stack kosong\n\n");
    }

    // isi stack
    PushTower(&A, 1);
    PushTower(&A, 2);
    PushTower(&A, 3);
    PushTower(&A, 4);
    printf("Isi top stack : %d\n", InfoTopTower(A));
    // isi stack
    PushTower(&B, 1);
    PushTower(&B, 2);
    PushTower(&B, 3);
    PushTower(&B, 4);
    printf("Isi top stack : %d\n", InfoTopTower(B));
    // compare stack
    if (compareStack(A, B))
    {
        if (topless(A) == topless(B))
        {
            printf("Stack sama\n");
        }
        else
        {
            printf("Stack tidak sama\n");
        }
    }
    else
    {
        printf("Stack tidak sama\n");
    }
    int i;
    printf("Isi stack dimulai dari top:\n");
    for (i = A.TOPTOWER; i >= 0; i--)
    {
        printf("%d\n", A.T[i]);
    }
    int *hasilpop;
    // pop stack
    PopTower(&A, hasilpop);
    printf("Isi stack setelah di pop dimulai dari top:\n");
    for (i = A.TOPTOWER; i >= 0; i--)
    {
        printf("%d\n", A.T[i]);
    }
    return 0;
}
