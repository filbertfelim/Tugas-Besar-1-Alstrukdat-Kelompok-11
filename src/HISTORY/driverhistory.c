#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "../ADT/Stack/stackhistory.h"

int main (){
    StackHistory SH;
    CreateEmptyStackHistory(&SH);
    
    stackhistinfotype str = "percobaan 1";
    PushHistory(&SH, str);

    stackhistinfotype str2 = "percobaan 2";
    PushHistory(&SH, str2);

    int n = 3;
    history(&SH, n);
    return 0;
}