#include <stdio.h>
#include "boolean.h" // Jika Anda menggunakannya
#include "proses.h"
#include "tqueue.h"

/* procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan Proses kosong, head=tail=0 }*/
void createQueue(tqueue *Q) {
    Proses emptyProses;
    MakeProses(&emptyProses, '#', 0); 
    for (int i = 1; i < 6; i++) {
        Q->wadah[i] = emptyProses;
    }
    Q->head = 0;
    Q->tail = 0;
}

/* function infoHead(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terdepan antrian Q} */
Proses infoHead(tqueue Q) { 
    return Q.wadah[head(Q)];
}

/* function infoTail(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terakhir antrian Q} */
Proses infoTail(tqueue Q) { 
    return Q.wadah[tail(Q)];
}

/* function sizeQueue(Q:tQueue)-> integer */
int sizeQueue(tqueue Q) {
    return tail(Q);
}

/* procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue *Q) {
    if (!isEmptyQueue(*Q)) {
        for (int i = head(*Q); i <= tail(*Q); i++) {
            PrintProses(Q->wadah[i]); 
            if (i < tail(*Q)) {
                printf("\n");
            }
        }
    }
}

/* function isEmptyQueue(Q:tQueue) -> boolean */
boolean isEmptyQueue(tqueue Q) {
    return Q.head == 0 && Q.tail == 0;
}
 
/* function isFullQueue(Q:tQueue) -> boolean */
boolean isFullQueue(tqueue Q) {
    return Q.tail == 5;
}

/* function isOneElement(Q:tQueue) -> boolean */
boolean isOneElement(tqueue Q) {
    return tail(Q) == 1;
}

/* procedure enqueue( input/output Q:tQueue, input P: Proses ) */
void enqueue(tqueue *Q, Proses P) { 
    if (!isFullQueue(*Q)) {
        if (isEmptyQueue(*Q)) {
            Q->head++;
        }
        Q->tail++;
        Q->wadah[tail(*Q)] = P; 
    }
}
 
/* procedure deQueue( input/output Q:tQueue, output P: Proses ) */
void dequeue(tqueue *Q, Proses *P) { 
    Proses emptyProses;
    MakeProses(&emptyProses, '#', 0);  

    if (!isEmptyQueue(*Q)) {
        *P = Q->wadah[head(*Q)];  

        for (int i = 1; i < tail(*Q); i++) {
            Q->wadah[i] = Q->wadah[i + 1];
        }
        Q->wadah[tail(*Q)] = emptyProses;

        if (tail(*Q) == 1) {
            Q->head = 0;
            Q->tail = 0;
        } else {
            Q->tail--;
        }
    } else {
        *P = emptyProses;  
    }
}

/*tambahan, dikerjakan bila cukup waktu */

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input e: character )
{I.S.: e terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, Proses e) {
    if (!isFullQueue(*Q1) && !isFullQueue(*Q2)) {
        if (sizeQueue(*Q1) <= sizeQueue(*Q2)) {
            enqueue(Q1, e);
        }
        else {
            enqueue(Q2, e);
        }
    }
}

/*procedure dequeue2( input/output Q1:tQueue, input/output Q2:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead Q1 atau Q2 atau e='-' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, Proses *e) {
    if (!isFullQueue(*Q1) && !isFullQueue(*Q2)) {
        if (sizeQueue(*Q1) < sizeQueue(*Q2)) {
            dequeue(Q2, e);
        }
        else {
            dequeue(Q1, e);
        }
    }
}
