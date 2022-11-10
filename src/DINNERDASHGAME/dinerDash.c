#include "dinerDash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintGame(int Saldo, Queue OrderList, arrayDiner Cook, arrayDiner Serve){
    printf("\n====================================================\n");
    printf("SALDO: %d\n", Saldo);
    //Display Queue Makanan
    printf("\nDaftar Pesanan\n");
    printf("Makanan\t | Durasi Memasak\t | Ketahanan\t | Harga\n");
    printf("--------------------------------------------------------\n");
    int i, idx;
    for(i = 0; i < length(OrderList); i++)
    {
        idx = (IDX_HEAD_DINNER(OrderList) + i) % CAPACITY_DINNER;
        printf("M%d\t | %d\t\t\t | %d\t\t | %d\n", OrderList.buffer[idx].makanan, OrderList.buffer[idx].durasimakanan, OrderList.buffer[idx].ketahanan, OrderList.buffer[idx].harga);
    }
    //Display Array Memasak
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan\t | Sisa Durasi Memasak\n");
    printf("--------------------------------\n");
    if (!IsArrayEmpty(Cook))
    {
        for (i = GetFirstDinerIdx(Cook); i < GetLastDinerIdx(Cook) + 1; i++)
        {
            printf("M%d\t | %d\n", Cook.TI[i].makanan, Cook.TI[i].durasimasak);
        }
    }
    else
    {
        printf("\t|\n");
    }
    //Display Array Serve
    printf("\nDaftar Makanan yang siap disajikan\n");
    printf("Makanan\t | Sisa Ketahanan Makanan\n");
    printf("-----------------------------------\n");
    if (!IsArrayEmpty(Serve))
    {
        for (i = GetFirstDinerIdx(Serve); i < GetLastDinerIdx(Serve) + 1; i++)
        {
            printf("M%d\t | %d\n", Serve.TI[i].makanan, Serve.TI[i].ketahanan);
        }
    }
    else
    {
        printf("\t|\n");
    }
}

void Cook(Queue OrderList, arrayDiner *Cook, int IDMakanan){
    // IDMakanan harus ada di OrderList
    int i = 0;
    boolean found = false;
    while (!found){
        if (OrderList.buffer[i].makanan == IDMakanan){
            found = true;
        }
        else{
            i++;
        }
    }
    ElTypeArrayDiner temp;
    temp.makanan = OrderList.buffer[i].makanan;
    temp.durasimasak = OrderList.buffer[i].durasimakanan;
    temp.ketahanan = OrderList.buffer[i].ketahanan;
    temp.harga = OrderList.buffer[i].harga;
    int j = NbElmtArray(*Cook);
    SetElArray(Cook, j + 1, temp);
    printf("Makanan M%d berhasil dimasak!\n", IDMakanan);
}

void Serve(Queue *OrderList, arrayDiner *Serve, int IDMakanan, int *jumlahTerlayani, int *Saldo){
    //ID Makanan harus ada di Serve
    int i = GetFirstDinerIdx(*Serve);
    boolean found = false;
    while (!found){
        if ((*Serve).TI[i].makanan == IDMakanan){
            found = true;
        }
        else{
            i++;
        }
    }
    //Tambah Saldo Pemain, Dequeue makanan dari antrian & hapus dari Serve;
    (*Saldo) += (((*OrderList).buffer[(*OrderList).idxHead])).harga;
    dequeue(OrderList);
    (*jumlahTerlayani)++;
    DeleteEl(Serve, i);
    printf("Makanan M%d berhasil diantar!\n", IDMakanan);
}

void TambahOrder(Queue *OrderList, int *customerID){
    ElTypeQueueDiner newVal;
    newVal.makanan = *customerID;
    newVal.durasimakanan = (rand() % 5) + 1;
    newVal.ketahanan = (rand() % 5) + 1;
    newVal.harga = (rand() % 50000);
    enqueue(OrderList, newVal);
    (*customerID) += 1;
}

