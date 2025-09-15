#include <stdio.h>

int main() {
    int i, j, maxKolom, jumlah, jumlahBulan[3], maxJumlah;
    int tabel[3][4] = {
        {10, 15, 10, 5},
        {20, 25, 20, 15},
        {10, 5, 14, 3}
    };

    for (j = 0; j < 4; j++) {
        jumlah = 0;
        for (i = 0; i < 3; i++) {
            jumlah += tabel[i][j];
        }
        jumlahBulan[j] = jumlah;
    }

    maxJumlah = jumlahBulan[0];
    for (j = 1; j < 4; j++) {
        if (maxJumlah < jumlahBulan[j]) {
            maxJumlah = jumlahBulan[j];
            maxKolom = j;
        }
    }

    if (maxKolom == 0) {
        printf("Jumlah penjualan tertinggi terjadi pada bulan Januari dengan jumlah %d", maxJumlah);
    }

    if (maxKolom == 1) {
        printf("Jumlah penjualan tertinggi terjadi pada bulan Februari dengan jumlah %d", maxJumlah);
    }

    if (maxKolom == 2) {
        printf("Jumlah penjualan tertinggi terjadi pada bulan Maret dengan jumlah %d", maxJumlah);
    }
    
    if (maxKolom == 3) {
        printf("Jumlah penjualan tertinggi terjadi pada bulan April dengan jumlah %d", maxJumlah);
    }
    return 0;
}