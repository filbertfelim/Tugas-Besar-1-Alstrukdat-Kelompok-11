#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tictactoe.h"

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void PrintBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkboard()
{
    int check = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                check--;
            }
        }
    }
    return check;
}

void resetboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void playermove()
{
    int x, y;
    do
    {
        printf("Masukan row(1-3): ");
        char *inputrow;
        inputrow = STARTINPUT();
        x = strtointinput(inputrow, str_len(inputrow));
        x--;
        printf("Masukan column(1-3): ");
        char *inputcolumn;
        inputcolumn = STARTINPUT();
        y = strtointinput(inputcolumn, str_len(inputcolumn));
        y--;
        if (board[x][y] != ' ')
        {
            printf("Masukan Tidak Valid\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}

void computermove()
{
    // random angka
    srand(time(0));
    int x, y;

    if (checkboard() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printwin(' ');
    }
}

char checkwin()
{
    // check row
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // check column
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // check diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}

void printwin(char winner)
{
    if (winner == PLAYER)
    {
        printf("Player Menang!\n");
    }
    else if (winner == COMPUTER)
    {
        printf("Computer Menang!\n");
    }
    else
    {
        printf("Permainan Seri!\n");
    }
}

void tictactoe(int *skor)
{
    printf("SELAMAT DATANG DI PERMAINAN TICTACTOE\n");
    int score;
    char winner = ' ';
    char response;
    winner = ' ';
    response = ' ';
    resetboard();
    while (winner == ' ' && checkboard() != 0)
    {
        PrintBoard();
        playermove();
        winner = checkwin();
        if (winner != ' ' || checkboard() == 0)
        {
            break;
        }
        computermove();
        winner = checkwin();
        if (winner != ' ' || checkboard() == 0)
        {
            break;
        }
    }
    PrintBoard();
    printwin(winner);
    if (winner == PLAYER)
    {
        score = 100;
    }
    else if (winner == COMPUTER)
    {
        score = 20;
    }
    else
    {
        score = 50;
    }
    printf("Skor : %d\n", score);
    *skor = score;
    printf("Terima Kasih telah bermain TICTACTOE!\n");
}
