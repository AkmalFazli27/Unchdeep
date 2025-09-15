/*Nama File 	: jumBarKolMat.c*/
/*Deskripsi 	: Program menghitung jumlah elemen pada masing-masing baris dan kolomnya.*/
/*Pembuat   	: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	: 25 Maret 2025 - 11:43*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    int B, K, i, j, jumlah;

    /*Algoritma*/
    printf("Masukkan jumlah baris: ");
    scanf("%d", &B);
    printf("Masukkan jumlah kolom: ");
    scanf("%d", &K);

    int P[B][K];

    for (i = 0; i < B; i++) {
        for (j = 0; j < K; j++) {
            printf("Masukkan nilai elemen baris ke-%d kolom ke-%d: ", i + 1, j + 1);
            scanf("%d", &P[i][j]);
        }
    }

    for (i = 0; i < K; i++) {
        jumlah = 0;

        for (j = 0; j < B; j++) {
            jumlah += P[i][j];
        }
        printf("Baris ke-%d = %d\n", i + 1, jumlah);
    }

    for (j = 0; j < B; j++) {
        jumlah = 0;

        for (i = 0; i < K; i++) {
            jumlah += P[i][j];
        }
        printf("Kolom ke-%d = %d\n", j + 1, jumlah);
    }

    return 0;
}