#include "skipgame.h"

void SkipGame(intQueue *GameQueue, int n, TabStr GameList){
    //Menampilkan antrian Game
    printf("Berikut adalah daftar Game-mu: \n");
    if(!isEmpty(*GameQueue)){
        int i = 0;
        for (i; i < length(*GameQueue); i++){
            int gameNum = GameQueue->buffer[i];
            printf("%d. %s\n", i+1, GetElmt(GameList, gameNum));
        }
    }
    else{
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    //Proses Skip dengan dequeue dan play game setelah dequeue
    int tempDequeue;
    int i;
    for (i = 0; i < n; i++){
        if(!isEmpty(*GameQueue)){
            dequeue(GameQueue, &tempDequeue);
        }
    }

    if(!isEmpty(*GameQueue)){
        Play(GameQueue, GameList);
    }
    else{
        printf("Tidak ada permainan di dalam daftar Game-mu.\n");
    }
}