#include <stdio.h>
#include "time.h"
#include <stdlib.h>

/*Setiap permainan dimulai dengan program sudah menentukan sebuah angka acak X.
Di setiap giliran, pemain diberi kesempatan menebak angka X. Game akan memberi tahu apakah tebakan pemain dibandingkan terhadap X lebih besar atau lebih kecil.
Permainan selesai jika pemain menebak angka X dengan benar.
Skor untuk game ini tergantung dengan seberapa cepat pemain menebak X. Formula skor dibebaskan.
Batasan X dan maksimal giliran dibebaskan.
*/

int rng()
{
    int tebakan;

    printf("RNG Telah dimulai. Uji kebenaran Anda dengan menebak X.\n");
    printf("Tebakan: ");
    scanf("%d", &tebakan);
    srand(time(NULL));

    int random = rand() % 100;
    
    while (tebakan != random){
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
            printf("Ya, x adalah %d\n", random);
        }
    return 0;
}

int main()
{
	rng();
	return 0;
}
