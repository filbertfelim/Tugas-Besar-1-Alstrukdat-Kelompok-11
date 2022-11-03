#include "queuegame.h"

void QueueGame(strQueue *GameQueue, TabStr GameList){
    int nomorGame;
    //Menampilkan game dalam Queue
    printf("Berikut adalah daftar antrian game-mu: \n");
    if(!isQueueEmpty(*GameQueue)){
        int i = 0;
        for (i; i < lengthQueue(*GameQueue); i++){
            printf("%d. %s\n", i+1, GameQueue->buffer[i]);
        }
    }
    else{
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    //Menampilkan game yang tersedia
    LISTGAME(&GameList);
    printf("\n");

    //Meminta Input game yang akan dimasukkan ke antrian
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    nomorGame = strtoint(STARTINPUT());

    //Tambah Game ke antrian
    while (nomorGame > NbElmt(GameList)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        nomorGame = strtoint(STARTINPUT());
    }
    STRenqueue(GameQueue, GameList.TI[nomorGame - 1]);
    printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");

}