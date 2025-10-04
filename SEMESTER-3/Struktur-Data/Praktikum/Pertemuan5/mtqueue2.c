/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul queue karakter */
/* NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi */
/* Tanggal   : 2 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue2.h"

int main() {
    tqueue2 A;
    char X, Y;

    createQueue2(&A);
    enqueue2(&A, 'F');
    enqueue2(&A, 'A');
    enqueue2(&A, 'B');
    enqueue2(&A, 'C');
    enqueue2(&A, 'D');
    printQueue2(&A);
    dequeue2(&A, &X);
    dequeue2(&A, &Y);
    printQueue2(&A);
    printf("head = %d", head2(A));
    printf("\ntail = %d", tail2(A));
    return 0;
}