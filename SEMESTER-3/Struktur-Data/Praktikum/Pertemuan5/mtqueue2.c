/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul queue 2 karakter */
/* NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi */
/* Tanggal   : 2 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue2.h"

int main() {
    // Kamus
    tqueue2 A, B;
    char X, Y, Z;
    
    // Algoritma
    createQueue2(&A);

    printf("=== KONDISI AWAL QUEUE A ===\n");
    printQueue2(&A);
    printf("Posisi Head: %d", head2(A));
    printf("\nPosisi Tail: %d\n", tail2(A));
    
    printf("\n=== ENQUEUE A, B, C, D ===\n");
    enqueue2(&A, 'A');
    enqueue2(&A, 'B');
    enqueue2(&A, 'C');
    enqueue2(&A, 'D');
    enqueue2(&A, 'E');
    printQueue2(&A);
    printf("Apakah Queue A penuh? %d", isFullQueue2(A));
    printf("\nPosisi Head: %d", head2(A));
    printf("\nPosisi Tail: %d\n", tail2(A));
    
    printf("\n=== DEQUEUE SEKALI ===\n");
    dequeue2(&A, &X);
    printQueue2(&A);
    printf("Elemen yang didequeue: %c\n", X);
    printf("Posisi Head = %d\n", head2(A));
    printf("Posisi Tail = %d\n", tail2(A));
    
    printf("\n=== ENQUEUE F ===\n");
    enqueue2(&A, 'F');
    printQueue2(&A);
    printf("Posisi Head: %d", head2(A));
    printf("\nPosisi Tail: %d\n", tail2(A));

    printf("\n=== DEQUEUE 3 KALI ===\n");
    dequeue2(&A, &X);
    dequeue2(&A, &Y);
    dequeue2(&A, &Z);
    printQueue2(&A);
    printf("Elemen yang didequeue pertama: %c\n", X);
    printf("Elemen yang didequeue kedua: %c\n", Y);
    printf("Elemen yang didequeue ketiga: %c\n", Z);
    printf("Posisi Head = %d\n", head2(A));
    printf("Posisi Tail = %d\n", tail2(A));
    
    printf("\n=== ENQUEUE2N ===\n");
    enqueue2N(&A, 3);
    printQueue2(&A);
    printf("Posisi Head = %d\n", head2(A));
    printf("Posisi Tail = %d\n", tail2(A));

    printf("\n=== ISEQUAL ===\n");
    createQueue2(&B);
    enqueue2(&B, 'A');
    enqueue2(&B, 'B');
    enqueue2(&B, 'C');
    enqueue2(&B, 'D');
    enqueue2(&B, 'E');
    printf("Queue A:\n");
    printQueue2(&A);
    printf("Queue B:\n");
    printQueue2(&B);

    printf("Apakah Queue A dan Queue B sama? %d", isEqualQueue2(A, B));
    return 0;
}