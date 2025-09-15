#include <stdio.h>

int main() {
    int i, k, N1, N2;

    printf("Masukkan panjang T1: ");
    scanf("%d",&N1);
    printf("Masukkan panjang T2: ");
    scanf("%d",&N2);

    int T1[N1], T2[N2];

    for (i = 0; i < N1; i++) {
        printf("Masukkan nilai ke-%d T1: ", i + 1);
        scanf("%d", &T1[i]);
    }
    
    for (i = 0; i < N2; i++) {
        printf("Masukkan nilai ke-%d T2: ", i + 1);
        scanf("%d", &T2[i]);
    }
    
    int isSimetris = 0;
    
    for (k = 0; k < N1; k++) {
        if (T1[k] == T2[k]) {
            isSimetris = 1;
            continue;
        }

        else {
            printf("T1 dan T2 tidak simetris");
            break;
        }
    }

    if (isSimetris) {
        printf("T1 dan T2 simetris");
    }

}