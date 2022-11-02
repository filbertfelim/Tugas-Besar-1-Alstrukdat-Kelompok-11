#include "mesin_kar.h"
#include <stdio.h>
#include <stdlib.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;
void START()
{
    pita = fopen("../data/config.txt", "r");
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

char *STARTINPUT()
{
    char *stringinput;
    fscanf(stdin, "%s", stringinput);
    return stringinput;
}

void ADV()
{
    retval = fscanf(pita, "%c", &currentChar);
    if (retval < 0)
    {
        fclose(pita);
        EOP = true;
    }
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC()
{
    return currentChar;
}
/* Mengirimkan currentChar */

boolean IsEOP()
{
    return (currentChar == MARK);
}
/* Mengirimkan true jika currentChar = MARK */