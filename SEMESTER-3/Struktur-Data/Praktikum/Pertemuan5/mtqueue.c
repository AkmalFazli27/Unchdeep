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
    char X, Y, Z;
    
    // Algoritma
    createQueue(&A);

    printf("=== KONDISI AWAL QUEUE A ===\n");
    printQueue(&A);
    printf("Posisi Head: %d", head(A));
    printf("\nPosisi Tail: %d\n", A.tail);
    
    printf("\n=== ENQUEUE A, B, C, D, E ===\n");
    enqueue(&A, 'A');
    enqueue(&A, 'B');
    enqueue(&A, 'C');
    enqueue(&A, 'D');
    enqueue(&A, 'E');
    printQueue(&A);
    printf("Apakah Queue A penuh? %d", isFullQueue(A));
    printf("\nPosisi Head: %d", head(A));
    printf("\nPosisi Tail: %d\n", A.tail);

    printf("\n=== DEQUEUE 3 KALI ===\n");
    dequeue(&A, &X);
    dequeue(&A, &Y);
    dequeue(&A, &Z);
    printQueue(&A);
    printf("Elemen yang didequeue pertama: %c\n", X);
    printf("Elemen yang didequeue kedua: %c\n", Y);
    printf("Elemen yang didequeue ketiga: %c\n", Z);
    printf("Posisi Head = %d\n", head(A));
    printf("Posisi Tail = %d\n", A.tail);
    
    printf("\n=== TEST ENQUEUE2 (MENDISTRIBUSIKAN KE ANTRIAN TERPENDEK) ===\n");
    createQueue(&B);

    enqueue(&B, 'X');
    enqueue(&B, 'Y');
    // enqueue(&B, 'Z');

    printf("Sebelum enqueue2:\nQueue A:\n");
    printQueue(&A);
    printf("Queue B:\n");
    printQueue(&B);

    enqueue2(&A, &B, 'V'); 
    printf("\nSetelah enqueue2('V'):\nQueue A:\n");
    printQueue(&A);
    printf("Queue B:\n");
    printQueue(&B);

    printf("\n=== TEST DEQUEUE2 (MENGAMBIL DARI ANTRIAN TERPANJANG) ===\n");
    printf("Sebelum dequeue2:\nQueue A:\n");
    printQueue(&A);
    printf("Queue B:\n");
    printQueue(&B);
    
    dequeue2(&A, &B, &X);
    printf("\nElemen yang didequeue oleh dequeue2: %c\n", X);
    printf("Queue A:\n");
    printQueue(&A);
    printf("Queue B:\n");
    printQueue(&B);

    return 0;
}