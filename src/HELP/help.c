#include "help.h"

void help()
{
    printf("Daftar command:\n");
    printf("\t 1. SAVE FILE          --- Menyimpan state daftar game pemain di dalam file. \n");
    printf("\t 2. CREATE GAME        --- Menambahkan game baru pada daftar game. \n");
    printf("\t 3. LIST GAME          --- Menampilkan daftar game yang disediakan oleh sistem. \n");
    printf("\t 4. DELETE GAME        --- Menghapus sebuah game dari daftar. \n");
    printf("\t 5. QUEUE GAME         --- Mendaftarkan game kedalam list antrian game. \n");
    printf("\t 6. PLAY GAME          --- Memainkan sebuah game di antrian pertama. \n");
    printf("\t 7. SKIP GAME n        --- Melewatkan antrian game sebanyak n. \n");
    printf("\t 8. QUIT               --- Keluar dari program game. \n");
    printf("\t 9. SCOREBOARD         --- Menampilkan daftar scoreboard semua game. \n");
    printf("\t 10. RESET SCOREBOARD  --- Menghapus semua isi scoreboard dari game tertentu / semua game. \n");
    printf("\t 11. HISTORY           --- Menampilkan daftar game yang telah dimainkan. \n");
    printf("\t 12. RESET HISTORY     --- Menghapus daftar game yang telah dimainkan. \n");
    printf(
        " ______                          _____           _           _       \n"
        " |   __|___ _____ ___ ___ ___   |     |___ _____| |_ ___ ___| |_ _ _ \n"
        " |__   | -_|     | . | . | .'|  | | | | -_|     | . | .'|   |  _| | |\n"
        " |_____|___|_|_|_|___|_  |__,|  |_|_|_|___|_|_|_|___|__,|_|_|_| |___|\n"
        "                     |___|                                           \n"

    );
}
/*
 * Menampilkan bantuan command - command untuk user yang membutuhkan bantuan saat akan menjalankan program
 */
