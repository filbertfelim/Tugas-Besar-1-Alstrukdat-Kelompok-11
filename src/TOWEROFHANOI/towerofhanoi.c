#include "towerofhanoi.h"

boolean isnumber(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
        i++;
    }
    if (i == 0)
    {
        return false;
    } else
    {
        return true;
    }
}

int optimalmoves(int x)
// menghitung jumlah langkah minimum yang dibutuhkan untuk menyelesaikan Tower of Hanoi dengan x disk
{
    if (x == 1)
    {
        return 1;
    }
    else
    {
        return 2 * optimalmoves(x - 1) + 1;
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

void displaytowerhanoi(int x, Stackhanoi A, Stackhanoi B, Stackhanoi C)
{
    for (int i = 0; i < x; i++)
    {
        int valA = A.T[x - i - 1];
        int valB = B.T[x - i - 1];
        int valC = C.T[x - i - 1];
        if (valA != 0)
        {
            blank(x - valA);
            stars(valA * 2 - 1);
            blank(x - valA);
        }
        else
        {
            blank(x - valA - 1);
            printf("|");
            if (x % 4 != 0)
                blank(x - valA);
            else
                blank(x - (valA)-1);
        }
        printf("\t");
        if (x % 4 == 0)
            printf("\t");
        if ((valB) != 0)
        {
            blank(x - (valB) + 1);
            stars((valB)*2 - 1);
            blank(x - (valB));
        }
        else
        {
            blank(x - (valB));
            printf("|");
            blank(x - (valB));
        }
        printf("\t");
        if ((valC) != 0)
        {
            blank(x - (valC) + 1);
            stars((valC)*2 - 1);
            blank(x - (valC));
        }
        else
        {
            blank(x - (valC));
            printf("|");
            blank(x - (valC));
        }
        printf("\n");
    }
    blank(x - 1);
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

void towerofhanoi(int *skor)
{
    Stackhanoi A, B, C, temp;
    int temp1, temp2, val1, val2, val3;
    int score, n;
    int count = 0;
    CreateEmptyStackTower(&A);
    CreateEmptyStackTower(&B);
    CreateEmptyStackTower(&C);
    CreateEmptyStackTower(&temp);
    printf("====================================================WELCOME TO============================================================\n");
    printf(" ________   ______   __       __  ________  _______    ______   ________  __    __   ______   __    __   ______   ______\n");
    printf("|       \\ /     \\ | \\  _  | \\|       \\|      \\  /     \\ |       \\| \\  | \\ /     \\ | \\  | \\ /     \\ |      \\\n");
    printf("\\$$$$$$$$|  $$$$$$\\| $$ /\\ | $$| $$$$$$$$| $$$$$$$\\|  $$$$$$\\| $$$$$$$$| $$  | $$|  $$$$$$\\| $$\\ | $$|  $$$$$$\\\\$$$$$$\n");
    printf(" | $$   | $$  | $$| $$/  $\\| $$| $$__    | $$__| $$| $$  | $$| $$__    | $$__| $$| $$__| $$| $$$\\| $$| $$  | $$  | $$\n");
    printf(" | $$   | $$  | $$| $$  $$$\\ $$| $$  \\   | $$    $$| $$  | $$| $$  \\   | $$    $$| $$    $$| $$$$\\ $$| $$  | $$  | $$\n");
    printf(" | $$   | $$  | $$| $$ $$\\$$\\$$| $$$$$   | $$$$$$$\\| $$  | $$| $$$$$   | $$$$$$$$| $$$$$$$$| $$\\$$ $$| $$  | $$  | $$\n");
    printf(" | $$   | $$__/ $$| $$$$  \\$$$$| $$_____ | $$  | $$| $$__/ $$| $$      | $$  | $$| $$  | $$| $$ \\$$$$| $$__/ $$ _| $$_\n");
    printf(" | $$    \\$$    $$| $$$    \\$$$| $$     \\| $$  | $$ \\$$    $$| $$      | $$  | $$| $$  | $$| $$  \\$$$ \\$$    $$|   $$\\\n");
    printf("  \\$$     \\$$$$$$  \\$$      \\$$ \\$$$$$$$$ \\$$   \\$$   \\$$$$$$  \\$$       \\$$   \\$$ \\$$   \\$$ \\$$   \\$$  \\$$$$$$  \\$$$$$$\n");
    // meminta masukkan jumlah disk
    printf("\n\n");
    printf("Selamat datang di Tower of Hanoi!\n");
    printf("Masukan jumlah disk: ");
    char *piringan;
    piringan = STARTINPUT();
    n = strtointinput(piringan, str_len(piringan));
    // mengecek apakah masukkan valid
    while (!isnumber(piringan))
    {

        printf("Masukan tidak valid, silahkan masukan kembali!!! \n");
        printf("Masukan jumlah disk: ");
        piringan = STARTINPUT();
        n = strtointinput(piringan, str_len(piringan));
    }

    printf("\n");
    printf("\n");

    for (int i = n; i > 0; i--)
    {
        PushTower(&A, i);
        PushTower(&temp, i);
    }
    // membandingkan stack
    while (!compareStack(C, temp))
    {
        displaytowerhanoi(n, A, B, C);
        printf("TOWER ASAL: ");
        char *str_asal;
        str_asal = STARTINPUT();
        // mengecek apakah masukkan valid
        if (str_asal[0] == 'A')
        {
            temp1 = 1;
        }
        else if (str_asal[0] == 'B')
        {
            temp1 = 2;
        }
        else if (str_asal[0] == 'C')
        {
            temp1 = 3;
        }
        else if (str_asal[0] == 'Q')
        {
            printf("Anda keluar dari permainan\n");
            skor[0] = 0;
            return;
        }
        else
        {
            printf("Masukan tidak valid, silahkan masukan kembali!!! \n");
            continue;
        }
        printf("TOWER TUJUAN: ");
        char *str_tujuan;
        str_tujuan = STARTINPUT();
        // mengecek apakah masukkan valid
        if (str_tujuan[0] == 'A')
        {
            temp2 = 1;
        }
        else if (str_tujuan[0] == 'B')
        {
            temp2 = 2;
        }
        else if (str_tujuan[0] == 'C')
        {
            temp2 = 3;
        }
        else if (str_asal[0] == 'Q')
        {
            printf("Anda keluar dari permainan\n");
            skor[0] = 0;
            return;
        }
        else
        {
            printf("Masukan tidak valid, silahkan masukan kembali!!! \n");
            continue;
        }
        printf("\n\n");
        int val1 = topless(A);
        int val2 = topless(B);
        int val3 = topless(C);
        if (temp1 == 1 && val1 != 0)
        {
            if (temp2 == 2)
            {
                if (val2 == 0 || val1 < val2)
                {
                    PopTower(&A, &temp1);
                    PushTower(&B, temp1);
                    count++;
                    // printf("%d %d", InfoTop(A), InfoTop(B));
                    printf("Memindahkan piringan ke B...\n");
                }
                else
                    printf("Tidak bisa dipindahkan\n");
            }
            else if (temp2 == 3)
            {
                if (val3 == 0 || val1 < val3)
                {
                    PopTower(&A, &temp1);
                    PushTower(&C, temp1);
                    count++;
                    printf("Memindahkan piringan ke C...\n");
                }
                else
                    printf("Tidak bisa dipindahkan\n");
            }
            else
                printf("Masukkan tidak valid\n");
        }
        else if (temp1 == 2 && val2 != 0)
        {
            if (temp2 == 1)
            {
                if (val1 == 0 || val2 < val1)
                {
                    PopTower(&B, &temp1);
                    PushTower(&A, temp1);
                    count++;
                    printf("Memindahkan piringan ke A...\n");
                }
                else
                    printf("Tidak bisa dipindahkan\n");
            }
            else if (temp2 == 3)
            {
                if (val3 == 0 || val2 < val3)
                {
                    PopTower(&B, &temp1);
                    PushTower(&C, temp1);
                    count++;
                    printf("Memindahkan piringan ke C...\n");
                }
                else
                    printf("Tidak bisa dipindahkan\n");
            }
            else
                printf("Masukkan tidak valid\n");
        }
        else if (temp1 == 3 && val3 != 0)
        {
            if (temp2 == 1)
            {
                if (val1 == 0 || val3 < val1)
                {
                    PopTower(&C, &temp1);
                    PushTower(&A, temp1);
                    count++;
                    printf("Memindahkan piringan ke A...\n");
                }
                else
                    printf("Tidak bisa dipindahkan\n");
            }
            else if (temp2 == 2)
            {
                if (val2 == 0 || val3 < val2)
                {
                    PopTower(&C, &temp1);
                    PushTower(&B, temp1);
                    count++;
                    printf("Memindahkan piringan ke B...\n");
                }
                else
                    printf("Tidak bisa dipindahkan\n");
            }
            else
                printf("Masukkan tidak valid\n");
        }
        else
            printf("Masukkan tidak valid\n");
    }
    displaytowerhanoi(n, A, B, C);
    score = ((optimalmoves(n) / count) * 10 * n / 5);
    printf("Score: %d\n", score);
    printf("SELAMAT KAMU BERHASIL!\n");
    *skor = score;
}
