#include "history.h"
#include "resethistory.h"

int main (){
    Stack S;
    CreateEmptyStack(&S);
    
    stackinfotype str = "percobaan 1";
    Push(&S, str);

    stackinfotype str2 = "percobaan 2";
    Push(&S, str2);

    int n = 3;
    history(&S, n);
    resethistory(&S);
    return 0;
}