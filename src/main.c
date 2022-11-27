// MAIN PROGRAM BNMO

// LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// ADT
#include "./ADT/Array/array.h"
#include "./ADT/Array/arrayMap.h"
#include "./ADT/Map/map.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/Stack/stackhistory.h"
#include "./ADT/Stack/stacktower.h"
#include "./ADT/Queue/strQueue.h"
#include "./ADT/Mesinkar_kata/mesin_kar.h"
#include "./ADT/Mesinkar_kata/mesin_kata.h"
#include "./DINNERDASHGAME/queueDiner.h"
#include "./DINNERDASHGAME/arrayDiner.h"
#include "boolean.h"

// FUNGSI
#include "./STRINGCOMP/stringcomp.h"
#include "./CREATEGAME/creategame.h"
#include "./LISTGAME/listgame.h"
#include "./DELETEGAME/deletegame.h"
#include "./QUEUEGAME/queuegame.h"
#include "./PLAYGAME/playgame.h"
#include "./SKIPGAME/skipgame.h"
#include "./SCOREBOARD/scoreboard.h"
#include "./HISTORY/history.h"
#include "./HISTORY/resethistory.h"
#include "./COMMANDLAIN/commandlain.h"
#include "./START/start.h"
#include "./HELP/help.h"
#include "./QUIT/quit.h"
#include "./LOADSAVE/loadfile.h"
#include "./LOADSAVE/savefile.h"

// FUNGSI GAME
#include "./BONUS/tictactoe.h"
#include "./DINNERDASHGAME/dinerDash.h"
#include "./GAMERNG/rng.h"
#include "./TOWEROFHANOI/towerofhanoi.h"
#include "./HANGMAN/hangman.h"

