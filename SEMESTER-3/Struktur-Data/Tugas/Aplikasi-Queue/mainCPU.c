#include <stdio.h>
#include "proses.h"
#include "tqueue.h"

int main() {
    // Kamus
    tqueue Q;
    Proses P1, P2, P3, P4, P5, prosesDieksekusi, temp;
    int waktuSkrg = 0;
    int waktuMulai, waktuSelesai, i, j;

    // Algotritma
    makeProses(&P1, 'A', 3);
    makeProses(&P2, 'B', 6);
    makeProses(&P3, 'C', 1);
    makeProses(&P4, 'D', 2);
    makeProses(&P5, 'E', 3);

    createQueue(&Q);

    enqueue(&Q, P1);
    enqueue(&Q, P2);
    enqueue(&Q, P3);
    enqueue(&Q, P4);
    enqueue(&Q, P5);

    printf("Keadaan queue awal:\n");
    printQueue(&Q);

    printf("\n\nKeadaan queue setelah diurutkan berdasarkan shortest job first:\n");
    for (i = 1; i <= 5 - 1; i++) {
        for (j = 1; j <= 5 - i; j++) {
            if (getBurstTime(Q.wadah[j]) > getBurstTime(Q.wadah[j + 1])) {
                temp = Q.wadah[j];
                Q.wadah[j] = Q.wadah[j + 1];
                Q.wadah[j + 1] = temp;
            }
        }
    }
    printQueue(&Q);

    printf("\n\nUrutan eksekusi proses:\n");
    while (!isEmptyQueue(Q)) {
        waktuMulai = waktuSkrg;
        waktuSelesai = waktuSkrg + getBurstTime(infoHead(Q));
        printf("Eksekusi Proses '%c', Mulai: %d, Selesai: %d\n",
               getIDProses(infoHead(Q)),
               waktuMulai,
               waktuSelesai);

        waktuSkrg = waktuSelesai;
        dequeue(&Q, &prosesDieksekusi);
    }
    return 0;
}