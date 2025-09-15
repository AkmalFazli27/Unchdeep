#include <stdio.h>

int main() {
    int i, j, maxBaris, jumlah, jumlahKota[3], maxJumlah;
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
        jumlahKota[i] = jumlah;
    }

    maxJumlah = jumlahKota[0];
    for (i = 1; i < 3; i++) {
        if (maxJumlah < jumlahKota[i]) {
            maxJumlah = jumlahKota[i];
            maxBaris = i;
        }
    }

    if (maxBaris == 0) {
        printf("Jumlah penjualan tertinggi terjadi pada Kota Semarang dengan jumlah %d", maxJumlah);
    }

    if (maxBaris == 1) {
        printf("Jumlah penjualan tertinggi terjadi pada Kota Jakarta dengan jumlah %d", maxJumlah);
    }

    if (maxBaris == 2) {
        printf("Jumlah penjualan tertinggi terjadi pada Kota Yogyakarta dengan jumlah %d", maxJumlah);
    }
    return 0;
}