#include "hangman.h"

boolean loadFile(TabStr *listgame, char *filename)
/* Membaca konfig file.txt yang ada dari listkata.txt*/
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
    return true;
  }
  else
  {
    return false;
  }
}

void addWord(TabStr listgame, char *file)
/*Menambahkan kata kedalam file.txt*/
{
    FILE *txt;
    char *filename = (char *)malloc(50 * sizeof(char));
    filename = filetodir(file);
    txt = fopen(filename, "w+");
    char *numgame = (char *)malloc(5 * sizeof(char));
    int i;

    // menulis daftar di list game
    sprintf(numgame, "%d", listgame.Neff);
    fprintf(txt, "%s\n", numgame);
    for (i = 0; i < NbElmt(listgame); i++)
    {
        fprintf(txt, "%s\n", listgame.TI[i]);
    }
    fclose(txt);
    printf("Save file berhasil disimpan.\n");
    free(filename);
    free(numgame);
}

int random(TabStr T)
/* mengambil list kata secara random dari file.txt */
{
    srand(time(NULL));
    int random = rand() % T.Neff;
    return random;
}

void printWord(TabStr *listkata, char *guess) 
/* Mengambil kata dari listkata secara acak*/
{
	printf("\t");
	for (int i = 0; i < listkata->Neff; ++i)
	{
        if (listkata->TI[i] == &guess[i])
        {
            printf("%c", listkata->TI[i]);
        }
        else
        {
            printf("_");
        }
	}
}

void MenuStart(TabStr *listkata, char *filename)
/*Mengembalikan 1 untuk menambah list kata pada file.txt, dan mengembalikan 2 untuk memainkan game*/
{
    printf("1. Menambah list kata pada file\n");
    printf("2. Memainkan game\n");
    int input;
    char *pilihan;
    pilihan = STARTINPUT();
    input = strtointinput(pilihan, str_len(pilihan));
    if (input == 1)
    {
        loadFile(listkata, "listkata.txt");
        printf("Masukkan kata yang ingin ditambahkan: ");
        char *newword;
        newword = STARTINPUT();
        (*listkata).TI[(*listkata).Neff] = newword;
        (*listkata).Neff++;
        addWord(*listkata, "listkata.txt");
    }
    else if (input == 2)
    {
        loadFile(listkata, "listkata.txt");
        hangman(listkata, "listkata.txt");
    }
    else
    {
        printf("Input salah\n");
        MenuStart(listkata, "listkata.txt");
    }
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

void hangman(TabStr *listkata, char *filename)
{
    printf("SELAMAT DATANG DI GAME HANGMAN!");
    MenuStart(listkata, "listkata.txt");
    int randomgame = random(*listkata);
    char *guess;
    int i, mistakes = 0;
    while (mistakes < 10)
    {
        printWord(listkata, guess);
        printf("\n");
        printf("Masukkan huruf: ");
        char *input;
        input = STARTINPUT();
        int j;
        for (j = 0; j < listkata->Neff; j++)
        {
            if (listkata->TI[randomgame][j] == input[0])
            {
                guess[j] = input[0];
            }
        }
        if (listkata->TI[randomgame] != guess)
        {
            mistakes++;
        }
        //printBody(mistakes, body);
        if (mistakes == 10)
        {
            printf("GAME OVER!");
        }
        else if (listkata->TI[randomgame] == guess)
        {
            printf("SELAMAT ANDA MENANG!");
        }
    }
}

int main()
{
    TabStr *listkata; 
    hangman(listkata, "listkata.txt");
    return 0;
}