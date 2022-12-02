// TODO :
// Snake Creation : Done (belum bug testing)
// Print Game Map : Done (belum bug testing)
// Validasi Movement Input : Done (belum bug testing)
// Snake Movement : Done (belum bug testing)
// Random Food Spawn : Almost done (Infinite loop saat tidak ada tempat kosong)
// Interaksi Snake dengan food (tambah panjang) : Done (belum bug testing)
// Fitur meteor dan interaksi meteor dengan snake : Harusnya udah Done (belum bug testing)
// Proses Game Over : Done (Harusnya) (belum bug testing)
// Skor : Done

#include <stdlib.h>
#include "SnakeOnMeteor.h"

Point GenerateRandomPos()
{
    Point P;
    P.posX = rand() % 5;
    P.posY = rand() % 5;
    return P;
}

int isInputValid(List Snake, char Movement, List Meteor)
{
    Point checkPos = Info(Head(Snake));
    if (Movement == 'W')
    {
        checkPos.posY--;
        if (checkPos.posY < 0)
        {
            checkPos.posY = 4;
        }
    }
    else if (Movement == 'S')
    {
        checkPos.posY++;
        if (checkPos.posY > 4)
        {
            checkPos.posY = 0;
        }
    }
    else if (Movement == 'A')
    {
        checkPos.posX--;
        if (checkPos.posX < 0)
        {
            checkPos.posX = 4;
        }
    }
    // Movement == 'D'
    else
    {
        checkPos.posX++;
        if (checkPos.posX > 4)
        {
            checkPos.posX = 0;
        }
    }
    // Meteor Flag = 1, Snake Flag = 2
    if (Search(Meteor, checkPos) != ListNil)
    {
        return 1;
    }
    else if (Search(Snake, checkPos) != ListNil)
    {
        return 2;
    }
    else if (Search(Snake, checkPos) == ListNil && Search(Meteor, checkPos) == ListNil)
    {
        return 0;
    }
}

