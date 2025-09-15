#include <stdio.h>

int main() {
    int i, S, P;

    printf("Masukkan nilai S: ");
    scanf("%d",&S);
    printf("Masukkan nilai P: ");
    scanf("%d",&P);

    if (S <= 0 || P <= 0) {
        printf("S dan P harus positif!");
    }

    if (P >= S) {
        printf("P harus kurang dari sama dengan S!");
    }

    while (S > 0 && P > 0) {
        if (P % 2 == 0) {
            S -= 1;
        }
        else {
            S -= 2;
        }

        P -= 2;

        printf("S = %d, P = %d\n",S,P);

    }  
    return 0;
}