#include "playgame.h"

void Play(strQueue *antrian, TabStr listgame, TabMap *arr_sb)
{
    gamename temp;
    int skor;
    char *toPlay = antrian->buffer[antrian->idxHead];
    if (compare_strings(toPlay, "RNG"))
    {
        printf("Loading RNG....\n");
        rng(&skor);
    }
    else if (compare_strings(toPlay, "Diner DASH"))
    {
        printf("Loading Diner Dash....\n");
        dinerdash(&skor);
    }
    else if (compare_strings(toPlay, "TICTACTOE"))
    {
        printf("Loading TICTACTOE....\n");
        tictactoe(&skor);
    }
    else
    {
        srand(time(NULL));
        skor = rand() % 100 + 1;
        printf("Skor : %d\n", skor);
    }
    char *name;
    printf("Nama : ");
    name = STARTINPUT();
    int idxgame = 0;
    while (!compare_strings(listgame.TI[idxgame], toPlay))
    {
        idxgame++;
    };
    while (IsMember((*arr_sb).TIMap[idxgame], name))
    {
        printf("Nama sudah ada, silahkan memakai nama lain!\n\n");
        printf("Nama : ");
        name = STARTINPUT();
    }
    Insert(&(*arr_sb).TIMap[idxgame], name, skor);
    SortMapValueDesc(&(*arr_sb).TIMap[idxgame]);
    printf("Skor berhasil disimpan ke dalam scoreboard.\n\n");
    STRdequeue(antrian, temp);
}
/*Memainkan Game pada urutan teratas*/

void PlayGame(strQueue *antrian, TabStr listgame, TabMap *arr_sb)
{
    printf("Berikut adalah daftar Game-mu: \n");
    if (!isQueueEmpty(*antrian))
    {
        int i;
        int listNum = 0;
        for (i = antrian->idxHead; i < (antrian->idxHead + lengthQueue(*antrian)); i++)
        {
            printf("%d. %s\n", listNum + 1, antrian->buffer[i]);
            listNum++;
        }
    }
    else
    {
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    if (!isQueueEmpty(*antrian))
    {
        Play(antrian, listgame, arr_sb);
    }
    else
    {
        printf("Tidak ada permainan di dalam daftar Game-mu.\n");
    }
}
/*Menampilkan game dalam antrian kemudian memainkan game pada urutan teratas*/