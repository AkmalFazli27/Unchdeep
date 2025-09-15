#include <stdio.h>

int main() {
    int i, k, jum;
    
    i = 1;
    jum = 0;

    while (i <= 4) {
        if (i % 2 == 0) {
            for (k = 1; k <= i; k++) {
                jum = jum + i + k;
            }
        }

        else {
            jum = jum + i + 1;
        }

        i += 1;
    }

    printf("Jumlah = %d",jum);
}