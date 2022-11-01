#include <stdio.h>
#include "time.h"
#include <stdlib.h>

/*
Di setiap giliran, pemain diberi kesempatan menebak angka X. Game akan memberi tahu apakah tebakan pemain dibandingkan terhadap X lebih besar atau lebih kecil.
Permainan selesai jika pemain menebak angka X dengan benar.
Skor untuk game ini tergantung dengan seberapa cepat pemain menebak X. Formula skor dibebaskan.
Batasan X dan maksimal giliran dibebaskan.
*/

int rng()
// I.S. Setiap permainan dimulai dengan program sudah menentukan sebuah angka acak X.
// F.S. Program selesai apabila pemain berhasil menebak angka x dengan benar. Skor bergantung pada jumlah tebakan pemain
// Semakin banyak jumlah tebakan maka skor yang didapat akan semakin kecil
{
    int tebakan, skor; //tebakan adalah angka yang ditebak, skor adalah skor yang didapat
    int max = 100; //maksimal tebakan

    printf("RNG Telah dimulai. Uji kebenaran Anda dengan menebak X.\n");
    printf("Tebakan: ");
    scanf("%d", &tebakan); //memasukkan tebakan
    srand(time(NULL)); //mengacak angka

    int random = rand() % 100 + 1; //membuat angka random di rentanng 1 - 100

    while (tebakan != random && tebakan <= max) //jika tebakan tidak sama dengan random dan tebakan masih dibawah maksimal)
    {
        if (tebakan > random){
            printf("Lebih kecil\n");
            printf("Tebakan: ");
            scanf("%d", &tebakan);
            }
        else if (tebakan < random){
            printf("Lebih besar\n");
            printf("Tebakan: ");
            scanf("%d", &tebakan);
            } 
        }
        if (tebakan == random){
            printf("Ya, X adalah %d\n", random);
        }
    skor = max - tebakan; //menghitung skor
    printf("Skor Anda adalah:  %d\n", skor);
    return skor;
}

int main()
{
	rng();
	return 0;
}
