#include <stdio.h>

int main() {
    int N, k;
    
    printf("Masukkan berapa banyak jalan yang akan dilalui Denis: ");
    scanf("%d", &N);
    
    printf("Masukkan berapa jarak cahaya lampu: ");
    scanf("%d", &k);
    
    int adaLampu[N];
    int areaTerang[N];
    
    for (int i = 0; i < N; i++) {
        printf("Masukkan apakah di petak jalan ini ada lampu atau tidak (1 jika ada, 0 jika tidak): ");
        scanf("%d", &adaLampu[i]);
        areaTerang[i] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        if (adaLampu[i]) {
            for (int j = i - k; j <= i + k; j++) {
                if (j >= 0 && j < N) {
                    areaTerang[j] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (areaTerang[i] == 0) {
            printf("NO");
            return 0;
        }
    }
    
    printf("YES");
    return 0;
}
