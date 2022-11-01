#include "../DINNERDASHGAME/dinnerdash.h"

void ADD(Queue *q) 
//menambah menu ke queue
{
    ElType val;
    val.makanan = length(*q);
    val.durasimemasak = rand() % 5 + 1;
    val.ketahanan = rand() % 5 + 1;
    val.harga = rand() % 50000 + 10000;
    enqueue(q, val);

}
void COOK(Queue q1, Queue *q, int makanan)
//membuat makanan
{
    printf("%d", q1.buffer[makanan].idmakanan);
    enqueue(q, q1.buffer[makanan]);
}

void SERVE(Queue *q, int makanan)
//menyajikan makanan makanan
{
    if (HEAD(*q) == makanan) {
        if ((*q).buffer[IDX_HEAD(*q)].durasimemasak == 0) {
            dequeue(q);
            printf("Berhasil mengantarkan M%d", makanan);
        } else {
            printf("M%d belum selesai dimasak", makanan);
        }
    } else {
        printf("M%d belum bisa disajikan karena M%d belum selesai", makanan, HEAD(*q));
    }
}

void COOKTIME(Queue *q) 
//mengurangi waktu memasak
{
    for (int i = 0; i < length(*q); i++)
    {
        if ((*q).buffer[i].durasimemasak != 0) {
            (*q).buffer[i].durasimemasak--;
        } else {
            if ((*q).buffer[i].ketahanan > 0) {
                (*q).buffer[i].ketahanan--;
            }
        }
    }
    
}

boolean isEnd(Queue q, int count)
//cek apakah sudah sampai akhir queue
{
    return((length(q) == 7) || (count == 15));
}

void commandCek(char *cc, int *cek, int *makanan) 
//mengubah input menjadi command
{
    char cook[] = "COOK"; //COOK M2
    char serve[] = "SERVE";
    boolean found = false;
    if (cc[0] == 'C') {
        found = true;
        for (int i = 0; i < 4; i++)
        {
            if (cc[i] != makanan[i]) {
                found = false;
            }
        } 
        if (found) {
            (*cek) = 0;
            (*makanan) = cc[6] - '0';
        }
    } else if (cc[0] == 'S') {
        found = true;
        for (int i = 0; i < 5; i++)
        {
            if (cc[i] != serve[i]) {
                found = false;
            }
        }
        if (found) {
            (*cek) = 1;
            (*makanan) = cc[7] - '0';
        }
    }    
}


void runDinnerDash()
{
    Queue qMenu, qMakanan;
    CreateQueue(&qMenu);
    CreateQueue(&qMakanan);
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        ADD(&qMenu);
    }
    int countcust = 0;
    int Com, Makanan;
    char inputCom[5];
    char inputMAKANAN[2];
    char temp;

    while (!isEnd(qMakanan, countcust)) {
        Com = 999;
        Makanan = 999;
        printf("\nDaftar Pesanan\n");
        printf("Makanan\t | Durasi Memasak\t | Ketahanan\t | Harga\n");
        printf("-----------------------------------------------------\n");
        for (int i = 0; i < length(qMenu); i++)
        {
            printf("M%d\t | %d\t\t\t | %d\t\t | %d\n", qMenu.buffer[i].idmakanan, qMenu.buffer[i].durasimemasak, qMenu.buffer[i].ketahanan, qMenu.buffer[i].harga);
        }
        
        printf("\nDaftar Makanan yang sedang dimasak\n");
        printf("Makanan\t | Sisa Durasi Memasak\n");
        printf("--------------------------------\n");
        if (!isEmpty(qMakanan)){
            for (int i = 0; i < length(qMakanan); i++)
            {
                if (q.buffer[i].durasimemasak != 0){
                printf("M%d\t | %d\n", qMakanan.buffer[i].idmakanan, qMakanan.buffer[i].durasimemasak);
                }
            }
        } else {
            printf("\t | \n");
        }
        }

        printf("\nDaftar Makanan yang dapat disajikan\n");
        printf("Makanan\t | Sisa Ketahanan Memasak\n");
        printf("--------------------------------\n");
        if (!isEmpty(qMakanan)){
            for (int i = 0; i < length(qMakanan); i++)
            {
                if (q.buffer[i].durasimemasak == 0){
                printf("M%d\t | %d\n", qMakanan.buffer[i].idmakanan, qMakanan.buffer[i].ketahanan);
                }
            }
        }
        
        COOKTIME(&qMakanan);
        printf("\nMASUKKAN COMMAND: ");
        scanf("%s", inputCom);
        printf("%s", inputCom);
        commandCek(inputCom, &Com, &Makanan);
        printf("%d %d", Com, Makanan);
        if (Com == 0) {
            COOK(qMenu, &qMakanan, Makanan);
        } else if (Com == 1) {
            SERVE(&qMakanan, Makanan);
        } else {
            printf("Command tidak dikenali");
        }
        countcust++;
}