#include <stdio.h>

int main() {
    int N, NEff, i;

    printf("Masukkan panjang tabel: ");
    scanf("%d", &N);

    int P[N];

    printf("Masukkan panjang NEff: ");
    scanf("%d", &NEff);

    for (i = 0; i < NEff; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &P[i]);
    }

    for (i = NEff; i < N; i++) {
        P[i] = 0;
    }

    int T[N]; // tabel baru setelah di tuker
    int index = N - NEff; // buat ganti nilai tabel baru yg bukan NEff menjadi 0

    for (i = 0; i < index; i++) {
        T[i] = 0;
    }

    for (i = 0; i < NEff; i++) {
        T[index + i] = P[i];
    }

    for (i = 0; i < N; i++) {
        printf("Nilai baru ke-%d: %d\n", i + 1, T[i]);
    }
    
    return 0;
}