#include <stdio.h>
#include <stdlib.h>
#include "loadfile.h"

static FILE *pita;
static int retval;

boolean loadFile(TabStr *listgame, TabStr *histgame, TabMap *listsb, char *filename)
{
  boolean ada = STARTLOAD(filename);
  if (ada)
  {
    // Membaca DAFTAR GAME
    CopyWord();
    int i = strtoint(currentWord.TabWord); // konversi char ke int
    (*listgame).Neff = i;
    int idx;
    int j;
    for (j = 0; j < (*listgame).Neff; j++)
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
      (*listgame).TI[j] = gamestring;
    }

    // Membaca HISTORY GAME
    ADV();
    CopyWord();
    i = strtoint(currentWord.TabWord); // konversi char ke int
    (*histgame).Neff = i;
    for (j = 0; j < i; j++)
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
      (*histgame).TI[j] = gamestring;
    }

    // Membaca semua scoreboard dari list game
    Map SB;
    int banyaksb;
    for (banyaksb = 0; banyaksb < (*listgame).Neff; banyaksb++)
    {
      CreateEmptyMap(&SB);
      ADV();
      CopyWord();
      i = strtoint(currentWord.TabWord); // konversi char ke int
      SB.Count = i;
      for (j = 0; j < SB.Count; j++)
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
        SB.Elements[j].Key = FirstWord(gamestring);
        SB.Elements[j].Value = strtointinput(SecondWord(gamestring), str_len(SecondWord(gamestring)));
      }
      SortMapValueDesc(&SB);
      SetElArrayMap(listsb, banyaksb, SB);
    }
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
    return true;
  }
  else
  {
    return false;
  }
}

/*
    membaca file savefile dan memasukkan game ke dalam array game
*/
