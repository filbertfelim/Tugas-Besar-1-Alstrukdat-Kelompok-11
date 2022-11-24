#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "../ADT/Stack/stack.h"

int main (){
    Stack S;
    CreateEmptyStack(&S);
    
    stackinfotype str = "percobaan 1";
    Push(&S, str);

    stackinfotype str2 = "percobaan 2";
    Push(&S, str2);

    int n = 3;
    history(&S, n);
    return 0;
}