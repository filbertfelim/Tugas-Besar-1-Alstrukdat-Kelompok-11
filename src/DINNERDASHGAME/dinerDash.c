#include "dinerDash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintGame(int Saldo, Queue OrderList, arrayDiner Cook, arrayDiner Serve){
    printf("SALDO: %d\n", Saldo);
    //Display Queue Makanan
    printf("\nDaftar Pesanan\n");
    printf("Makanan\t | Durasi Makanan\t | Ketahanan\t | Harga\n");
    printf("----------------------------------------------------\n");
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
        int i;
        for (i = GetFirstDinerIdx(Cook); i < GetLastDinerIdx(Cook); i++)
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
    printf("--------------------------------\n");
    if (!IsArrayEmpty(Cook))
    {
        int i;
        for (i = GetFirstDinerIdx(Cook); i < GetLastDinerIdx(Cook); i++)
        {
            printf("M%d\t | %d\n", Cook.TI[i].makanan, Cook.TI[i].ketahanan);
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
}

void Serve(Queue *OrderList, arrayDiner *Serve, int IDMakanan, int *jumlahTerlayani){
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
    //Dequeue makanan dari antrian & hapus dari Serve;
    dequeue(OrderList);
    (*jumlahTerlayani)++;
    int j;
    for(j = i; j <= NbElmtArray(*Serve); j++){
        (*Serve).TI[j] = (*Serve).TI[j+1];
    }
    ((*Serve).Neff)--;
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

void NextPutaran(Queue *OrderList, arrayDiner *Cook, arrayDiner *Serve){
    int i,j,k,count,idx;
    TambahOrder(OrderList);
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
            for(k = j; k <= NbElmtArray(*Serve); k++){
                (*Serve).TI[k] = (*Serve).TI[k+1];
                (*Serve).Neff -= 1;
            }
            count--;
        }
        j++;
    }
    //Kurangi Durasi Memasak tiap makanan. Masukkan ke Serve jika durasi masak = 0
    arrayDiner tempCook;
    MakeEmptyArray(&tempCook);
    count = 0;
    for(i = GetFirstDinerIdx(*Cook); i <= NbElmtArray(*Cook); i++){
        (Cook->TI[i].durasimasak)--;
        count++;
    }
    j = GetFirstDinerIdx(*Cook);
    while(j <= NbElmtArray(*Cook) && count != 0){
        ElTypeArrayDiner currFood = (*Cook).TI[j];
        k = NbElmtArray(*Serve) + 1;
        if(currFood.durasimasak == 0)
        {
            SetElArray(Serve,k,currFood);
            //Hapus dan Geser Elemen setelahnya
            for(k = j; k <= NbElmtArray(*Cook); k++){
                (*Cook).TI[k] = (*Cook).TI[k+1];
                (*Cook).Neff -= 1;
            }
            count--;
        }
        j++;
    }
}

void Skip(Queue *OrderList, arrayDiner *Cook, arrayDiner *Serve){
    NextPutaran(OrderList, Cook, Serve);
}

void dinerdash(){
    /* KAMUS */
    Queue OrderList;
    arrayDiner CookList, ServeList;
    int customerID, saldo, jumlahTerlayani;
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

    //Proses Pemasukan 3 Pelanggan Pertama
    for(i = 0; i < 3; i++){
        TambahOrder(&OrderList, &customerID);
    }

    //Start
    printf("Selamat Datang di Diner Dash\n\n");
    PrintGame(saldo, OrderList, CookList, ServeList);

    //Game
    while(length(OrderList) <= 7 && jumlahTerlayani < 15){
        printf("MASUKKAN COMMAND: ");
        Command = STARTINPUT();
        First = FirstWord(Command);
        Second = SecondWord(Command);

        if(compare_strings("COOK", First)){
            //Proses Second buat mendapatkan IDMakanan
            int ID;
            // ID = ..........
            
            Cook(OrderList, &CookList, ID);
        }
        else if (compare_strings("SERVE")){

        }
        else if(compare_strings("SKIP", First)){
            Skip(&OrderList, &CookList, &Serve);
        }

    }
}