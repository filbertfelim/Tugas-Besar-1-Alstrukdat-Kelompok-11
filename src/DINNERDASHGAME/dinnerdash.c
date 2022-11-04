#include "../DINNERDASHGAME/dinnerdash.h"
#include "../ADT/Mesinkar_kata/mesin_kar.h"

void ADD(Queue *q)                       
  // menambah menu ke queue//
{
  ElType val;
    val.makanan = length(*q);
    val.durasimakanan = rand()%5 + 1;
    val.ketahanan = rand()%5 + 1;
    val.harga = (rand() % 50000 + 10000);
    enqueue(q, val); 
}
void COOK(Queue q1, Queue *q, int makan)    
// membuat makanan//
{
    printf("%d", q1.buffer[makan].makanan);
    enqueue(q, q1.buffer[makan]);
}
void SERVE(Queue *q, int makan)              
// menyajikan makanan makanan//
{
    if (HEAD(*q) == makan) {
        if ((*q).buffer[IDX_HEAD(*q)].durasimakanan == 0) {
            dequeue(q);
            printf("Berhasil mengantarkan M%d", makan);
        } else {
            printf("M%d belum selesai dimasak", makan);
        }
    } else {
        printf("M%d belum bisa disajikan karena M%d belum selesai", makan, HEAD(*q));
    }
}
void COOKTIME(Queue *q)                     
// mengurangi waktu memasak//
{
    int i;
    for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
        if ((*q).buffer[i].durasimakanan > 0) {
            (*q).buffer[i].durasimakanan--;
        }
        else {
            (*q).buffer[i].durasimakanan != 0;
            (*q).buffer[i].ketahanan--; 
        }
    }
}
boolean isEnd(Queue q, int counter)       
// cek apakah sudah sampai akhir queue//
{
  return((length(q) == 7) || (counter == 15));
}

void commandCek(char *cc)
// cek command//
{
  boolean cek1 = false;
  if (compare_strings(cc, "ADD") == 0) {
    cek1 = true;
  } else if (compare_strings(cc, "serve") == 0) {
    cek1 = true;
  } else {
    printf("Command tidak valid\n");
  }
}
void runDinnerDash()                     
// run game//
{
Queue qMenu, qCook;
    CreateQueue(&qMenu);
    CreateQueue(&qCook);
    srand(time(NULL));
    int i = 0;
    for (i; i < 3; i++)
    {
        ADD(&qMenu);
    }
    int count = 0;
    int comm, makan;
    char *inputCom;
    char inputMakan[2];
    char temp;

    while (!isEnd(qCook, count)) {
        comm = 999;
        makan = 999;
        displayQueueMakanan(qMenu);
        displayQueueCook(qCook);
        displayQueueServe(qCook);
        COOKTIME(&qCook);
        
        printf("MASUKKAN COMMAND: ");
        inputCom = STARTINPUT();
        printf("%s ", inputCom);
        
        commandCek(inputCom);
        printf("%d %d", comm, makan);
        if (comm == 0) {
            COOK(qMenu, &qCook, makan);
            count++;
        } else {
            SERVE(&qCook, makan);
        }
        ADD(&qMenu);
    }
}