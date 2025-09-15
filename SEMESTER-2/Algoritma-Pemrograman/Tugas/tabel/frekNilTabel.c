/*Nama File 	: frekNilTabel.c*/
/*Deskripsi 	: Program menampilkan nilai yang frekuensi kemunculannya lebih dari satu pada sebuah tabel.*/
/*Pembuat   	: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	: 24 Maret 2025 - 14:12*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    int N, i, k, j, sudahDicek, count;

    /*Algoritma*/
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

    printf("Angka yang muncul lebih dari sekali: ");

    for (int i = 0; i < N; i++) {
        if (P[i] <= 0) {
            printf("Nilai bilangan harus positif.");
            break;
        }

        sudahDicek = 0;

        for (k = 0; k < i; k++) {
            if (P[i] == P[k])
            {
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
            printf("%d\n", P[i]);
        }
    }

    return 0;
}