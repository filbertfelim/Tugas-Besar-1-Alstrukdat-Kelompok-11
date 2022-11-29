#include "hangman.h"

boolean loadfilekata(TabStr *listkata, char *filename)
/* Membaca konfig file.txt yang ada dari listkata.txt*/
{
    boolean ada = STARTLOAD(filename);
    // Membaca DAFTAR KATA
    CopyWord();
    int i = strtoint(currentWord.TabWord); // konversi char ke int
    (*listkata).Neff = i;
    int idx;
    int j;
    for (j = 0; j < (*listkata).Neff; j++)
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
        (*listkata).TI[j] = gamestring;
    }
    return true;
}

void addWord(TabStr listkata, char *filename)
/*Menambahkan kata kedalam file.txt*/
{
    FILE *txt;
    txt = fopen(filename, "w+");
    char *numkata = (char *)malloc(5 * sizeof(char));
    int i;
    // menulis daftar di list kata
    sprintf(numkata, "%d", listkata.Neff);
    fprintf(txt, "%s\n", numkata);
    for (i = 0; i < listkata.Neff - 1; i++)
    {
        fprintf(txt, "%s\n", listkata.TI[i]);
    }
    fprintf(txt, "%s", listkata.TI[i]);
    fclose(txt);
}

int randomidx(TabStr T)
/* mengambil list kata secara random dari file.txt */
{
    srand(time(NULL));
    int random = rand() % T.Neff;
    return random;
}

void MenuStart(TabStr *listkata, char *filename)
/*Mengembalikan 1 untuk menambah list kata pada file.txt, dan mengembalikan 2 untuk memainkan game*/
{
    printf("Silahkan pilih menu dibawah ini:\n");
    printf("1. Menambah kata baru pada kamus\n");
    printf("2. Memainkan game\n");
    printf("\nPilihan: ");
    int input;
    char *pilihan;
    pilihan = STARTINPUT();
    input = strtointinput(pilihan, str_len(pilihan));
    if (input == 1)
    {
        loadfilekata(listkata, filename);
        if ((*listkata).Neff == 100)
        {
            printf("Jumlah kata di kamus sudah penuh!\n\n");
        }
        else
        {
            printf("Masukkan kata yang ingin ditambahkan: ");
            char *newword;
            newword = STARTINPUT();
            (*listkata).TI[(*listkata).Neff] = newword;
            (*listkata).Neff++;
            addWord(*listkata, filename);
            printf("Kata %s berhasil ditambahkan ke dalam kamus.\n\n", newword);
        }
        MenuStart(listkata, filename);
    }
    else if (input == 2)
    {
        loadfilekata(listkata, filename);
        printf("\n");
    }
    else
    {
        printf("Input salah\n\n");
        MenuStart(listkata, filename);
    }
}

void printBody(int chance, char *body)
{
    switch (10 - chance)
    {
    case 9:
        body[9] = '\\';
        break;
    case 8:
        body[8] = '/';
        break;
    case 7:
        body[7] = '|';
        break;
    case 6:
        body[6] = '|';
        break;
    case 5:
        body[5] = '\\';
        break;
    case 4:
        body[4] = '|';
        break;
    case 3:
        body[3] = '/';
        break;
    case 2:
        body[2] = ')';
        break;
    case 1:
        body[1] = '(', body[0] = '|';
        break;
    default:
        break;
    }

    printf(" _________ \n"
           "|         %c\n"
           "|        %c %c\n"
           "|       %c %c %c\n"
           "|         %c\n"
           "|         %c\n"
           "|       %c  %c\n"
           "|             \n",
           body[0], body[1], body[2],
           body[3], body[4], body[5], body[6], body[7], body[8], body[9]);
}

