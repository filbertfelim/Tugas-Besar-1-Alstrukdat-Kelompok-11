#include "hangman.h"

boolean loadFile(TabStr *listgame, char *filename)
/* Membaca file.txt*/
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
  }
}

int random(TabStr T)
/* mengambil list kata secara random dari file.txt */
{
    srand(time(NULL));
    int random = rand() % T.Neff;
    return random;
}

/*void printBody(int mistakes, char* body)
{
	switch(mistakes) {
        case 9: body[9] = '/'; break;
        case 8: body[8] = '\\'; break;
        case 7: body[7] = '|'; break;
		case 6: body[6] = '|'; break;
		case 5: body[5] = '\\'; break;
		case 4: body[4] = '|'; break;
		case 3: body[3] = '/'; break;
		case 2: body[2] = '('; break;
		case 1: body[1] = ')', body[0] = '|'; break;
		default: break;
	}

	printf(" _________ \n"
	       "|         %c\n"
           "|        %c%c\n"
	       "|      %c %c %c\n"
           "|         %c\n"
	       "|         %c\n"
	       "|       %c  %c\n"
	       "|             \n", body[0], body[1], body[2],
	       body[3], body[4], body[5], body[6], body[7], body[8], body[9]);
} */

void printWord(TabStr *listgame, char *guess) {
	printf("\t");
	for (int i = 0; i < listgame->Neff; ++i)
	{
        if (listgame->TI[i] == &guess[i])
        {
            printf("%c", listgame->TI[i]);
        }
        else
        {
            printf("_");
        }
	}
}

void MenuStart(TabStr *listgame, char *filename, char *file)
/*Mengembalikan 1 untuk menambah list kata pada file.txt, dan mengembalikan 2 untuk memainkan game*/
{
    printf("1. Menambah list kata pada file\n");
    printf("2. Memainkan game\n");
    int input;
    char *pilihan;
    pilihan = STARTINPUT();
    input = strtointinput(pilihan, str_len(pilihan));
    if (input == '1'){
        printf("Masukkan kata yang ingin ditambahkan: ");
        char *kata;
        kata = STARTINPUT();
        FILE *txt;
        char *filename = (char *)malloc(50 * sizeof(char));
        filename = filetodir(file);
        txt = fopen(filename, "w+");
        char *numgame = (char *)malloc(5 * sizeof(char));
        int i;
        // menulis daftar di list kata
        sprintf(numgame, "%d", listgame->Neff);
        fprintf(txt, "%s\n", numgame);
        for (i = 0; i < NbElmt(*listgame); i++)
        {
            fprintf(txt, "%s\n", listgame->TI[i]);
        }
        fprintf(txt, "%s\n", kata);
        fclose(txt);
    }
    else if (input == '2'){
        hangman();
    }
}

/*void isikata(TabStr *listgame, char *filename)
Menuliskan kata ke dalam file.txt
{
    FILE *txt;
    char *filename = (char *)malloc(50 * sizeof(char));
    filename = filetodir(file);
    txt = fopen(filename, "w+");
    char *numgame = (char *)malloc(5 * sizeof(char));
    int i;
    // menulis daftar di list kata
    sprintf(numgame, "%d", listgame->Neff);
    fprintf(txt, "%s\n", numgame);
    for (i = 0; i < NbElmt(*listgame); i++)
    {
        fprintf(txt, "%s\n", listgame->TI[i]);
    }
    fclose(txt);
}*/

void hangman(TabStr *listgame, char *filename, char *file)
{
    printf("SELAMAT DATANG DI GAME HANGMAN!");
    MenuStart(listgame, filename, file);
    int randomgame = random(*listgame);
    char *guess;
    int i, mistakes = 0;
    while (mistakes < 10)
    {
        printWord(listgame, guess);
        printf("\n");
        printf("Masukkan huruf: ");
        char *input;
        input = STARTINPUT();
        int j;
        for (j = 0; j < listgame->Neff; j++)
        {
            if (listgame->TI[randomgame][j] == input[0])
            {
                guess[j] = input[0];
            }
        }
        if (listgame->TI[randomgame] != guess)
        {
            mistakes++;
        }
        //printBody(mistakes, body);
        if (mistakes == 10)
        {
            printf("GAME OVER!");
        }
        else if (listgame->TI[randomgame] == guess)
        {
            printf("SELAMAT ANDA MENANG!");
        }
    }
}

int main()
{
    TabStr listgame; 
    hangman(TabStr *listgame, "listkata.txt", char *file);
    return 0;
}