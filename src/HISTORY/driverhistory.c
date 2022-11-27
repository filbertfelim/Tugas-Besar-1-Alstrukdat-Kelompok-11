#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include "resethistory.h"

int main(){
    StackHistory SH;
    CreateEmptyStackHistory(&SH);

    stackhistinfotype str = "Game 1";
    PushHistory(&SH, str);
    stackhistinfotype str2 = "Game 2";
    PushHistory(&SH, str2);
    stackhistinfotype str3 = "Game 3";
    PushHistory(&SH, str3);
    stackhistinfotype str4 = "Game 4";
    PushHistory(&SH, str4);
    stackhistinfotype str5 = "Game 5";
    PushHistory(&SH, str5);

    int n = 4;
    history(&SH, n);
    resethistory(&SH);
    return 0;

}