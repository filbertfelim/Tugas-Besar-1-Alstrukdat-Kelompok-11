/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../boolean.h"
#include "mesin_kar.h"

#define NMax 100
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int strtoint(char *strg);
/*
   Mengubah string menjadi integer dari TabWord dan mengembalikan nilai integernya
*/
int strtointinput(char *strg, int length);
/*
   Mengubah string menjadi integer dari input dan mengembalikan nilai integernya
*/
int str_len(char *strg);
/*
   mengembalikan panjang string
*/

char *FirstWord(char *strg);
/*
   mengembalikan kata pertama untuk string
*/
char *SecondWord(char *strg);
/*
   mengembalikan kata kedua untuk string
*/

int countblank(char *strg);
/*
   menghitung banyak blank dalam suatu string
*/
char *tolowercase(char *strg);
/*
   mengubah string menjadi huruf kecil
*/
char *touppercase(char *strg);
/*
   mengubah string menjadi huruf besar
*/
#endif