void NextPutaran(Queue *OrderList, arrayDiner *Cook, arrayDiner *Serve, int *IDCustomer){
    int i,j,k,count,idx;
    TambahOrder(OrderList, IDCustomer);
    //Kurangi Ketahanan makanan yang ada di Serve, hangus jika ketahanan = 0
    count = 0;
    for(i = GetFirstDinerIdx(*Serve); i <= NbElmtArray(*Serve); i++){
        (((*Serve).TI[i]).ketahanan)--;
        if (((*Serve).TI[i]).ketahanan == 0){
            count++;
        }
    }
    j = GetFirstDinerIdx(*Serve);
    while(j <= NbElmtArray(*Serve) && count != 0){
        ElTypeArrayDiner currServeFood = (*Serve).TI[j];
        if(currServeFood.ketahanan == 0)
        {
            DeleteEl(Serve, j);
            count--;
            printf("Makanan M%d hangus dan harus dimasak kembali!\n", currServeFood.makanan);
        }
        j++;
    }
    //Kurangi Durasi Memasak tiap makanan. Masukkan ke Serve jika durasi masak = 0
    arrayDiner tempCook;
    MakeEmptyArray(&tempCook);
    count = 0;
    for(i = GetFirstDinerIdx(*Cook); i <= NbElmtArray(*Cook); i++){
        (Cook->TI[i].durasimasak)--;
        if ((Cook->TI[i].durasimasak) == 0){
            count++;
        }
    }
    j = GetFirstDinerIdx(*Cook);
    while(j <= NbElmtArray(*Cook) && count != 0){
        ElTypeArrayDiner currFood = (*Cook).TI[j];
        k = NbElmtArray(*Serve) + 1;
        if(currFood.durasimasak == 0)
        {
            if (IsQueueMember(*OrderList, currFood.makanan))
            {
                SetElArray(Serve,k,currFood);
                printf("Makanan M%d berhasil dimasak!\n", currFood.makanan);
            }
            else{
                printf("Makanan M%d selesai dimasak, tetapi hangus karena sudah tidak ada di antrian!\n", currFood.makanan);
            }
            DeleteEl(Cook, j);
            count--;
        }
        else{
            j++;
        }
    }
    for(i = GetFirstDinerIdx(*Serve); i <= GetLastDinerIdx(*Serve); i++){
        if (!(IsQueueMember(*OrderList, (*Serve).TI[i].makanan))){
            printf("Makanan M%d hangus karena sudah tidak ada di antrian!\n", (*Serve).TI[i].makanan);
            DeleteEl(Serve, i);
        }
    }
}

void Skip(Queue *OrderList, arrayDiner *Cook, arrayDiner *Serve, int *IDCustomer){
    NextPutaran(OrderList, Cook, Serve, IDCustomer);
}

int FoodID(char *Second){
    int ID = 0;
    int i = 0;
        if (str_len(Second) == 0 || str_len(Second) == 1){
            ID = -999;
        }
        while (i < str_len(Second) && ID != -999){
            char tempChar = Second[i];
            if (i == 0){
                if (tempChar != 'M'){
                     ID = -999;
                }
            }
            else{
                if ((tempChar - '0') < 0 || (tempChar - '0') > 9)
                {
                    ID = -999;
                }
                else{
                    ID = ID * 10 + (tempChar - '0');
                }
            }
            i++;
        }
    return ID;
}

void dinerdash(){
    /* KAMUS */
    Queue OrderList;
    arrayDiner CookList, ServeList;
    int customerID, saldo, jumlahTerlayani, nextToServe;
    int i; // Variabel Looping
    char *Command, *First, *Second;

    /* ALGORITMA */

    //Inisialisasi
    srand(time(NULL));
    CreateQueue(&OrderList);
    MakeEmptyArray(&CookList);
    MakeEmptyArray(&ServeList);
    customerID = 0;
    saldo = 0;
    jumlahTerlayani = 0;
    nextToServe = 0;

    //Proses Pemasukan 3 Pelanggan Pertama
    for(i = 0; i < 3; i++){
        TambahOrder(&OrderList, &customerID);
    }

    //Start
    printf("============================\n");
    printf("Selamat Datang di Diner Dash\n");
    printf("============================\n\n");

    //Game
    while(length(OrderList) <= 7 && jumlahTerlayani < 15){
        PrintGame(saldo, OrderList, CookList, ServeList);
        printf("\nMASUKKAN COMMAND: ");
        Command = STARTINPUT();
        First = FirstWord(Command);
        Second = SecondWord(Command);
        if(compare_strings("COOK", First)){
            //Proses Second buat mendapatkan IDMakanan
            int ID = FoodID(Second);
            if (ID != -999){
                boolean found = IsQueueMember(OrderList, ID);
                if (found){
                    NextPutaran(&OrderList, &CookList, &ServeList, &customerID);
                    Cook(OrderList, &CookList, ID);
                }
                else{
                    printf("Makanan M%d tidak ada dalam antrian.\n\n", ID);
                }
            }
            else{
                printf("Command cook tidak valid.\n\n");
            }
        }
        else if (compare_strings("SERVE", First)){
            //Proses Second buat mendapatkan IDMakanan
            int ID = FoodID(Second);
            if (ID != -999){
                boolean found = IsQueueMember(OrderList, ID);
                if (found){
                    if (IsInArray(ServeList, ID)){
                        if (ID == nextToServe){
                            Serve(&OrderList, &ServeList, ID, &jumlahTerlayani, &saldo);
                            nextToServe++;
                            NextPutaran(&OrderList, &CookList, &ServeList, &customerID);
                        }
                        else{
                            printf("Makanan M%d belum bisa disajikan karena M%d belum disajikan.\n", ID, jumlahTerlayani);
                        }
                    }
                    else{
                        printf("Makanan M%d belum siap disajikan.\n\n", ID);
                    }
                }
                else{
                    printf("Makanan M%d tidak ada dalam antrian.\n\n", ID);
                }
            }
            else{
                printf("Command serve tidak valid.\n\n");
            }
        }
        else if(compare_strings("SKIP", First)){
            Skip(&OrderList, &CookList, &ServeList, &customerID);
        }
        else{
            printf("Command tidak Valid.\n\n");
        }

    }

    // Game Over
    printf("Permainan selesai! Kamu berhasil memperoleh Saldo sebanyak %d!\n", saldo);
    printf("===================================================================\n\n");
}