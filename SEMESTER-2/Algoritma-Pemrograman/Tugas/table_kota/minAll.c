#include <stdio.h>

int main() {
    int i, j, minPenjualan, iKota, iBulan, nilai;
    int tabel[3][4] = {
        {10, 15, 10, 5},
        {20, 25, 20, 15},
        {10, 5, 14, 3}
    };
    char dataBulan[4][10] = {"Januari", "Februari", "Maret", "April"};
    char dataKota[3][20] = {"Semarang", "Jakarta", "Yogyakarta"};
    char *kota, *bulan;

    minPenjualan = tabel[0][0];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (minPenjualan >= tabel[i][j]) {
                minPenjualan = tabel[i][j];
                iKota = i;
                iBulan = j;
            }
        }
    }
    
    bulan = dataBulan[iBulan];
    kota = dataKota[iKota];
    
    printf("Penjualan terendah secara keseluruhan pada bulan %s, Kota %s, dengan penjualan %d", bulan, kota, minPenjualan);

    return 0;
}