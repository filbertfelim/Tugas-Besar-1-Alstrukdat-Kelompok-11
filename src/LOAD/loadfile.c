#include <stdio.h>
#include <stdlib.h>
#include "loadfile.h"
#include "../ADT/Array/array.h"

static FILE *pitaFile;

void loadFile(TabStr *T, const char *namaFile)
{
  printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
  pitaFile = fopen(namaFile, "r");
  if (pitaFile == NULL)
  {
    printf("Save file kosong.\n");
  }
  else
  {
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
}
