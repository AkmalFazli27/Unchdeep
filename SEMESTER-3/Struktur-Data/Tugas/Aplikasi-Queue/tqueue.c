#include <stdio.h>
#include "boolean.h" 
#include "proses.h"
#include "tqueue.h"


/* ----- KONSTRUKTOR ----- */

/* procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan Proses kosong, head=tail=0 }*/
void createQueue(tqueue *Q) {
    Proses emptyProses;
    makeProses(&emptyProses, '#', 0); 
    for (int i = 1; i < 6; i++) {
        Q->wadah[i] = emptyProses;
    }
    Q->head = 0;
    Q->tail = 0;
}


/* ----- SELEKTOR ----- */

/*function head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} 
*/
#define head(Q) (Q).head

/*function tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} 
*/
#define tail(Q) (Q).tail

/*function infoHead(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terdepan antrian Q} 
*/
Proses infoHead(tqueue Q) { 
    return Q.wadah[head(Q)];
}

/*function infoTail(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terakhir antrian Q} 
*/
Proses infoTail(tqueue Q) { 
    return Q.wadah[tail(Q)];
}

/*function sizeQueue(Q:tQueue) -> integer 
{Mengembalikkan banyak elemen yang terisi di queue}
*/
int sizeQueue(tqueue Q) {
    return tail(Q);
}


/* ----- MUTATOR ----- */

/*procedure enqueue( input/output Q:tQueue, input P: Proses )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } 
*/
void enqueue(tqueue *Q, Proses P) { 
    if (!isFullQueue(*Q)) {
        if (isEmptyQueue(*Q)) {
            Q->head++;
        }
        Q->tail++;
        Q->wadah[tail(*Q)] = P; 
    }
}
 
/*procedure dequeue( input/output Q:tQueue, output P: Proses )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju}
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0} 
*/
void dequeue(tqueue *Q, Proses *P) { 
    Proses emptyProses;
    makeProses(&emptyProses, '#', 0);  

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


/* ----- OPERATOR ----- */

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: Mencetak elemen yang ada di queue ke layar}
*/
void printQueue(tqueue *Q) {
    if (!isEmptyQueue(*Q)) {
        for (int i = 1; i <= 5; i++) {
            printf("ID: %c | BT: %d", getIDProses(Q->wadah[i]), getBurstTime(Q->wadah[i]));
            if (i < 5) {
                printf("\n");
            }
        }
    }
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: Mencetak elemen tak kosong ke layar}
*/
void viewQueue(tqueue *Q) {
    if (!isEmptyQueue(*Q)) {
        for (int i = head(*Q); i <= tail(*Q); i++) {
            printf("ID: %c | BT: %d", getIDProses(Q->wadah[i]), getBurstTime(Q->wadah[i]));
            if (i < tail(*Q)) {
                printf("\n");
            }
        }
    }
}


/* ----- PREDIKAT ----- */

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}
*/
boolean isEmptyQueue(tqueue Q) {
    return Q.head == 0 && Q.tail == 0;
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}
*/
boolean isFullQueue(tqueue Q) {
    return Q.tail == 5;
}