void hangman(char *filename, int *skor)
{
    TabStr listkata;
    MakeEmpty(&listkata);
    printf("=================================WELCOME TO=================================\n");
    printf("'##::::'##::::'###::::'##::: ##::'######:::'##::::'##::::'###::::'##::: ##:\n");
    printf(" ##:::: ##:::'## ##::: ###:: ##:'##... ##:: ###::'###:::'## ##::: ###:: ##:\n");
    printf(" ##:::: ##::'##:. ##:: ####: ##: ##:::..::: ####'####::'##:. ##:: ####: ##:\n");
    printf(" #########:'##:::. ##: ## ## ##: ##::'####: ## ### ##:'##:::. ##: ## ## ##:\n");
    printf(" ##.... ##: #########: ##. ####: ##::: ##:: ##. #: ##: #########: ##. ####:\n");
    printf(" ##:::: ##: ##.... ##: ##:. ###: ##::: ##:: ##:.:: ##: ##.... ##: ##:. ###:\n");
    printf(" ##:::: ##: ##:::: ##: ##::. ##:. ######::: ##:::: ##: ##:::: ##: ##::. ##:\n");
    printf(" ..:::::..::..:::::..::..::::..:::......::::..:::::..::..:::::..::..::::..::\n");

    printf("SELAMAT DATANG DI GAME HANGMAN!\n\n");
    char *fileload = filetodir(filename);
    TabStr guessed_alphabet;
    MakeEmpty(&guessed_alphabet);
    MenuStart(&listkata, fileload);
    int randomwordidx = randomidx(listkata);
    char *word = (listkata).TI[randomwordidx];
    char *guess = (char *)malloc(30 * sizeof(char));
    char *tebakan = (char *)malloc(5 * sizeof(char));
    char *body = (char *)malloc(10 * sizeof(char));
    for (int x = 0; x < 10; x++)
    {
        body[x] = ' ';
    }
    boolean guessed, completed;
    int score = 0;
    int i;
    for (i = 0; i < str_len(word); i++)
    {
        guess[i] = '0';
    }
    guess[i] = '\0';
    int chance = 10;
    while (chance != 0)
    {
        completed = true;
        guessed = false;
        printBody(chance, body);
        printf("Tebakan sebelumnya : ");
        if (guessed_alphabet.Neff == 0)
        {
            printf("-");
        }
        else
        {
            for (i = 0; i < guessed_alphabet.Neff - 1; i++)
            {
                printf("%c, ", guessed_alphabet.TI[i][0]);
            }
            printf("%c", guessed_alphabet.TI[i][0]);
        }
        printf("\nKata: ");
        for (i = 0; i < str_len(word); i++)
        {
            if (guess[i] == '0')
            {
                printf("_ ");
            }
            else
            {
                printf("%c ", word[i]);
            }
        }
        printf("\nKesempatan : %d\n", chance);
        printf("Masukkan tebakan : ");
        tebakan = STARTINPUT();
        if (str_len(tebakan) > 1)
        {
            printf("Input tidak valid");
        }
        else
        {
            boolean in_guessed = false;
            for (i = 0; i < guessed_alphabet.Neff; i++)
            {
                if (guessed_alphabet.TI[i][0] == tebakan[0] || guessed_alphabet.TI[i][0] == tebakan[0] - 32 || guessed_alphabet.TI[i][0] == tebakan[0] + 32)
                {
                    in_guessed = true;
                }
            }
            if (in_guessed)
            {
                printf("Input sudah pernah dipakai sebelumnya, silahkan menebak huruf lain!");
            }
            else
            {
                guessed_alphabet.TI[guessed_alphabet.Neff] = tebakan;
                guessed_alphabet.Neff++;
                for (i = 0; i < str_len(word); i++)
                {
                    if (word[i] == tebakan[0] || word[i] == (tebakan[0] - 32) || word[i] == (tebakan[0] + 32))
                    {
                        guess[i] = '1';
                        guessed = true;
                    }
                }
                if (guessed == false)
                {
                    chance--;
                }
            }
        }
        printf("\n");
        for (i = 0; i < str_len(word); i++)
        {
            if (guess[i] == '0')
            {
                completed = false;
            }
        }
        if (completed == true)
        {
            printf("Anda berhasil menebak kata %s! Kamu mendapatkan %d poin.\n\n", word, str_len(word));
            score += str_len(word);
            MakeEmpty(&guessed_alphabet);
            randomwordidx = randomidx(listkata);
            word = (listkata).TI[randomwordidx];
            for (i = 0; i < str_len(word); i++)
            {
                guess[i] = '0';
            }
            guess[i] = '\0';
        }
    }
    printf("Anda sudah kehabisan kesempatan, poin yang didapatkan : %d\n", score);
    printf("Terima kasih telah bermain HANGMAN!\n");
    *skor = score;
}