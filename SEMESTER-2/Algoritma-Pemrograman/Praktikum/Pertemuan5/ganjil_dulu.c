#include <stdio.h>
#include <stdlib.h>

void tukarbil(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int N, i, adaTukar = 1;

    printf("Masukkan panjang tabel: ");
    scanf("%d", &N);

    int nilai[N];

    for (i = 0; i < N; i++) {
        printf("Masukkan nilai elemen ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    while (adaTukar == 1) {
        adaTukar = 0;
        for (i = 0; i < N - 1; i++) {
            if ((nilai[i] % 2 == 0) && (nilai[i + 1] % 2 == 1)) {
                tukarbil(&nilai[i], &nilai[i + 1]);
                adaTukar = 1;
            }
        }
    }

    for (i = 0; i < N; i++) {
        printf("%d ", nilai[i]);
    }

    return 0;
}