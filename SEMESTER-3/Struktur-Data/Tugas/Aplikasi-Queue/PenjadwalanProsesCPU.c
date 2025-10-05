#include <stdio.h>
#include "boolean.h" // Jika Anda menggunakannya
#include "proses.h"
#include "tqueue.h"

void SetDaftar(daftarProses *DP, tqueue *Q);
void sortDaftarProses(daftarProses *DP); 
void DaftarKeQueue(tqueue *Q, daftarProses DP); 

void printEksekusi(tqueue *Q) {
    int currTime = 0;
    int startTime, finishTime;
    printf("\n");
    for (int i = 1; i <= 5; i++) {
        printf("\n");
        startTime = currTime;
        finishTime = currTime + GetBurstTime(Q->wadah[i]);
        printf("Eksekusi: %c, Mulai: %d, Selesai: %d", GetIDProses(Q->wadah[i]), startTime, finishTime);
        currTime = finishTime;
    }
}

int main() {
    // Kamus
    tqueue Q; // antrean proses di CPU
    daftarProses DP;
    Proses P1, P2, P3, P4, P5; // Proses {proses yang diantrekan}

    // Algotritma
    // {membuat 5 buah proses sesuai dengan ketentuan NIM masing-masing}
    MakeProses(&P1, 'A', 3);
    MakeProses(&P2, 'B', 6);
    MakeProses(&P3, 'C', 1);
    MakeProses(&P4, 'D', 2);
    MakeProses(&P5, 'E', 3);

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

    SetDaftar(&DP, &Q);

    sortDaftarProses(&DP);

    DaftarKeQueue(&Q, DP);

    printf("\n\nKeadaan queue setelah diurutkan berdasarkan Shortest Job First:\n");
    viewQueue(&Q);

    printEksekusi(&Q);
    return 0;
}