void CreateSnake(List *Snake, Point StartingPoint)
{
    CreateListEmpty(Snake);
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

void PrintGameSnake(List Snake, List Food, List Meteor, List Obstacles, int turn)
{
    // Print Peta
    int i, count, j;
    Point iterator;
    count = 1;
    iterator.posX = 0;
    iterator.posY = 0;

    // Print Top Border
    for (i = 0; i < 81; i++)
    {
        printf("-");
    }
    printf("\n");

    // Print Game Area
    for (i = 0; i < 25; i++)
    {
        if (i % 5 == 0)
        {
            printf("|");
        }
        if (Search(Meteor, iterator) != ListNil)
        {
            red();
            printf("\tM\t");
            reset();
            printf("|");
            if (i % 5 == 4)
            {
                printf("\n");
                for (j = 0; j < 81; j++)
                {
                    printf("-");
                }
                printf("\n");
            }
        }
        else if (Search(Obstacles, iterator) != ListNil)
        {
            cyan();
            printf("\tX\t");
            reset();
            printf("|");
            if (i % 5 == 4)
            {
                printf("\n");
                for (j = 0; j < 81; j++)
                {
                    printf("-");
                }
                printf("\n");
            }
        }
        else if (Search(Snake, iterator) != ListNil)
        {
            if (Search(Snake, iterator) == Head(Snake))
            {
                green();
                printf("\tH\t");
                reset();
                printf("|");
            }
            else
            {
                green();
                printf("\t%d\t", posInList(Snake, iterator));
                reset();
                printf("|");
            }

            if (i % 5 == 4)
            {
                printf("\n");
                for (j = 0; j < 81; j++)
                {
                    printf("-");
                }
                printf("\n");
            }
            count++;
        }
        else
        {
            if (Search(Food, iterator) != ListNil)
            {
                yellow();
                printf("\to\t");
                reset();
                printf("|");
            }
            else
            {
                printf("\t \t|");
            }

            if (i % 5 == 4)
            {
                printf("\n");
                for (j = 0; j < 81; j++)
                {
                    printf("-");
                }
                printf("\n");
            }
        }

        iterator.posX += 1;
        if (iterator.posX > 4)
        {
            iterator.posX = 0;
            iterator.posY += 1;
        }
    }
    printf("\n");
}

void SpawnObstacle(List *Obstacle, List Snake, int numberOfObstacles)
{
    int i;
    for (i = 0; i < numberOfObstacles; i++)
    {
        Point newObstaclePos = GenerateRandomPos();
        while (Search(*Obstacle, newObstaclePos) != ListNil || Search(Snake, newObstaclePos) != ListNil)
        {
            newObstaclePos = GenerateRandomPos();
        }
        InsVTail(Obstacle, newObstaclePos);
    }
}

void IsObstacleHit(List Snake, List Obstacle, boolean *GameOver, int *loseFlag)
{
    addresslist loc = Head(Obstacle);
    while (loc != ListNil && !(*GameOver))
    {
        if (Search(Snake, Info(loc)) != ListNil)
        {
            *GameOver = true;
            (*loseFlag) = 3;
        }
        else
        {
            loc = Next(loc);
        }
    }
}

void SpawnMakanan(List Snake, List *Food, List Meteor, List Obstacles)
{
    if (IsListEmpty(*Food))
    {
        Point foodPos = GenerateRandomPos();
        // Cek apakah ada bagian snake atau makanan di posisi yang dihasilkan
        while (Search(Snake, foodPos) != ListNil || Search(Obstacles, foodPos) != ListNil || Search(*Food, foodPos) != ListNil || Search(Meteor, foodPos) != ListNil)
        {
            foodPos = GenerateRandomPos();
        }
        InsVTail(Food, foodPos);
    }
}

char ValidateMovementInput(char *Input, List Snake, List Meteor, int turn)
{
    boolean valid = false;
    char movementKey;
    while (!valid)
    {
        while (str_len(Input) != 1)
        {
            printf("Command tidak valid! Silakan input command menggunakan huruf w/a/s/d\n\n");
            printf("Turn %d:\n", turn);
            printf("Silakan masukkan command Anda: ");
            // Input = '\0';
            Input = STARTINPUT();
        }
        while (!(Input[0] == 'w' || Input[0] == 'a' || Input[0] == 's' || Input[0] == 'd'))
        {
            printf("Command tidak valid! Silakan input command menggunakan huruf w/a/s/d\n\n");
            // Input = '\0';
            printf("Turn %d:\n", turn);
            printf("Silakan masukkan command Anda: ");
            Input = STARTINPUT();
        }
        movementKey = Input[0];
        if (movementKey == 'W' || movementKey == 'w')
        {
            if (isInputValid(Snake, 'W', Meteor) == 0)
            {
                valid = true;
            }
        }
        else if (movementKey == 'A' || movementKey == 'a')
        {
            if (isInputValid(Snake, 'A', Meteor) == 0)
            {
                valid = true;
            }
        }
        else if (movementKey == 'S' || movementKey == 's')
        {
            if (isInputValid(Snake, 'S', Meteor) == 0)
            {
                valid = true;
            }
        }
        else if (movementKey == 'D' || movementKey == 'd')
        {
            if (isInputValid(Snake, 'D', Meteor) == 0)
            {
                valid = true;
            }
        }
        if (!valid)
        {
            char capitalizeMovKey = movementKey - 32;
            if (isInputValid(Snake, capitalizeMovKey, Meteor) == 1)
            {
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut!\n");
            }
            else if (isInputValid(Snake, capitalizeMovKey, Meteor) == 2)
            {
                printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\n");
            }
            printf("Silakan input command yang lain!\n\n");
            // Input = '\0';
            printf("Silakan masukkan command Anda: ");
            Input = STARTINPUT();
        }
    }
    return movementKey;
}

void MoveSnake(char Input, List *Snake, int *turn)
{
    if (Input == 'W' || Input == 'w')
    {

        AdjustBody(Snake);
        Info(Head(*Snake)).posY--;
        (*turn)++;
    }
    else if (Input == 'A' || Input == 'a')
    {

        AdjustBody(Snake);
        Info(Head(*Snake)).posX--;
        (*turn)++;
    }
    else if (Input == 'S' || Input == 's')
    {
        AdjustBody(Snake);
        Info(Head(*Snake)).posY++;
        (*turn)++;
    }
    else if (Input == 'D' || Input == 'd')
    {

        AdjustBody(Snake);
        Info(Head(*Snake)).posX++;
        (*turn)++;
    }
    HandlePosOverflow(Snake);
    printf("Berhasil bergerak!\n");
}

void HandlePosOverflow(List *Snake)
{
    addresslist loc = Head(*Snake);
    while (loc != ListNil)
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
    addresslist loc = Tail(*Snake);
    while (Prev(loc) != ListNil)
    {
        Info(loc) = Info(Prev(loc));
        loc = Prev(loc);
    }
}

void IsFoodHit(List *Snake, List *Food, boolean *GameOver, int *snakeLength, int *loseFlag)
{
    boolean foodHit = false;
    Point headPos = Info(Head(*Snake));
    addresslist loc = Head(*Food);
    while (loc != ListNil && !foodHit)
    {
        if (headPos.posX == Info(loc).posX && headPos.posY == Info(loc).posY)
        {
            foodHit = true;
        }
        else
        {
            loc = Next(loc);
        }
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
        if (leftCheck.posX >= 0 && Search(*Snake, leftCheck) != ListNil)
        {
            // Cek Atas Tail
            if (upCheck.posY >= 0 && Search(*Snake, upCheck) != ListNil)
            {
                // Cek Bawah Tail
                if (downCheck.posY <= 4 && Search(*Snake, downCheck) != ListNil)
                {
                    if (rightCheck.posX <= 4 && Search(*Snake, rightCheck) != ListNil)
                    {
                        (*GameOver) = true;
                        (*loseFlag) = 2;
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
        (*snakeLength)++;
        HandlePosOverflow(Snake);
        // Hapus makanan karena sudah dimakan
        DelP(Food, Info(loc));
    }
}

void IsStuck(List Snake, List Meteor, boolean *isGameOver, int *loseFlag)
{
    addresslist loc = Head(Snake);
    Point toCheckRight = Info(loc);
    Point toCheckLeft = Info(loc);
    Point toCheckUp = Info(loc);
    Point toCheckDown = Info(loc);
    toCheckRight.posX++;
    toCheckLeft.posX--;
    toCheckUp.posY--;
    toCheckDown.posY++;
    if (toCheckRight.posX > 4)
    {
        toCheckRight.posX = 0;
    }
    if (toCheckLeft.posX < 0)
    {
        toCheckLeft.posX = 4;
    }
    if (toCheckUp.posY < 0)
    {
        toCheckUp.posY = 4;
    }
    if (toCheckDown.posY > 4)
    {
        toCheckDown.posY = 0;
    }

    if ((Search(Meteor, toCheckLeft) || Search(Snake, toCheckLeft)) && (Search(Meteor, toCheckRight) || Search(Snake, toCheckRight)) && (Search(Meteor, toCheckUp) || Search(Snake, toCheckUp)) && (Search(Meteor, toCheckDown) || Search(Snake, toCheckDown)))
    {
        (*isGameOver) = true;
        (*loseFlag) = 4;
    }
}

void SpawnMeteor(List *Meteor)
{
    Point meteorPos = GenerateRandomPos();
    InsVTail(Meteor, meteorPos);
}

void IsMeteorHit(List *Snake, List Meteor, boolean *GameOver, boolean *hitbyMeteor, int *loseFlag)
{
    addresslist loc = Head(Meteor);
    if (loc != ListNil)
    {
        if (Search(*Snake, Info(loc)) != ListNil)
        {
            if (Info(loc).posX == Info(Head(*Snake)).posX && Info(loc).posY == Info(Head(*Snake)).posY)
            {
                *GameOver = true;
                *loseFlag = 1;
            }
            (*hitbyMeteor) = true;
        }
    }
}

void GameUpdate(List *Snake, List *Food, List *Meteor, List Obstacles, boolean *isGameOver, int *turn, int *snakeLength, int *loseFlag)
{
    boolean hitByMeteor = false;
    listinfotype tempPos;
    char *movementInput;
    int i;

    if (*turn > 1)
    {
        SpawnMakanan(*Snake, Food, *Meteor, Obstacles);
    }
    IsStuck(*Snake, *Meteor, isGameOver, loseFlag);
    if (*isGameOver)
    {
        return;
    }
    if (*turn != 0)
    {
        printf("Turn: %d\n", *turn);
    }
    printf("Silakan masukkan command Anda: ");
    movementInput = STARTINPUT();
    MoveSnake(ValidateMovementInput(movementInput, *Snake, *Meteor, *turn), Snake, turn);
    // Delete Meteor Lama
    if (!IsListEmpty(*Meteor))
    {
        DelVTail(Meteor, &tempPos);
    }
    // Tambah Meteor Baru
    if (*turn > 1)
    {
        SpawnMeteor(Meteor);
    }
    IsObstacleHit(*Snake, Obstacles, isGameOver, loseFlag);
    if (*isGameOver)
    {
        return;
    }
    IsFoodHit(Snake, Food, isGameOver, snakeLength, loseFlag);
    if (*turn > 1)
    {
        SpawnMakanan(*Snake, Food, *Meteor, Obstacles);
    }
    IsMeteorHit(Snake, *Meteor, isGameOver, &hitByMeteor, loseFlag);
    printf("Berikut merupakan peta permainan: \n");
    for (i = 0; i < 81; i++)
    {
        printf("=");
    }
    printf("\n");
    PrintGameSnake(*Snake, *Food, *Meteor, Obstacles, *turn);
    if (hitByMeteor && (*isGameOver == false))
    {
        addresslist loc = Head(*Meteor);
        boolean found = false;
        while (loc != ListNil && !found)
        {
            if (Search(*Meteor, Info(loc)) != ListNil)
            {
                found = true;
            }
            else
            {
                loc = Next(loc);
            }
        }
        DelP(Snake, Info(loc));
        (*snakeLength)--;
        printf("Anda terkena meteor!\n");
        printf("Berikut merupakan peta permainan sekarang\n");
        PrintGameSnake(*Snake, *Food, *Meteor, Obstacles, *turn);
    }
    else if (!hitByMeteor)
    {
        printf("Anda beruntung tidak terkena meteor! Silakan lanjutkan permainan\n");
        printf("-----------------------------------------------------------------\n");
    }
}

void SnakeOnMeteor(int *score)
{
    srand(time(NULL));
    char *movementInput;
    Point StartingPoint = GenerateRandomPos();
    List Snake;
    List Food;
    List Meteor;
    List Obstacles;
    boolean isGameOver = false;
    int turn = 0;
    int skor = 0;
    int snakeLength = 3;
    int loseFlag = 0; // 1 = Kepala terkena meteor, 2 = Tidak bisa spawn ekor, 3 = Nabrak Obstacle
    listinfotype tempPos;

    CreateListEmpty(&Food);
    CreateSnake(&Snake, StartingPoint);
    CreateListEmpty(&Meteor);
    CreateListEmpty(&Obstacles);
    printf("\n\n");
    while (!isGameOver)
    {
        if (turn == 0)
        {
            printf("===================================== W E L C O M E   T O =======================================\n");
            printf(" ___    _   _  _____  ___    _   _     _____  _   _     _   _  ___   _____  ___    _____  ___   \n");
            printf("(  _`\\ ( ) ( )(  _  )(  _`\\ ( ) ( )   (  _  )( ) ( )   /'\\_/`\\(  _`\\(_   _)(  _`\\ (  _  )|  _`\\ \n");
            printf("| (_(_)| `\\| || (_) || ( (_)| |/'/'   | ( ) || `\\| |   |     || (_(_) | |  | (_(_)| ( ) || (_) ) \n");
            printf("`\\__ \\ | , ` ||  _  || |  _ | , <     | | | || , ` |   | (_) ||  _)_  | |  |  _)_ | | | || ,  / \n");
            printf("( ))_)|| | |`||| | ||| (_( )| |\\`\\    | (_) || |`\\ |   | | | || (_( ) | |  | (_( )| (_) || |\\ \\ \n");
            printf("`\\____)(_) (_)(_) (_)(____/'(_) (_)   (_____)(_) (_)   (_) (_)(____/' (_)  (____/'(_____)(_) (_) \n\n");
            printf("Mengenerate peta, snake, dan makanan...\n\n");
            SpawnObstacle(&Obstacles, Snake, 1);
            SpawnMakanan(Snake, &Food, Meteor, Obstacles);
            printf("Berhasil digenerate!\n");
            printf("Berikut merupakan peta permainan\n");
            PrintGameSnake(Snake, Food, Meteor, Obstacles, turn);
            printf("\n");
            turn++;
        }
        GameUpdate(&Snake, &Food, &Meteor, Obstacles, &isGameOver, &turn, &snakeLength, &loseFlag);
        if (isGameOver == true)
        {
            skor += 2 * snakeLength;
            if (snakeLength == 0)
            {
                printf("Panjang snake anda 0! Permainan berakhir!\n");
            }
            else if (loseFlag == 1)
            {
                printf("Kepala snake anda terkena meteor! Permainan berakhir!\n");
                skor -= 2;
            }
            else if (loseFlag == 2)
            {
                printf("Ekor tidak dapat ditambahkan! Permainan berakhir!\n");
            }
            else if (loseFlag == 3)
            {
                printf("Anda menabrak obstacle! Permainan berakhir!\n");
            }
            else if (loseFlag == 4)
            {
                printf("Anda tidak dapat bergerak kemanapun! Permainan berakhir!\n");
            }
            printf("Skor Anda: %d\n", skor);
            (*score) = skor;
            break;
        }
    }
}