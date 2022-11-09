#include "strQueue.h"
#include <stdio.h>

int main(){
    strQueue Q;
    gamename temp;
    int length;

    //Tes Create Queue & Primitif isEmpty
    CreateStrQueue(&Q);
    if (isQueueEmpty(Q)){
        printf("Queue Empty\n");
    }

    //Tes Enqueue & length
    STRenqueue(&Q, "Game 1");
    STRenqueue(&Q, "Game 2");
    STRenqueue(&Q, "Game 3");
    STRenqueue(&Q, "Game 4");

    length = lengthQueue(Q);
    printf("Queue Length: %d\n", length);
    int i;
    for(i = lengthQueue(Q); i < CAPACITY; i++){
        STRenqueue(&Q, "Game X");
    }

    //Tes primitif displayQueue dan isFull
    strdisplayQueue(Q);
    if (isQueueFull(Q)){
        printf("Queue Full\n");
    }

    //Tes Dequeue
    while(Q.idxHead != IDX_UNDEF){
        STRdequeue(&Q, temp);
    }
    if (isQueueEmpty(Q)){
        printf("Queue Empty\n");
    }
    return 0;
}