/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Muhammad Akmal Fazli Riyadi / 24060124130123*/
/* Tanggal : 20/11/2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

int main() {
    List3 L, L1, L2, L3;
    address A;
    infotype X;

    CreateList(&L);

    /* Insert */
    InsertVFirst(&L, 'C');
    InsertVFirst(&L, 'B');
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'A');  

    printf("List awal: ");
    PrintList(L); printf("\n");

    /* NbElm */
    printf("Jumlah elemen: %d\n", NbElm(L));

    /* SearchX */
    SearchX(L, 'B', &A);
    if (A != NIL) printf("Ketemu B\n");

    /* UpdateX */
    UpdateX(&L, 'D', 'Z');
    printf("Update D->Z: ");
    PrintList(L); printf("\n");

    /* Insert After & Before */
    InsertVAfterX(&L, 'B', 'X');
    InsertVBeforeX(&L, 'C', 'Y');
    printf("Setelah Insert After & Before: ");
    PrintList(L); printf("\n");

    /* Delete First & Last */
    DeleteVFirst(&L, &X);
    printf("Delete First (%c): ", X);
    PrintList(L); printf("\n");

    DeleteVLast(&L, &X);
    printf("Delete Last (%c): ", X);
    PrintList(L); printf("\n");

    /* DeleteX */
    DeleteX(&L, 'X');
    printf("Delete X: ");
    PrintList(L); printf("\n");

    /* DeleteVAfterX & DeleteVBeforeX */
    DeleteVAfterX(&L, 'B', &X);
    printf("Delete After B (%c): ", X);
    PrintList(L); printf("\n");

    DeleteVBeforeX(&L, 'C', &X);
    printf("Delete Before C (%c): ", X);
    PrintList(L); printf("\n");

    /* Insert lagi untuk test lain */
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'N');
    InsertVLast(&L, 'G');
    InsertVLast(&L, 'U');

    /* CountX */
    printf("Count A: %d\n", CountX(L, 'A'));

    /* FrekuensiX */
    printf("Frekuensi A: %.2f\n", FrekuensiX(L, 'A'));

    /* CountVocal */
    printf("Jumlah vokal: %d\n", CountVocal(L));

    /* CountNG */
    printf("Jumlah pasangan NG: %d\n", CountNG(L));

    /* SearchAllX */
    printf("Posisi huruf A: ");
    SearchAllX(L, 'A');
    printf("\n");

    /* MaxMember & Modus */
    printf("MaxMember: %d\n", MaxMember(L));
    printf("Modus: %c\n", Modus(L));

    /* DeleteAllX */
    DeleteAllX(&L, 'A');
    printf("Setelah DeleteAllX A: ");
    PrintList(L); printf("\n");

    /* Invers */
    Invers(&L);
    printf("Invers L: ");
    PrintList(L); printf("\n");

    /* OPERASI LIST BANYAK */
    CreateList(&L1);
    InsertVLast(&L1, 'K');
    InsertVLast(&L1, 'L');

    ConcatList(L, L1, &L2);
    printf("Concat L + L1: ");
    PrintList(L2); printf("\n");

    SplitList(L2, &L1, &L3);
    printf("Split L2 -> L1: "); PrintList(L1); printf("\n");
    printf("Split L2 -> L3: "); PrintList(L3); printf("\n");

    CopyList(L3, &L1);
    printf("Copy L3 ke L1: ");
    PrintList(L1); printf("\n");
}