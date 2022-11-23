#include "../TOWEROFHANOI/towerofhanoi.h"

void scoredisplay(int step, int *score)
{
    int x = 100;
    if (step > 31)
    {
        step -= 31;
        while (step>0)
        {
            step -= 3;
            x --;
        }
    }
    if (x < 0)
    {
        x = 0;
    }
    *score = x;
}

void checkmoves(char t1, char t2, stack A, Stack B, Stack C, boolean *check)
{
    if ((t1 == 'A' || t1 == 'B' || t1 == 'C') && (t2 == 'A' || t2 == 'B' || t2 == 'C'))
    {
        if (t1 != t2)
        {
            if (t1 == 'A')
            {
                if (IsStackEmptyH(A))
                {
                    printf("Tidak ada piringan di tower A\n");
                }
                else
                {
                    if (t2 == 'B')
                    {
                        if (IsStackEmptyH(B))
                        {
                            *check = true;
                        }
                        else
                        {
                            if (InfoTop(A).elhanoi < InfoTop(B).elhanoi)
                            {
                                *check = true;
                            }
                            else
                            {
                                printf("Piringan tidak bisa dipindahkan ke tower B\n");
                            }
                        }
                    }
                    else
                    {
                        if (IsStackEmptyH(C))
                        {
                            *check = true;
                        }
                        else
                        {
                            if (InfoTop(A).elhanoi < InfoTop(C).elhanoi)
                            {
                                *check = true;
                            }
                            else
                            {
                                printf("Piringan tidak bisa dipindahkan ke tower C\n");
                            }
                        }
                    }
                }
            }
            else if (t1 == 'B')
            {
                if (IsStackEmptyH(B))
                {
                    printf("Tidak ada piringan di tower B\n");
                }
                else
                {
                    if (t2 == 'A')
                    {
                        if (IsStackEmptyH(A))
                        {
                            *check = true;
                        }
                        else
                        {
                            if (InfoTop(B).elhanoi < InfoTop(A).elhanoi)
                            {
                                *check = true;
                            }
                            else
                            {
                                printf("Piringan tidak bisa dipindahkan ke tower A\n");
                            }
                        }
                    }
                    else
                    {
                        if (IsStackEmptyH(C))
                        {
                            *check = true;
                        }
                        else
                        {
                            if (InfoTop(B).elhanoi < InfoTop(C).elhanoi)
                            {
                                *check = true;
                            }
                            else
                            {
                                printf("Piringan tidak bisa dipindahkan ke tower C\n");
                            }
                        }
                    }
                }
            }
            else 
            {
                if (IsStackEmptyH(C))
                {
                    printf("Tidak ada piringan di tower C\n");
        
                }
                else 
                {
                    if(t2 == 'B')
                    {
                        if (IsStackEmptyH(B))
                        {
                            *check = true;
                        }
                        else
                        {
                            if (InfoTop(C).elhanoi < InfoTop(B).elhanoi)
                            {
                                *check = true;
                            }
                            else
                            {
                                printf("Piringan tidak bisa dipindahkan ke tower B\n");
                            }
                        }
                    }
                    else
                    {
                        if (IsStackEmptyH(A))
                        {
                            *check = true;
                        }
                        else
                        {
                            if (InfoTop(C).elhanoi < InfoTop(A).elhanoi)
                            {
                                *check = true;
                            }
                            else
                            {
                                printf("Piringan tidak bisa dipindahkan ke tower A\n");
                            }
                        }
                    }
                }
            }
        }
    }
}

boolean checkwin(Stack C)
{
    Stack temp;
    CreateEmptyH(&temp);
    PushH(&temp,"*********" 5);
    PushH(&temp," ******* " 4);
    PushH(&temp,"  *****  " 3);
    PushH(&temp,"   ***   " 2);
    PushH(&temp,"    *    " 1);

    // compare stack C and temp
    boolean win = true;
    while (!IsStackEmptyH(temp) && win)
    {
        if (InfoTop(C).elhanoi != InfoTop(temp).elhanoi)
        {
            win = false;
        }
        PopH(&C);
        PopH(&temp);
    }
    return win;
}
void displaytowerhanoi(Stack A, Stack B, Stack C)
{
    int i = MaxEl - 1;
    while (i >= 0)
    {
        printf("%s", A.T[i].tower);
        printf("%s", B.T[i].tower);
        printf("%s", C.T[i].tower);
    }
    printf("--------");
    printf("--------");
    printf("--------\n");
    printf("  A  ");
    printf("  B  ");
    printf("  C  \n");
}

void towerofhanoi()
{
    int count = 0;
    int score = 0;

    Stack A, B, C;
    CreateEmptyStackH(&A);
    CreateEmptyStackH(&B);
    CreateEmptyStackH(&C);

    PushH(&A, "*********", 5);
    PushH(&A, " ******* ", 4);
    PushH(&A, "  *****  ", 3);
    PushH(&A, "   ***   ", 2);
    PushH(&A, "    *    ", 1);

    int i = 0;
    while (i < MaxEl)
    {
        B.T[i].tower = "   |   ";
        B.T[i].elhanoi = 6;
        C.T[i].tower = "   |   ";
        C.T[i].elhanoi = 6;
        i++;
    }

    displaytowerhanoi(A, B, C);

    boolean done = false;
    while (!finish)
    {
        boolean valid = false
        char T1, T2;
        while (!valid)
        {
            printf("\n");
            printf("tower awal: ");
            // inputan
            scanf("%c", &T1);
            printf("\n");
            // simpen towernya

            printf("tower tujuan: ");
            // inputan
            scanf("%c", &T2);
            printf("\n");
            // simpen towernya

            //cek valid
            checkmoves(T1, T2, A, B, C &valid);

        }
        count++;
        ElHanoi temp;
        if (T1 == 'A')
        {
            PopH(&A, &temp);
        }
        else if (T1 == 'B')
        {
            PopH(&B, &temp);
        }
        else if (T1 == 'C')
        {
            PopH(&C, &temp);
        }
        if (T2 == 'A')
        {
            printf("\n");
            printf("memindahkan ke tower A\n");
            printf("\n");
            PushH(&A, temp.tower, temp.elhanoi);
        }
        else if (T2 == 'B')
        {
            printf("\n");
            printf("memindahkan ke tower B\n");
            printf("\n");
            PushH(&B, temp.tower, temp.elhanoi);
        }
        else if (T2 == 'C')
        {
            printf("\n");
            printf("memindahkan ke tower C\n");
            printf("\n");
            PushH(&C, temp.tower, temp.elhanoi);
        }
        displaytowerhanoi(A, B, C);

        if (checkwin(C))
        {
            finish = true;
        }
    }

    //score
    scores(count, &score);
    printf("Kamu berhasil\n");
    printf("Score kamu: %d\n", score);
}

int main()
{
    towerofhanoi();
    return 0;
}

