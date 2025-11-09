/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : Muhammad Akmal Fazli Riyadi / 24060124130123*/
/* Tanggal : November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

int main() {
    // kamus
    address A, B, C, D, P;
    infotype X;
    List1 Senarai, L1, L2;

    // algoritma
    A = Alokasi('R');
    B = Alokasi('O');
    C = Alokasi('T');
    D = Alokasi('I');

    CreateList(&Senarai);

    printf("=== PENGISIAN ===");

    printf("\nIsi awal Senarai dengan 'O' dan 'R'");
    InsertVFirst(&Senarai, B->info);
    InsertVFirst(&Senarai, A->info);
    printf("\nIsi Senarai: ");
    PrintList(Senarai);
    printf("\nIsi akhir Senarai dengan 'T' dan 'I'");
    InsertVLast(&Senarai, C->info);
    InsertVLast(&Senarai, D->info);
    printf("\nIsi Senarai: ");
    PrintList(Senarai);

    printf("\n\n=== PENGHAPUSAN ===");

    printf("\nHapus elemen pertama Senarai");
    DeleteVFirst(&Senarai, &X);
    printf("\nElemen yang dihapus: %c", X);
    printf("\nIsi Senarai: ");
    PrintList(Senarai);

    printf("\n\nHapus elemen terakhir Senarai");
    DeleteVLast(&Senarai, &X);
    printf("\nElemen yang dihapus: %c", X);
    printf("\nIsi Senarai: ");
    PrintList(Senarai);

    printf("\n\n=== PENCARIAN ===");

    printf("\nCari huruf 'O' dalam Senarai:");
    SearchX(Senarai, 'O', &P);
    if (P != NIL)
        printf("\nDitemukan! info(P) = %c", info(P));
    else
        printf("\nTidak ditemukan!");

    printf("\nCari huruf 'Z' dalam Senarai:");
    SearchX(Senarai, 'Z', &P);
    if (P != NIL)
        printf("\nDitemukan! info(P) = %c", info(P));
    else
        printf("\nTidak ditemukan!");

    printf("\n\n=== MANIPULASI ELEMEN LIST ===");

    printf("\nUpdate huruf 'O' menjadi 'A'");
    UpdateX(&Senarai, 'O', 'A');
    printf("\nIsi Senarai: ");
    PrintList(Senarai);

    printf("\nBalik urutan elemen (Invers)");
    Invers(&Senarai);
    printf("\nIsi Senarai setelah Invers: ");
    PrintList(Senarai);

    printf("\n\n=== SOAL TAMBAHAN ===");

    printf("\nJumlah huruf vokal dalam Senarai: %d", CountVocal(Senarai));
    printf("\nJumlah huruf 'A' dalam Senarai: %d", CountX(Senarai, 'A'));
    printf("\nFrekuensi huruf 'A': %.2f", FrekuensiX(Senarai, 'A'));

    printf("\nPosisi huruf 'A' dalam Senarai: ");
    SearchAllX(Senarai, 'A');

    printf("\nGanti semua huruf 'A' menjadi 'E'");
    UpdateAllX(&Senarai, 'A', 'E');
    printf("\nIsi Senarai: ");
    PrintList(Senarai);

    printf("\nSisipkan huruf 'X' setelah huruf 'E'");
    InsertVAfter(&Senarai, 'E', 'X');
    printf("\nIsi Senarai: ");
    PrintList(Senarai);

    printf("\nHuruf modus (paling sering muncul): %c", Modus(Senarai));
    printf("\nBanyaknya huruf modus: %d", NbModus(Senarai));

    printf("\n\n=== OPERASI BANYAK LIST ===");

    printf("\nSalin Senarai ke L1");
    CopyList(Senarai, &L1);
    printf("\nIsi L1: ");
    PrintList(L1);

    printf("\nPisahkan L1 menjadi dua list (L1 & L2)");
    SplitList(L1, &L1, &L2);
    printf("\nIsi L1: ");
    PrintList(L1);
    printf("\nIsi L2: ");
    PrintList(L2);

    printf("\nGabungkan L1 dan L2 ke dalam list baru L3");
    List1 L3;
    ConcatList(L1, L2, &L3);
    printf("\nIsi L3: ");
    PrintList(L3);

    return 0;
}
