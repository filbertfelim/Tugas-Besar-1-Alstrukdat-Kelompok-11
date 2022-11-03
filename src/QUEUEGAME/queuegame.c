#include "queuegame.h"

void QueueGame(strQueue *GameQueue, TabStr GameList)
{
    int nomorGame;
    // Menampilkan game dalam Queue
    printf("Berikut adalah daftar antrian game-mu: \n");
    if (!isQueueEmpty(*GameQueue))
    {
        int i;
        for (i = 0; i < lengthQueue(*GameQueue); i++)
        {
            printf("\t %d. %s\n", i + 1, GameQueue->buffer[i]);
        }
    }
    else
    {
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    // Menampilkan game yang tersedia
    LISTGAME(&GameList);

    // Meminta Input game yang akan dimasukkan ke antrian
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    char *numinput;
    numinput = STARTINPUT();
    nomorGame = strtointinput(numinput, str_len(numinput));

    // Tambah Game ke antrian
    while (nomorGame > NbElmt(GameList))
    {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n\n");
        printf("Nomor Game yang mau ditambahkan ke antrian: ");
        numinput = STARTINPUT();
        nomorGame = strtointinput(numinput, str_len(numinput));
    }
    STRenqueue(GameQueue, GameList.TI[nomorGame - 1]);
    printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
}