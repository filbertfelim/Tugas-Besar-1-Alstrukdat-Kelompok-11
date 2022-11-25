#include "towerofhanoi.h"

int optimalmoves(int x)
// menghitung jumlah langkah minimum yang dibutuhkan untuk menyelesaikan Tower of Hanoi dengan x disk
{
    if (i == 1)
    {
        return 1;
    }
    else
    {
        return 2 * optimalmoves(i - 1) + 1;
    }
}
// optimalmoves/jumlah gerak * 10 * n/5

void blank(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf(" ");
    }
}

void stars(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("*");
    }
}

void displaytowerhanoi(int x, Stack A, Stack B, Stack C)
{
    for (int i = 0; i < x; i++)
    {
        int valA = A.T[x-i-1];
        int valB = B.T[x-i-1];
        int valC = C.T[x-i-1];
        if (valA != 0)
        {
            blank(x - valA);
            stars(valA * 2 - 1);
            blank(x - valA);
        }
        else
        {
            blank(x - valA-1);
            printf("|");
            if (x % 4 != 0)blank(x - valA);
            else
            blank(x - valA - 1);
        }
        printf("\t");
        if (x % 4 == 0) printf("\t");
        if (valB != 0)
        {
            blank(x - valB+1);
            stars(valB * 2 - 1);
            blank(x - valB);
        }
        else
        {
            blank(x - valB);
            printf("|");
            blank(x - valB);
        }
        printf("\t");
        if (valC != 0)
        {
            blank(x - valC + 1);
            stars(valC * 2 - 1);
            blank(x - valC);
        }
        else
        {
            blank(x - valC);
            printf("|");
            blank(x - valC);
        }
        printf("\n");
    }
    blank(x-1);
    printf("A");
    blank(x);
    printf("\t");
    blank(x);
    printf("B");
    blank(x);
    printf("\t");
    blank(x);
    printf("C");
    blank(x);
    printf("\n\n");
}

void towerofhanoi()
{
    Stack A, B, C, temp;
    int temp1, temp2, val1, val2, val3;
    int score, n;
    int count = 0;
    CreateEmptyStack(&A);
    CreateEmptyStack(&B);
    CreateEmptyStack(&C);
    
    char *piringan;
    printf("Masukan jumlah disk: ");
    piringan = STARTINPUT();
    printf("\n");
    n = strtointinput(piringan, str_len(piringan));
    for (int i = n; i > 0; i--)
    {
        Push(&A, i);
        Push(&B, 0);
        Push(&C, 0);
    }
    temp = A;
    
    while(!compareStack(C, temp))
    {
        displaytowerhanoi(n, A, B, C);
        printf("TOWER ASAL: ");
        char *str_asal;
        str_asal = STARTINPUT();
        temp1 = strtointinput(str_asal, str_len(str_asal));
        
        printf("TOWER TUJUAN: ");
        char * str_tujuan;
        str_tujuan = STARTINPUT();
        printf("\n\n");
        temp2 = strtointinput(str_tujuan, str_len(str_tujuan));
        
        val1 = InfoTop(A);
        val2 = InfoTop(B);
        val3 = InfoTop(C);
        if (temp1 == 1 && val1 != 0)
        {
            if (temp2 == 2)
            {
                if (val2 == 0 || val1 < val2)
                {
                    Pop(&A, &temp1);
                    Push(&B, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else if (temp2 == 3)
            {
                if (val3 == 0 || val1 < val3)
                {
                    Pop(&A, &temp1);
                    Push(&C, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else printf("Masukkan tidak valid\n");
        }
        else if (temp1 == 2&& val2 != 0)
        {
            if (temp2 == 1)
            {
                if (val1 == 0 || val2 < val1)
                {
                    Pop(&B, &temp1);
                    Push(&A, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else if (temp2 == 3)
            {
                if (val3 == 0 || val2 < val3)
                {
                    Pop(&B, &temp1);
                    Push(&C, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else printf("Masukkan tidak valid\n");
        }
        else if (temp1 == 3 && val3 != 0)
        {
            if (temp2 == 1)
            {
                if (val1 == 0 || val3 < val1)
                {
                    Pop(&C, &temp1);
                    Push(&A, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else if (temp2 == 2)
            {
                if (val2 == 0 || val3 < val2)
                {
                    Pop(&C, &temp1);
                    Push(&B, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else printf("Masukkan tidak valid\n");
        }
        else printf("Masukkan tidak valid\n");
    }
    displaytowerhanoi(n, A, B, C);
    score = ((optimalmoves(n) / count) * 10 * n/5);
    printf("Score: %d\n", score);
    printf("SELAMAT ANDA MENANG!\n");
}

int main()
{
    towerofhanoi();
    return 0;
}