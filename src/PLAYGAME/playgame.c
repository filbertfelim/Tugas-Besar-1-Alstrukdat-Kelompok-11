#include "playgame.h"

void Play(intQueue *antrian, TabStr GameList){
    int temp;
    int gameNumber = antrian->buffer[0];
    char *toPlay = GameList.TI[gameNumber];
    if (compare_strings(toPlay, "RNG")){
        printf("Loading RNG....\n");
        rng();
    }
    else if (compare_strings(toPlay, "Diner Dash")){
        printf("Loading Diner Dash....\n");
        runDinnerDash();
    }
    else{
        printf("Game %s tidak dapat dimainkan. Silakan pilih game lain.\n", toPlay);
    }
    dequeue(antrian, temp);
}

void PlayGame(intQueue *antrian, TabStr GameList){
    printf("Berikut adalah daftar Game-mu: \n");
    if(!isEmpty(*antrian)){
        int i = 0;
        for (i; i < length(*antrian); i++){
            int gameNum = antrian->buffer[i];
            printf("%d. %s\n", i+1, GetElmt(GameList, gameNum));
        }
    }
    else{
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    if(!isEmpty(*antrian)){
        Play(antrian, GameList);
    }
    else{
        printf("Tidak ada permainan di dalam daftar Game-mu.\n");
    }
    

}