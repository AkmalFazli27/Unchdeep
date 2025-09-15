#include <stdio.h>

int main() {
    int i, j, maxPenjualan, iKota, iBulan, nilai;
    int tabel[3][4] = {
        {10, 15, 10, 5},
        {20, 25, 20, 15},
        {10, 5, 14, 3}
    };
    char dataBulan[4][10] = {"Januari", "Februari", "Maret", "April"};
    char dataKota[3][20] = {"Semarang", "Jakarta", "Yogyakarta"};
    char *kota, *bulan;

    maxPenjualan = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (maxPenjualan < tabel[i][j]) {
                maxPenjualan = tabel[i][j];
                iKota = j;
                iBulan = i;
            }
        }
    }
    bulan = dataBulan[iBulan];
    kota = dataKota[iKota];

    printf("Penjualan tertinggi secara keseluruhan pada bulan %s, Kota %s, dengan penjualan %d", bulan, kota, maxPenjualan);
    
    return 0;
}