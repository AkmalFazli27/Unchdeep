#ifndef TQUEUE_H
#define TQUEUE_H

#include "boolean.h"
#include "proses.h" 

/* type tQueue = <  wadah: array [1..5] of Proses,
                     head: integer,
                     tail: integer > */
typedef struct {
    Proses wadah[6]; 
    int head;
    int tail;
} tqueue;

/* ----- KONSTRUKTOR ----- */

/*procedure createQueue(output Q:tQueue)*/
/*{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan Proses kosong, head=tail=0 }
*/ 
void createQueue(tqueue *Q);


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
Proses infoHead(tqueue Q); 

/*function infoTail(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terakhir antrian Q} 
*/
Proses infoTail(tqueue Q); 

/*function sizeQueue(Q:tQueue) -> integer 
{Mengembalikkan banyak elemen yang terisi di queue}
*/
int sizeQueue(tqueue Q);


/* ----- MUTATOR ----- */

/*procedure enqueue( input/output Q:tQueue, input P: Proses )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } 
*/
void enqueue(tqueue *Q, Proses P); 

/*procedure dequeue( input/output Q:tQueue, output P: Proses )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju}
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0} 
*/
void dequeue(tqueue *Q, Proses *P); 


/* ----- OPERATOR ----- */

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: Mencetak elemen yang ada di queue ke layar}
*/
void printQueue(tqueue *Q);

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: Mencetak elemen tak kosong ke layar}
*/
void viewQueue(tqueue *Q);


/* ----- PREDIKAT ----- */

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}
*/
boolean isEmptyQueue(tqueue Q);

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}
*/
boolean isFullQueue(tqueue Q);


#endif