/*Nama File 	: nilMax2Tabel.c*/
/*Deskripsi 	: Program menampilkan nilai maksimum kedua dari sebuah tabel.*/
/*Pembuat   	: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	: 24 Maret 2025 - 13:02*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    int i, N, maxTabel, max2Tabel;

    /*Algoritma*/
    maxTabel = 0;
    max2Tabel = 0;

    printf("Masukkan panjang tabel: ");
    scanf("%d", &N);

    int P[N];

    for (i = 0; i < N; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &P[i]);
    }

    for (i = 0; i < N; i++) {
        if (P[i] > maxTabel) {
            max2Tabel = maxTabel;
            maxTabel = P[i];
        }

        if (maxTabel > P[i] && P[i] > max2Tabel) {
            max2Tabel = P[i];
        }
    }
    printf("Nilai maksimum kedua: %d", max2Tabel);

    return 0;
}