int main()
{
    printf(" ##::::: ##: ########: ##:::::::: ######::: #######:: ##:::: ##: ########:::: ########:: #######::::: ########:: ##::: ##: ##:::: ##:: #######::\n");
    printf(" ##: ##: ##: ##.....:: ##::::::: ##... ##: ##.... ##: ###:: ###: ##.....:::::... ##..:: ##.... ##:::: ##.... ##: ###:: ##: ###:: ###: ##.... ##: \n");
    printf(" ##: ##: ##: ##::::::: ##::::::: ##:::..:: ##:::: ##: #### ####: ##::::::::::::: ##:::: ##:::: ##:::: ##:::: ##: ####: ##: #### ####: ##:::: ##: \n");
    printf(" ##: ##: ##: ######::: ##::::::: ##::::::: ##:::: ##: ## ### ##: ######::::::::: ##:::: ##:::: ##:::: ########:: ## ## ##: ## ### ##: ##:::: ##: \n");
    printf(" ##: ##: ##: ##...:::: ##::::::: ##::::::: ##:::: ##: ##. #: ##: ##...:::::::::: ##:::: ##:::: ##:::: ##.... ##: ##. ####: ##. #: ##: ##:::: ##: \n");
    printf(" ##: ##: ##: ##::::::: ##::::::: ##::: ##: ##:::: ##: ##:.:: ##: ##::::::::::::: ##:::: ##:::: ##:::: ##:::: ##: ##:. ###: ##:.:: ##: ##:::: ##: \n");
    printf("  ###. ###:: ########: ########:. ######::. #######:: ##:::: ##: ########::::::: ##::::. #######::::: ########:: ##::. ##: ##:::: ##:. #######:: \n");
    printf("ENTER COMMAND: ");
    char *command;
    char *filename;
    filename = (char *)malloc(50 * sizeof(char));
    command = STARTINPUT();
    char *first = FirstWord(command);
    char *scnd = SecondWord(command);
    boolean finish_load = false;

    // Inisialisasi data yang diperlukan
    TabStr game;
    StackHistory historygame;
    strQueue gamequeue;
    TabMap arr_sb;
    MakeEmpty(&game);
    MakeEmptyArrayMap(&arr_sb);
    CreateEmptyStackHistory(&historygame);
    CreateStrQueue(&gamequeue);
    while (!finish_load)
    {

        if (compare_strings(command, "START"))
        {
            STARTGAME(&game);
            finish_load = true;
        }
        else if (compare_strings(first, "LOAD"))
        {
            filename = filetodir(scnd);
            finish_load = loadFile(&game, &arr_sb, &historygame, filename);
            if (!finish_load)
            {
                printf("Load belum berhasil. Silakan input nama file lain.\n\n");
                printf("ENTER COMMAND: ");
                command = STARTINPUT();
                first = FirstWord(command);
                scnd = SecondWord(command);
            }
        }
        else
        {
            printf("Perintah yang bisa digunakan hanya START DAN LOAD\n\n");
            printf("ENTER COMMAND: ");
            command = STARTINPUT();
            first = FirstWord(command);
            scnd = SecondWord(command);
        }
    }
    printf("ENTER COMMAND: ");
    command = STARTINPUT();
    first = FirstWord(command);
    scnd = SecondWord(command);
    while (!compare_strings(command, "QUIT"))
    {
        if (countblank(command) > 1 && !(compare_strings(first, "SKIP")))
        {
            commandlain();
        }
        else
        {
            if (compare_strings(command, "CREATE GAME"))
            {
                CreateGame(&game, &arr_sb);
            }
            else if (compare_strings(first, "SAVE"))
            {
                SAVE(game, historygame, arr_sb, scnd);
            }
            else if (compare_strings(command, "LIST GAME"))
            {
                LISTGAME(&game);
            }
            else if (compare_strings(command, "DELETE GAME"))
            {
                DeleteGame(&game, &gamequeue, &arr_sb);
            }
            else if (compare_strings(command, "QUEUE GAME"))
            {

                QueueGame(&gamequeue, game);
            }
            else if (compare_strings(command, "PLAY GAME"))
            {
                PlayGame(&gamequeue, game, &arr_sb, &historygame);
            }
            else if (compare_strings(first, "SKIP"))
            {
                if (compare_strings(FirstWord(scnd), "GAME"))
                {
                    char *third = SecondWord(scnd);
                    if (third[0] != '\0')
                    {
                        if ((((third[0]) - '0') > 0) && (((third[0]) - '0') < 10))
                        {
                            SkipGame(&gamequeue, game, &arr_sb, strtointinput(third, str_len(third)), &historygame);
                        }
                        else
                        {
                            printf("Jumlah skip tidak valid!\n");
                        }
                    }
                    else
                    {
                        printf("Jumlah skip tidak valid!\n");
                    }
                }
                else
                {
                    commandlain();
                }
            }
            else if (compare_strings(command, "HELP"))
            {
                help();
            }
            else if (compare_strings(command, "SCOREBOARD"))
            {
                scoreboard(arr_sb, game);
            }
            else if (compare_strings(command, "RESET SCOREBOARD"))
            {
                resetscoreboard(game, &arr_sb);
            }
            else if (compare_strings(first, "HISTORY"))
            {
                int idx = 0;
                boolean valid = true;
                if (scnd[0] != '\0')
                {
                    while (valid && idx < str_len(scnd))
                    {
                        if ((((scnd[idx]) - '0') < 0) || (((scnd[idx]) - '0') >= 10))
                        {
                            valid = false;
                        }
                        idx++;
                    }
                    if (!valid)
                    {
                        printf("Jumlah history tidak valid!\n");
                    }
                    else
                    {
                        history(&historygame, strtointinput(scnd, str_len(scnd)));
                    }
                }
                else
                {
                    commandlain();
                }
            }
            else if (compare_strings(command, "RESET HISTORY"))
            {
                resethistory(&historygame);
            }
            else
            {
                commandlain();
            }
        }
        printf("ENTER COMMAND: ");
        command = STARTINPUT();
        first = FirstWord(command);
        scnd = SecondWord(command);
    }
    printf("Apakah anda ingin melakukan save? (Y/N).\n");
    printf("ENTER COMMAND: ");
    command = STARTINPUT();
    while (!compare_strings(command, "Y") && !compare_strings(command, "N"))
    {
        printf("Perintah yang bisa digunakan hanya Y DAN N\n\n");
        printf("ENTER COMMAND: ");
        command = STARTINPUT();
    }
    if (compare_strings(command, "Y"))
    {
        printf("Masukkan nama filename :");
        command = STARTINPUT();
        SAVE(game, historygame, arr_sb, command);
    }
    else
    {
        printf("Save file tidak disimpan.\n\n");
    }
    quit();
    return 0;
}