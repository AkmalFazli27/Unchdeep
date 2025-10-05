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

/*PROCEDURE*/
/*procedure createQueue ( output Q:tQueue)*/
void createQueue(tqueue *Q);

/*SELEKTOR*/
#define head(Q) (Q).head
#define tail(Q) (Q).tail

/*function infoHead(Q:tQueue)-> Proses */
Proses infoHead(tqueue Q); // 

/*function infoTail(Q:tQueue)-> Proses */
Proses infoTail(tqueue Q); // 

/*function sizeQueue(Q:tQueue)-> integer */
int sizeQueue(tqueue Q);

/*procedure printQueue(input Q:tQueue)*/
void printQueue(tqueue *Q);

/*procedure viewQueue(input Q:tQueue)*/
void viewQueue(tqueue *Q);

/*PREDIKAT*/
/*function isEmptyQueue(Q:tQueue) -> boolean*/
boolean isEmptyQueue(tqueue Q);

/*function isFullQueue(Q:tQueue) -> boolean*/
boolean isFullQueue(tqueue Q);

/*function isOneElement(Q:tQueue) -> boolean*/
boolean isOneElement(tqueue Q);

/*MUTATOR*/
/*procedure enqueue( input/output Q:tQueue, input P: Proses )*/
void enqueue(tqueue *Q, Proses P); 

/*procedure deQueue( input/output Q:tQueue, output P: Proses )*/
void dequeue(tqueue *Q, Proses *P); 

/*tambahan, dikerjakan bila cukup waktu */
void enqueue2(tqueue *Q1, tqueue *Q2, Proses P); 
void dequeue2(tqueue *Q1, tqueue *Q2, Proses *P); 

#endif