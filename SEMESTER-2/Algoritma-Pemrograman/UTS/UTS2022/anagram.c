#include <stdio.h>

int main() {
    int i, count, sizeT1, sizeT2;

    printf("Masukkan panjang T1: ");
    scanf("%d",&sizeT1);
    printf("Masukkan panjang T2: ");
    scanf("%d",&sizeT2);

    char T1[sizeT1], T2[sizeT2];

    for (i = 0; i < sizeT1; i++) {
        printf("Masukkan karakter ke-%d T1: ", i + 1);
        scanf(" %c", &T1[i]);
    }
    
    for (i = 0; i < sizeT2; i++) {
        printf("Masukkan karakter ke-%d T2: ", i + 1);
        scanf(" %c", &T2[i]);
    }

    if (sizeT1 != sizeT2) {
        printf("T1 dan T2 tidak anagram!");
    }

    else {
        int countT1 = 0, countT2 = 0;
        for (i = 0; i < sizeT1 ; i++) {
            for (int j = 0; j < sizeT2; j++) {
                if (T1[i] == T2[j]) {
                    countT1 += 1;
                }
            }
            for (int j = 0; j < sizeT1; j++) {
                if (T1[i] == T2[j]) {
                    countT2 += 1;
                }
            }
        }

        if (countT1 == countT2) {
            printf("T1 dan T2 anagram!");
        }

        else {
            printf("T1 dan T2 tidak anagram!");
        }
    }

    return 0;
}