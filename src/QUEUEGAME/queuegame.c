#include "queuegame.h"

void QueueGame(Queue *GameQueue, TabStr GameList){
    int nomorGame;
    //Menampilkan game dalam Queue
    printf("Berikut adalah daftar antrian game-mu: \n");
    if(!isEmpty(*GameQueue)){
        int i = 0;
        for (i; i < length(*GameQueue); i++){
            printf("%d. %s\n", i+1, GameQueue->buffer[i]);
        }
    }
    else{
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    //Menampilkan game yang tersedia
    printf("Berikut adalah daftar game yang tersedia: \n");
    if(!IsEmpty(GameList)){
        int i;
        for (i = 1; i <= NbElmt(GameList); i++){
            printf("%d. %s\n", i, GetElmt(GameList, i));
        }
    }
    printf("\n");

    //Meminta Input game yang akan dimasukkan ke antrian
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    scanf("%d", &nomorGame);

    //Tambah Game ke antrian
    if (nomorGame > NbElmt(GameList)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
    else{
        enqueue(GameQueue, GetElmt(GameList, nomorGame));
        printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
    }

}