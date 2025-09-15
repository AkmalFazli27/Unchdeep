#include <stdio.h>

int main () {
    int i, N, k;

    printf("Masukkan panjang jalan: ");
    scanf("%d", &N);
    printf("Masukkan sisi terang lampu: ");
    scanf("%d", &k);

    int jalan[N];

    for (i = 0; i < N; i++) {
        printf("Masukkan tata letak lampu ke-%d: ", i + 1);
        scanf("%d", &jalan[i]);
    }
}