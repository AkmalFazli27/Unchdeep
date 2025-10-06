#include <stdio.h>
#include "proses.h"
#include "tqueue.h"

int main() {
    // Kamus
    tqueue Q; // antrean proses di CPU
    Proses P1, P2, P3, P4, P5; // Proses {proses yang diantrekan}
    int waktuSkrg = 0;
    int waktuMulai, waktuSelesai, i, j;
    Proses prosesDieksekusi; 

    // Algotritma
    // {membuat 5 buah proses sesuai dengan ketentuan NIM masing-masing}
    makeProses(&P1, 'A', 3);
    makeProses(&P2, 'B', 6);
    makeProses(&P3, 'C', 1);
    makeProses(&P4, 'D', 2);
    makeProses(&P5, 'E', 3);

    // {inisialisasi Q untuk antrean proses}
    createQueue(&Q);

    // {proses masuk ke antrean sesuai dengan urutan penulisan}
    enqueue(&Q, P1);
    enqueue(&Q, P2);
    enqueue(&Q, P3);
    enqueue(&Q, P4);
    enqueue(&Q, P5);

    printf("Keadaan queue awal:\n");
    printQueue(&Q);

    printf("\n\nKeadaan queue setelah diurutkan berdasarkan Shortest Job First:\n");
    for (i = 1; i <= 5 - 1; i++) {
        for (j = 1; j <= 5 - i; j++) {
            if (getBurstTime(Q.wadah[j]) > getBurstTime(Q.wadah[j + 1])) {
                Proses temp = Q.wadah[j];
                Q.wadah[j] = Q.wadah[j + 1];
                Q.wadah[j + 1] = temp;
            }
        }
    }
    printQueue(&Q);

    printf("\n\n--- Urutan Eksekusi Proses ---\n");
    while (!isEmptyQueue(Q)) {
        Proses prosesSkrg = infoHead(Q);
        waktuMulai = waktuSkrg;
        waktuSelesai = waktuSkrg + getBurstTime(prosesSkrg);

        printf("Eksekusi Proses '%c', Mulai: %d, Selesai: %d (Burst Time: %d)\n",
               getIDProses(prosesSkrg),
               waktuMulai,
               waktuSelesai,
               getBurstTime(prosesSkrg));

        waktuSkrg = waktuSelesai;
        dequeue(&Q, &prosesDieksekusi);
    }

    return 0;
}