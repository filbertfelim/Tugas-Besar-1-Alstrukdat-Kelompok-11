// TODO :
// Snake Creation : Done (belum bug testing)
// Print Game Map : Done (belum bug testing)
// Validasi Movement Input : Done (belum bug testing)
// Snake Movement : Done (belum bug testing)
// Random Food Spawn : Almost done (Infinite loop saat tidak ada tempat kosong)
// Interaksi Snake dengan food (tambah panjang) : Done (belum bug testing)
// Fitur meteor dan interaksi meteor dengan snake : Not started
// Proses Game Over : Not fully done
// Skor : Not Started

#include <stdlib.h>
#include "SnakeOnMeteor.h"

Point GenerateRandomPos()
{
    Point P;
    P.posX = rand() % 5;
    P.posY = rand() % 5;
    return P;
}

boolean isInputValid(List Snake, char Movement)
{
    Point checkPos = Info(Head(Snake));
    if (Movement == 'W')
    {
        checkPos.posY--;
    }
    else if (Movement == 'S')
    {
        checkPos.posY++;
    }
    else if (Movement == 'A')
    {
        checkPos.posX--;
    }
    // Movement == 'D'
    else
    {
        checkPos.posX++;
    }
    if (Search(Snake, checkPos) == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CreateSnake(List *Snake, Point StartingPoint)
{
    CreateEmpty(Snake);
    Point tracker = StartingPoint;
    int i;
    for (i = 0; i < 3; i++)
    {
        if (tracker.posX < 0)
        {
            tracker.posX += 5;
        }
        InsVTail(Snake, tracker);
        tracker.posX -= 1;
    }
}

void PrintGame(List Snake, List Food)
{
    // Print Peta
    int i, count;
    Point iterator;
    count = 1;
    iterator.posX = 0;
    iterator.posY = 0;

    // Print Top Border
    for (i = 0; i < 49; i++)
    {
        printf("*");
    }
    printf("\n");
    printf("*");
    for (i = 0; i < 47; i++)
    {
        printf(" ");
    }
    printf("*\n");

    // Print Game Area
    for (i = 0; i < 25; i++)
    {
        if (i % 5 == 0)
        {
            printf("*\t");
        }
        if (Search(Snake, iterator) != Nil)
        {
            if (Search(Snake, iterator) == Head(Snake))
            {
                printf("H\t");
            }
            else
            {
                printf("%d\t", posInList(Snake, iterator));
            }

            if (i % 5 == 4)
            {
                printf("*\n");
            }
            count++;
        }
        else
        {
            if (Search(Food, iterator) != Nil)
            {
                printf("o\t");
            }
            else
            {
                printf("x\t");
            }

            if (i % 5 == 4)
            {
                printf("*\n");
            }
        }

        iterator.posX += 1;
        if (iterator.posX > 4)
        {
            iterator.posX = 0;
            iterator.posY += 1;
        }
    }

    // Print Bottom Border
    printf("*");
    for (i = 0; i < 47; i++)
    {
        printf(" ");
    }
    printf("*\n");
    for (i = 0; i < 49; i++)
    {
        printf("*");
    }
    printf("\n\n");
}

void SpawnMakanan(List Snake, List *Food)
{
    Point foodPos = GenerateRandomPos();
    while (Search(Snake, foodPos) != Nil)
    {
        foodPos = GenerateRandomPos();
    }
    InsVTail(Food, foodPos);
}

void ValidateMovementInput(char *Input, int *turn)
{
    while (str_len(Input) != 1)
    {
        printf("Masukkan gerakan tidak valid! Silakan masukkan ulang!\n");
        Input = STARTINPUT();
    }
    while (!(Input[0] != 'w' || Input[0] != 'a' || Input[0] != 's' || Input[0] != 'd'))
    {
        printf("Masukkan gerakan tidak valid! Silakan masukkan ulang!\n");
        Input = STARTINPUT();
    }
    turn++;
}

void MoveSnake(char Input, List *Snake)

{
    if (Input == 'W' || Input == 'w')
    {
        if (isInputValid(*Snake, 'W'))
        {
            AdjustBody(Snake);
            Info(Head(*Snake)).posY--;
        }
        else
        {
            printf("Masukkan tidak valid! Silakan masukkan input yang valid!\n");
        }
    }
    else if (Input == 'A' || Input == 'a')
    {
        if (isInputValid(*Snake, 'A'))
        {
            AdjustBody(Snake);
            Info(Head(*Snake)).posX--;
        }
        else
        {
            printf("Masukkan tidak valid! Silakan masukkan input yang valid!\n");
        }
    }
    else if (Input == 'S' || Input == 's')
    {
        if (isInputValid(*Snake, 'S'))
        {
            AdjustBody(Snake);
            Info(Head(*Snake)).posY++;
        }
        else
        {
            printf("Masukkan tidak valid! Silakan masukkan input yang valid!\n");
        }
    }
    else if (Input == 'D' || Input == 'd')
    {
        if (isInputValid(*Snake, 'D'))
        {
            AdjustBody(Snake);
            Info(Head(*Snake)).posX++;
        }
        else
        {
            printf("Masukkan tidak valid! Silakan masukkan input yang valid!\n");
        }
    }
    // Handling Position Overflow
    address loc = Head(*Snake);
    while (loc != Nil)
    {
        if (Info(loc).posX < 0)
        {
            Info(loc).posX = 4;
        }
        else if (Info(loc).posX > 4)
        {
            Info(loc).posX = 0;
        }
        else if (Info(loc).posY < 0)
        {
            Info(loc).posY = 4;
        }
        else if (Info(loc).posY > 4)
        {
            Info(loc).posY = 0;
        }

        loc = Next(loc);
    }
}

void AdjustBody(List *Snake)
{
    address loc = Tail(*Snake);
    while (Prev(loc) != Nil)
    {
        Info(loc) = Info(Prev(loc));
        loc = Prev(loc);
    }
}

void IsFoodHit(List *Snake, List Food, boolean *GameOver)
{
    boolean foodHit = false;
    Point headPos = Info(Head(*Snake));
    address loc = Head(Food);
    while (loc != Nil && !foodHit)
    {
        if (headPos.posX == Info(loc).posX && headPos.posY == Info(loc).posY)
        {
            foodHit = true;
        }
        loc = Next(loc);
    }

    if (foodHit)
    {
        Point oldTailPos = Info(Tail(*Snake));
        Point newTailPos;

        Point leftCheck = oldTailPos;
        Point rightCheck = oldTailPos;
        Point downCheck = oldTailPos;
        Point upCheck = oldTailPos;

        leftCheck.posX--;
        rightCheck.posX++;
        upCheck.posY--;
        downCheck.posY++;

        // Cek Kiri Tail
        if (leftCheck.posX >= 0 && Search(*Snake, leftCheck) != Nil)
        {
            // Cek Atas Tail
            if (upCheck.posY >= 0 && Search(*Snake, upCheck) != Nil)
            {
                // Cek Bawah Tail
                if (downCheck.posY <= 4 && Search(*Snake, downCheck) != Nil)
                {
                    if (rightCheck.posX <= 4 && Search(*Snake, rightCheck) != Nil)
                    {
                        (*GameOver) = true;
                    }
                    // Add sebelah kanan tail lama
                    else
                    {
                        InsVTail(Snake, rightCheck);
                    }
                }
                // Add di bawah tail lama
                else
                {
                    InsVTail(Snake, downCheck);
                }
            }
            // Add di atas tail lama
            else
            {
                InsVTail(Snake, upCheck);
            }
        }
        // Add di kiri
        else
        {
            InsVTail(Snake, leftCheck);
        }
    }
}

void RemoveSnakePart(List *Snake);

void SnakeOnMeteor()
{
    srand(time(NULL));
    char *movementInput;
    Point StartingPoint = GenerateRandomPos();
    List Snake;
    List Food;
    boolean isGameOver = false;
    int turn = 0;

    CreateEmpty(&Food);
    CreateSnake(&Snake, StartingPoint);
    printf("\n\n");
    while (!isGameOver)
    {
        printf("Turn: %d\n", turn);
        printf("=================================================\n");
        SpawnMakanan(Snake, &Food);
        PrintGame(Snake, Food);
        movementInput = STARTINPUT();
        ValidateMovementInput(movementInput, &turn);
        MoveSnake(movementInput[0], &Snake);
        IsFoodHit(&Snake, Food, &isGameOver);
    }
}