#include <stdio.h>
#include <stdlib.h>
#include "loadfile.h"

static FILE *pita;
static int retval;

boolean loadFile(TabStr *listgame, TabStr *histgame, Map *SB_RNG, Map *SB_DD, Map *SB_HGMN, Map *SB_TOH, Map *SB_SOM, char *filename)
{
  MakeEmpty(listgame);
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

    // Membaca SB_RNG
    ADV();
    CopyWord();
    i = strtoint(currentWord.TabWord); // konversi char ke int
    (*SB_RNG).Count = i;
    for (j = 0; j < (*SB_RNG).Count; j++)
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
      (*SB_RNG).Elements[j].Key = FirstWord(gamestring);
      (*SB_RNG).Elements[j].Value = strtointinput(SecondWord(gamestring), str_len(SecondWord(gamestring)));
    }

    // Membaca SB_DD
    ADV();
    CopyWord();
    i = strtoint(currentWord.TabWord); // konversi char ke int
    (*SB_DD).Count = i;
    for (j = 0; j < (*SB_DD).Count; j++)
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
      (*SB_DD).Elements[j].Key = FirstWord(gamestring);
      (*SB_DD).Elements[j].Value = strtointinput(SecondWord(gamestring), str_len(SecondWord(gamestring)));
    }

    // Membaca SB_HGMN
    ADV();
    CopyWord();
    i = strtoint(currentWord.TabWord); // konversi char ke int
    (*SB_HGMN).Count = i;
    for (j = 0; j < (*SB_HGMN).Count; j++)
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
      (*SB_HGMN).Elements[j].Key = FirstWord(gamestring);
      (*SB_HGMN).Elements[j].Value = strtointinput(SecondWord(gamestring), str_len(SecondWord(gamestring)));
    }

    // Membaca SB_TOH
    ADV();
    CopyWord();
    i = strtoint(currentWord.TabWord); // konversi char ke int
    (*SB_TOH).Count = i;
    for (j = 0; j < (*SB_TOH).Count; j++)
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
      (*SB_TOH).Elements[j].Key = FirstWord(gamestring);
      (*SB_TOH).Elements[j].Value = strtointinput(SecondWord(gamestring), str_len(SecondWord(gamestring)));
    }

    // Membaca SB_SOM
    ADV();
    CopyWord();
    i = strtoint(currentWord.TabWord); // konversi char ke int
    (*SB_SOM).Count = i;
    for (j = 0; j < (*SB_SOM).Count; j++)
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
      (*SB_SOM).Elements[j].Key = FirstWord(gamestring);
      (*SB_SOM).Elements[j].Value = strtointinput(SecondWord(gamestring), str_len(SecondWord(gamestring)));
    }
    SortMapValueDesc(SB_RNG);
    SortMapValueDesc(SB_DD);
    SortMapValueDesc(SB_HGMN);
    SortMapValueDesc(SB_TOH);
    SortMapValueDesc(SB_SOM);
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
