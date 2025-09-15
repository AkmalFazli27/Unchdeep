#include <stdio.h>
#include <stdlib.h>

int ganjil(int count_ganjil, int idx_ganjil, int tab_ganjil[]) {
    if (idx_ganjil == 0) {
        return 0;
    }

    if (count_ganjil % 2 != 0) {
        return tab_ganjil[count_ganjil / 2];
    }

    else {
        return (tab_ganjil[count_ganjil / 2] + tab_ganjil[(count_ganjil / 2) - 1]) / 2; 
    }
}

int genap(int count_genap, int idx_genap, int tab_genap[]) {
    if (idx_genap == 0) {
        return 0;
    }

    if (count_genap % 2 != 0) {
        return tab_genap[count_genap / 2];
    }

    else {
        return (tab_genap[count_genap / 2] + tab_genap[(count_genap / 2) - 1]) / 2; 
    }
}

int main() {
    int N, i, j, count_ganjil = 0, count_genap = 0, tengah_genap, tengah_ganjil;
    float mean;

    printf("Masukkan nilai N: ");
    scanf("%d",&N);

    int tab_angka[N];

    if (N <= 1) {
        printf("Panjang data harus lebih dari 2!");
        return 1;
    }

    for (i = 0; i < N; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d",&tab_angka[i]);
    }

    for (i = 0; i < N; i++) {
        if (tab_angka[i] % 2 == 0) {
            count_genap += 1;
        }
        else {
            count_ganjil += 1;
        }
    }
    
    int tab_genap[count_genap], tab_ganjil[count_ganjil];
    int idx_genap = 0, idx_ganjil = 0;

    for (i = 0; i < N; i++) {
        if (tab_angka[i] % 2 == 0) {
            if (idx_genap < count_genap) {
                tab_genap[idx_genap] = tab_angka[i];
                idx_genap += 1;
            }
        }
        else {
            if (idx_ganjil < count_ganjil) {
                tab_ganjil[idx_ganjil] = tab_angka[i];
                idx_ganjil += 1;
            }
        }
    }


    printf("list ganjil: ");
    for (int i = 0; i < count_ganjil; i++) {
        printf("%d ", tab_ganjil[i]);
    }
    printf("\n");
    printf("list genap: ");
    for (int i = 0; i < count_genap; i++) {
        printf("%d ", tab_genap[i]);
    }
    printf("\n");

    tengah_ganjil = ganjil(count_ganjil, idx_ganjil, tab_ganjil);
    tengah_genap = genap(count_genap, idx_genap, tab_genap);

    printf("tengah ganjil = %d \n", tengah_ganjil);
    printf("tengah genap = %d\n", tengah_genap);

    if (tengah_ganjil == 0) {
        mean = tengah_genap;
    }

    else if (tengah_genap == 0) {
        mean = tengah_ganjil;
    }

    else {
        mean = (float) (tengah_ganjil + tengah_genap) / 2.0;
    }

    printf("%.3f", mean);
    

}