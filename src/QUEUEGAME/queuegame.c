#include "queuegame.h"

void QueueGame(intQueue *GameQueue, TabStr *GameList){
    int nomorGame;
    //Menampilkan game dalam Queue
    printf("Berikut adalah daftar antrian game-mu: \n");
    if(!isEmpty(*GameQueue)){
        int i = 0;
        for (i; i < length(*GameQueue); i++){
            int gameNum = GameQueue->buffer[i];
            printf("%d. %s\n", i+1, GetElmt(*GameList, gameNum));
        }
    }
    else{
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    //Menampilkan game yang tersedia
    LISTGAME(GameList);
    printf("\n");

    //Meminta Input game yang akan dimasukkan ke antrian
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    nomorGame = strtoint(STARTINPUT());

    //Tambah Game ke antrian
    while (nomorGame > NbElmt(*GameList)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        nomorGame = strtoint(STARTINPUT());
    }
    enqueue(GameQueue, nomorGame-1);
    printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");

}