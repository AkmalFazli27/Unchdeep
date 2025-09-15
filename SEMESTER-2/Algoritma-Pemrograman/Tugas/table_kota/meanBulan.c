#include <stdio.h>

int main() {
    int i, j, maxKolom;
    float jumlah, maxMean, meanBulan[4];
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
        meanBulan[j] = jumlah / 3.0;
    }

    maxMean = meanBulan[0];
    for (j = 1; j < 4; j++) {
        if (maxMean < meanBulan[j]) {
            maxMean = meanBulan[j];
            maxKolom = j;
        }
    }

    if (maxKolom == 0) {
        printf("Rata - rata penjualan tertinggi terjadi pada bulan Januari dengan nilai rata - rata %.2f", maxMean);
    }

    if (maxKolom == 1) {
        printf("Rata - rata penjualan tertinggi terjadi pada bulan Februari dengan nilai rata - rata %.2f", maxMean);
    }

    if (maxKolom == 2) {
        printf("Rata - rata penjualan tertinggi terjadi pada bulan Maret dengan nilai rata - rata %.2f", maxMean);
    }

    if (maxKolom == 3) {
        printf("Rata - rata penjualan tertinggi terjadi pada bulan April dengan nilai rata - rata %.2f", maxMean);
    }
    return 0;
}