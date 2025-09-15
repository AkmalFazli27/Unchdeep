#include <stdio.h>

int main() {
    int i, j, maxBaris;
    float jumlah, maxMean, meanKota[3];
    int tabel[3][4] = {
        {10, 15, 10, 5},
        {20, 25, 20, 15},
        {10, 5, 14, 3}
    };

    for (i = 0; i < 3; i++) {
        jumlah = 0;
        for (j = 0; j < 4; j++) {
            jumlah += tabel[i][j];
        }
        meanKota[i] = jumlah / 4.0;
    }

    maxMean = meanKota[0];
    for (j = 1; j < 3; j++) {
        if (maxMean < meanKota[j]) {
            maxMean = meanKota[j];
            maxBaris = j;
        }
    }

    if (maxBaris == 0) {
        printf("Rata - rata penjualan tertinggi terjadi pada Kota Semarang dengan nilai rata - rata %.2f", maxMean);
    }

    if (maxBaris == 1) {
        printf("Rata - rata penjualan tertinggi terjadi pada Kota Jakarta dengan nilai rata - rata %.2f", maxMean);
    }

    if (maxBaris == 2) {
        printf("Rata - rata penjualan tertinggi terjadi pada Kota Yogyakarta dengan nilai rata - rata %.2f", maxMean);
    }

    return 0;
}