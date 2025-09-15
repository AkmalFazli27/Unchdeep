/*Nama File 	: simetriTabel.c*/
/*Deskripsi 	: Program memeriksa apakah 2 buah tabel itu simetri (panjangnya sama dan elemennya sama pada posisi yang sama).*/
/*Pembuat   	: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	: 25 Maret 2025 - 11:43*/

#include <stdio.h> /*header file*/

int main() {
    /*Kamus*/
    int N, i, k, j, apakahSimteri;

    /*Algoritma*/
    printf("Masukkan panjang T1: ");
    scanf("%d", &N);

    int P1[N];

    for (i = 0; i < N; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &P1[i]);
    }

    printf("\n");

    printf("Masukkan panjang T2: ");
    scanf("%d", &N);

    int P2[N];

    for (i = 0; i < N; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &P2[i]);
    }

    printf("\n");

    apakahSimteri = 1;
    if (N1 != N2) {
    apakahSimteri = 0;
} else {
    for (i = 0; i < N1; i++) {
        if (P1[i] != P2[i]) {
            apakahSimteri = 0;
            break;
        }
    }
}

    if (apakahSimteri) {
        printf("T1 dan T2 simetri");
    }

    else {
        printf("T1 dan T2 tidak simetri");
    }

    return 0;
}