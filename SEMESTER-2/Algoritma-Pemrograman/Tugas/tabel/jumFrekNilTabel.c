/*Nama File 	: jumFrekNilTabel.c*/
/*Deskripsi 	: Program menampilkan jumlah nilai yang frekuensi kemunculannya lebih dari satu pada sebuah tabel.*/
/*Pembuat   	: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	: 24 Maret 2025 - 16:07*/

#include <stdio.h> /*header file*/

int main() {
    /*Kamus*/
    int N, i, k, j, jumlah, sudahDicek, count;

    /*Algoritma*/
    jumlah = 0;
    printf("Masukkan panjang tabel: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Panjang tabel harus lebih dari 0.\n");
    }

    int P[N];

    for (i = 0; i < N; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &P[i]);
    }

    for (i = 0; i < N; i++) {
        if (P[i] <= 0) {
            printf("Nilai bilangan harus positif.");
            break;
        }

        sudahDicek = 0;

        for (k = 0; k < i; k++) {
            if (P[i] == P[k]) {
                sudahDicek = 1;
                break;
            }
        }

        if (sudahDicek) {
            continue;
        }

        count = 0;

        for (j = 0; j < N; j++) {
            if (P[i] == P[j]) {
                count++;
            }
        }

        if (count > 1) {
            jumlah += P[i] * count;
        }
    }

    printf("Hasil penjumlahan semua angka yang muncul lebih dari satu kali = %d", jumlah);

    return 0;
}