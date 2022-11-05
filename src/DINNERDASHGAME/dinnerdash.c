#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../DINNERDASHGAME/queuedinner.h"
#include "../STRINGCOMP/stringcomp.h"
#include "../ADT/Mesinkar_kata/mesin_kar.h"

void DESC(int saldo, Queue idmenu, Queue cook, Queue serve)
{
    int i;

    printf("SALDO: %d\n\n", saldo);
    displayQueueMakanan(idmenu);
    displayQueueCook(cook);
    displayQueueServe(serve);
}

void dinnerdash()
{
    /* KAMUS */
    Queue menu, cook, serve;
    int saldo, count, id, i, cust;
    char *command;
    char ck[] = "COOK";
    char sv[] = "SERVE";
    x val;
    boolean found;
    /* ALGORITMA */

    srand(time(NULL));
    CreateQueue(&menu);
    CreateQueue(&cook);
    CreateQueue(&serve);
    cust = 0;
    saldo = 0;
    for (i = 0; i < 3; i++)
    {
        val.makanan = cust;
        val.durasimakanan = (rand() % 5) + 1;
        val.ketahanan = (rand() % 5) + 1;
        val.harga = (rand() % 50000 + 10000);
        enqueue(&menu, val);
        cust++;
    }

    printf("Selamat Datang di Diner Dash!\n\n");
    DESC(saldo, menu, cook, serve);

    while ((length(menu) <= 7) && (length(serve) < 15))
    {
        printf("MASUKKAN COMMAND: ");
        scanf("%s M%d", command, &id);
        /*command = STARTINPUT();*/

        printf("\n\n");
        for (i = 0; i < length(cook); i++)
        {
            if (i < 5)
            {
                ((cook.buffer[i]).durasimakanan)--;
                if ((cook.buffer[i]).durasimakanan == 0)
                {
                    enqueue(&serve, cook.buffer[i]);
                    printf("Makanan M%d telah selesai dimasak\n", (cook.buffer[i]).makanan);
                }
            }
            else
            {
                break;
            }
        }
        for (i = 0; i < length(serve); i++)
        {
            if (i < 5)
            {
                ((serve.buffer[i]).ketahanan)--;
                if ((serve.buffer[i]).ketahanan == 0)
                {
                    dequeue(&serve);
                    printf("Makanan M%d telah hangus, Makanan harus dimasak ulang\n", (serve.buffer[i]).makanan);
                }
            }
            else
            {
                break;
            }
        }
        count = 0;
        for (i = 0; i < length(cook); i++)
        {
            if ((cook.buffer[i]).durasimakanan == 0)
            {
                count++;
            }
            if ((count != 0) && (i != length(cook) - 1))
            {
                cook.buffer[i - count + 1] = cook.buffer[i + 1];
            }
        }
        if (length(cook) == count)
        {
            IDX_HEAD_DINNER(cook) = IDX_UNDEF;
            IDX_TAIL_DINNER(cook) = IDX_UNDEF;
        }
        else
        {
            IDX_TAIL_DINNER(cook) = (IDX_TAIL_DINNER(cook) - count) % CAPACITY_DINNER;
        }

        if (compare_strings(ck, command))
        {
            for (i = 0; i < length(menu); i++)
            {
                if (id == (menu.buffer[i]).makanan)
                {
                    enqueue(&cook, menu.buffer[i]);
                    printf("Berhasil memasak M%d\n", (menu.buffer[i]).makanan);
                    val.makanan = cust;
                    val.durasimakanan = (rand() % 5) + 1;
                    val.ketahanan = (rand() % 5) + 1;
                    val.harga = (rand() % 50000 + 10000);
                    enqueue(&menu, val);
                    cust++;
                }
            }
            printf("==========================================================\n\n");
        }
        else if ((compare_strings(sv, command)))
        {

            if (id == ((menu).buffer[(menu).idxHead].makanan))
            {
                dequeue(&menu);
                enqueue(&serve, val);
                printf("Berhasil mengantar M%d\n", id);
                saldo += val.harga;
                count = 0;
                found = false;

                for (i = 0; i < length(serve); i++)
                {
                    if (i < 5)
                    {
                        ((serve.buffer[i]).ketahanan)--;
                        if ((serve.buffer[i]).ketahanan == 0)
                        {
                            dequeue(&serve);
                            printf("Makanan M%d telah hangus, Makanan harus dimasak ulang\n", (serve.buffer[i]).makanan);
                            found = true;
                        }
                        else
                        {
                            found = false;
                        }
                    }
                    if (id == (serve.buffer[i]).makanan)
                    {
                        found = true;
                        count++;
                    }
                    if (found && (i != length(serve) - 1) && (count != 0))
                    {
                        serve.buffer[i - count + 1] = serve.buffer[i + 1];
                    }
                }
                if (length(serve) == count)
                {
                    IDX_HEAD_DINNER(serve) = IDX_UNDEF;
                    IDX_TAIL_DINNER(serve) = IDX_UNDEF;
                }
                else
                {
                    IDX_TAIL_DINNER(serve) = (IDX_TAIL_DINNER(serve) - count) % CAPACITY_DINNER;
                }

                val.makanan = cust;
                val.durasimakanan = (rand() % 5) + 1;
                val.ketahanan = (rand() % 5) + 1;
                val.harga = (rand() % 50000 + 10000);
                enqueue(&menu, val);
                cust++;
            }
            else
            {
                printf("M%d belum dapat disajikan karena M%d belum selesai\n", id, ((menu).buffer[(menu).idxHead].makanan));
            }
            printf("==========================================================\n\n");
        }
        /*else
        {
            printf("TIDAK VALID\n");
        } */
        DESC(saldo, menu, cook, serve);
    }
    printf("Permainan selesai! Kamu berhasil memperoleh Saldo sebanyak %d\n", saldo);
    printf("==========================================================\n\n");
}