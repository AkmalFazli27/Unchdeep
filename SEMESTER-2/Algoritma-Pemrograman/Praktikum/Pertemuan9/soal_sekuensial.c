#include <stdio.h>

int main() {
    int N, i, total_A = 0, total_B = 0, total_C = 0, total_D = 0, total_E = 0, sum_all = 0;
    float mean = 0;

    printf("Masukkan panjang data: ");
    scanf("%d", &N);

    int tab_nilai[N], tab_konversi[N];

    if (N <= 0) {
        printf("Panjang data harus positf!");
    }

    for (i = 0; i < N; i++) {
        printf("Masukkan harga ke-%d: ", i + 1);
        scanf("%d", &tab_nilai[i]);
    }

    for (i = 0; i < N; i++) {
        if (tab_nilai[i] >= 80) {
            tab_konversi[i] = 'A';
            total_A += 1;
        }

        else if (tab_nilai[i] >= 70) {
            tab_konversi[i] = 'B';
            total_B += 1;
        }

        else if (tab_nilai[i] >= 55) {
            tab_konversi[i] = 'C';
            total_C += 1;
        }

        else if (tab_nilai[i] >= 40) {
            tab_konversi[i] = 'D';
            total_D += 1;
        }

        else if (tab_nilai[i] < 40) {
            tab_konversi[i] = 'E';
            total_E += 1;
        }
    }

    for (i = 0; i < N; i++) {
        sum_all += tab_nilai[i];
    }

    mean = sum_all / N;

    printf("Banyak A: %d\n", total_A);
    printf("Banyak B: %d\n", total_B);
    printf("Banyak C: %d\n", total_C);
    printf("Banyak D: %d\n", total_D);
    printf("Banyak E: %d\n", total_E);
    printf("Nilai rata - rata: %.2f", mean);
    
    return 0;
}