#include "mesin_kata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord()
{
    int i = 0;
    while ((currentChar != MARK) && (i < NMax) && !EOP)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int strtoint(char *strg)
{
    int a;
    int res;
    res = 0;
    for (a = 0; a < currentWord.Length; a++)
    {
        res = res * 10 + (strg[a] - '0');
    }
    return res;
}
/*
   Mengubah string menjadi integer dari TabWord dan mengembalikan nilai integernya
*/

int strtointinput(char *strg, int length)
{
    int a;
    int res;
    res = 0;
    for (a = 0; a < length; a++)
    {
        res = res * 10 + (strg[a] - '0');
    }
    return res;
}
/*
   Mengubah string menjadi integer dari input dan mengembalikan nilai integernya
*/

int str_len(char *strg)
{
    int i = 0;
    while (strg[i] != '\0')
    {
        i++;
    }
    return i;
}
/*
   mengembalikan panjang string
*/

char *FirstWord(char *strg)
{
    int i = 0;
    char *firstword = (char *)malloc(50 * sizeof(char));
    while (strg[i] != ' ' && strg[i] != '\0')
    {
        *(firstword + i) = strg[i];
        i++;
    }
    *(firstword + i) = '\0';
    

    return firstword;
}
/*
   mengembalikan kata pertama untuk string
*/

char *SecondWord(char *strg)
{
    int i = 0;
    int idx = 0;
    char *secondword = (char *)malloc(50 * sizeof(char));
    while (strg[i] != ' ' && strg[i] != '\0')
    {
        i++;
    }
    while (strg[i] != '\0')
    {
        *(secondword + idx) = strg[i+1];
        idx++;
        i++;
    }
    *(secondword + idx) = '\0';
    return secondword;
}
/*
   mengembalikan kata kedua untuk string
*/

int countblank(char *strg)
{
    int i, count;
    count = 0;
    for (i = 0; i < str_len(strg); i++)
    {
        if (strg[i] == ' ')
        {
            count++;
        }
    }
    return count;
}
/*
   menghitung banyak blank dalam suatu string
*/
