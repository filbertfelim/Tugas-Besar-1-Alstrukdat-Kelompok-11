#include "playgame.h"

void Play(strQueue *antrian){
    char *temp;
    char *toPlay = antrian->buffer[0];
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
    STRdequeue(antrian, temp);
}

void PlayGame(strQueue *antrian){
    printf("Berikut adalah daftar Game-mu: \n");
    if(!isQueueEmpty(*antrian)){
        int i = 0;
        for (i; i < lengthQueue(*antrian); i++){
            printf("%d. %s\n", i+1, antrian->buffer[i]);
        }
    }
    else{
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    if(!isQueueEmpty(*antrian)){
        Play(antrian);
    }
    else{
        printf("Tidak ada permainan di dalam daftar Game-mu.\n");
    }
    

}