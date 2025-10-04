/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul queue karakter */
/* NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi */
/* Tanggal   : 2 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue.h"

int main() {
    // Kamus
    tqueue A, B;
    char X;

    // Algoritma
    printf("=============== QUEUE A ===============\n");
    createQueue(&A);
    createQueue(&B);
    enqueue(&A,'A');
    enqueue(&A,'B');
    enqueue(&A,'C');
    enqueue(&B,'A');
    enqueue(&B,'B');
    printQueue(&A);
    printQueue(&B);
    // printf("Size dari Queue A: %d", sizeQueue(A));
    // dequeue(&A, &X);
    dequeue2(&A, &B, &X);
    printQueue(&A);
    printQueue(&B);
    // printf("%c", X);

    return 0;
}