#include "history.h"
#include "resethistory.h"

int main (){
    StackHistory SH;
    CreateEmptyStackHistory(&SH);
    
    stackhistinfotype str = "percobaan 1";
    PushHistory(&SH, str);

    stackhistinfotype str2 = "percobaan 2";
    PushHistory(&SH, str2);

    int n = 3;
    history(&SH, n);
    resethistory(&SH);
    return 0;
}