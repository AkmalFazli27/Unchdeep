/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Muhammad Akmal Fazli Riyadi / 24060124130123*/
/* Tanggal : 20/11/2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

int main() {
    // kamus lokal
    address A, B, C, D;
    List3 L;
    infotype X, Y;

    // algoritma
    A = Alokasi('A');
    B = Alokasi('B');
    C = Alokasi('C');
    D = Alokasi('D');

    CreateList(&L);
    InsertVFirst(&L, A->info);
    InsertVFirst(&L, B->info);
    PrintList(L);
    printf("\n");
    InsertVLast(&L, C->info);
    InsertVLast(&L, D->info);
    PrintList(L);
    printf("\nBanyak elemen: %d", NbElm(L));
    DeleteVFirst(&L, &X);
    printf("\nElement yang dihapus: %c\n", X);
    PrintList(L);
    DeleteVLast(&L, &Y);
    printf("\nElement yang dihapus: %c\n", Y);
    PrintList(L);
}