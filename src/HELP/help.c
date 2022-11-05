#include "help.h"

void help()
{
    printf("Daftar command:\n");
    printf("\t 1. START      --- Menampilkan tampilan awal game. \n");
    printf("\t 2. LOAD       --- Menampilkan list game, histori, dan scoreboard game. \n");
    printf("\t 3. SAVE       --- Menyimpan state game pemain dalam suatu file. \n");
    printf("\t 4. CREATE GAME --- Menambahkan game baru pada daftar game. \n");
    printf("\t 5. LIST GAME   --- Menampilkan daftar game yang disediakan oleh sistem. \n");
    printf("\t 6. DELETE GAME --- Menghapus sebuah game dari daftar. \n");
    printf("\t 7. QUEUE GAME  --- Mendaftarkan game kedalam list game. \n");
    printf("\t 8. PLAY GAME   --- Memainkan sebuah game. \n");
    printf("\t 9. SKIPGAME   --- Melewatkan permainan sebanyak n. \n");
    printf("\t 10.QUIT       --- Keluar dari program game. \n");
    printf( 
    " ______                          _____           _           _        \n"
    " |   __|___ _____ ___ ___ ___   |     |___ _____| |_ ___ ___| |_ _ _ \n"
    " |__   | -_|     | . | . | .'|  | | | | -_|     | . | .'|   |  _| | |\n"
    " |_____|___|_|_|_|___|_  |__,|  |_|_|_|___|_|_|_|___|__,|_|_|_| |___|\n"
    "                     |___|                                           \n"

    );
}
