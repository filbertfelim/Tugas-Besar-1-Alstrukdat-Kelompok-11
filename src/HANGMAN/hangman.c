#include "hangman.h"

void printBody(int mistakes, char* body)
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
}

void printWord(char* guess, int len) {
	printf("\t");
	for (int i = 0; i < len; ++i)
	{
		printf("%c ", guess[i]);
		printf("_");
	}
}

void hangman()
{
    srand(time(NULL));
    int randomword = rand() % 6;
    char guessword[][16] = 
    {
        "ALSTRUKDAT", "KAMUNANYA", "KUCING", "WINDOWS", "AQUA", "TUBESASIK"
    };

    int chances = 10, mistakes = 0;
    int len = strlen(guessword[randomword]);
    char *guess = malloc(len * sizeof(char));
    boolean found;
    char *body = malloc(10 * sizeof(char));
    do {
        found = false;
        printf("SELAMAT DATANG DI GAME HANGMAN!");
        printf("\n");
        printBody(mistakes, body);
        printf("\n");
        printf("Tebakan sebelumnya: ");
        if (mistakes == 0) printf("-\n");
        for (int i = 0; i < mistakes; ++i)
        {
            printf("%c ", body[i]);
        }
        printf("Kesempatan : %d\n", chances);
        printf("Kata: ");
        printWord(guess, len);
        printf("\nMasukkan tebakan: ");
        char *input;
        input = STARTINPUT();
        if (strlen(input) > 1) {
            printf("Tebakan salah!\n");
            continue;
        }
        for (int i = 0; i < len; ++i)
        {
            if (guessword[randomword][i] == input[0]) {
                guess[i] = input[0];
                found = true;
            }
        }
        if (!found) {
            body[mistakes] = input[0];
            mistakes++;
            chances--;
        }
    } while (chances > 0 && mistakes < 10 && !compare_strings(guess, guessword[randomword]));

    if (compare_strings(guess, guessword[randomword])) {
        printf("Selamat, tebakan anda benar!\n", guessword[randomword]);
    } else {
        printf("Anda kalah!\n");
        printf("Kata yang benar adalah %s\n", guessword[randomword]);
    }
}
