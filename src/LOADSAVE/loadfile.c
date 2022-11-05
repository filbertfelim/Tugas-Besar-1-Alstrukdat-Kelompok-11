#include <stdio.h>
#include <stdlib.h>
#include "loadfile.h"
#include "../ADT/Array/array.h"
#include "../STRINGCOMP/stringcomp.h"

static FILE *pita;
static int retval;

void loadFile(TabStr *T)
{
  STARTLOAD();
  printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
  CopyWord();
  int i = strtoint(currentWord.TabWord); // konversi char ke int
  (*T).Neff = i;
  int idx;
  int j;
  for (j = 0; j < (*T).Neff; j++)
  {
    ADV();
    CopyWord();
    char *gamestring;
    gamestring = (char *)malloc(currentWord.Length * sizeof(char));
    for (idx = 0; idx < currentWord.Length; idx++)
    {
      *(gamestring + idx) = currentWord.TabWord[idx];
    }
    *(gamestring + currentWord.Length) = '\0';
    (*T).TI[j] = gamestring;
  }
}
