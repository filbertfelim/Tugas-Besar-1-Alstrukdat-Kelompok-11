#include "mesin_kar.h"
#include "../../STRINGCOMP/stringcomp.h"
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

boolean STARTLOAD(char *filename)
{
    pita = fopen(filename, "r");
    if (pita != NULL)
    {
        ADV();
        return true;
    }
    else
    {
        return false;
    }
}

char *STARTINPUT()
{
    pita = stdin;
    char *stringinput;
    int c;
    int i = 0;
    stringinput = (char *)malloc(101 * sizeof(char));
    while (c = fgetc(pita))
    {
        if (c == EOF || c == '\n' || c == '\r')
        {
            break;
        }
        *(stringinput + i) = (char)c;
        i++;
    }
    *(stringinput + i) = '\0';
    return stringinput;
}

void ADV()
{
    if (pita != NULL){
    	retval = fscanf(pita, "%c", &currentChar);
    	EOP = retval < 0;
    	if (EOP && pita != NULL)
    	{
        	fclose(pita);
        	pita = NULL;
    	}
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

char *filetodir(char *file)
{
    char dir[8] = "../data/";
    char *filedir = (char *)malloc(100 * sizeof(char));
    int i = 0;
    while (i < 8)
    {
        filedir[i] = dir[i];
        i++;
    }
    int idx = 0;
    while (file[idx] != '\0')
    {
        filedir[i] = file[idx];
        i++;
        idx++;
    }
    filedir[i] = '\0';
    return filedir;
}
/*
   mengubah filename menjadi directory yang tepat untuk load dan save
*/
