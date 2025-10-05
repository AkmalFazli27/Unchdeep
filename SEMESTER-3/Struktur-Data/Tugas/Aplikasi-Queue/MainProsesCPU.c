#include <stdio.h>
#include "ProsesQueue.h"

int main() {
    // Kamus
    tqueue Q; // antrean proses di CPU
    daftarProses DP;
    Proses P1, P2, P3, P4, P5; // Proses {proses yang diantrekan}

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
    viewQueue(&Q);

    setDaftar(&DP, &Q);

    sortDaftarProses(&DP);

    daftarKeQueue(&Q, DP);

    printf("\n\nKeadaan queue setelah diurutkan berdasarkan Shortest Job First:\n");
    viewQueue(&Q);

    printf("\n\n--- Urutan Eksekusi Proses ---\n");
    printEksekusi(&Q);
    
    return 0;
}