#include <stdio.h>
#include "titik0.h"

int main() {
    Titik A, B;

    printf("Baca titik A:\n");
    bacaTitik(&A);

    printf("Baca titik B:\n");
    bacaTitik(&B);

    printf("Titik A = ");
    tulisTitik(A);
    printf("\n");

    printf("Titik B = ");
    tulisTitik(B);
    printf("\n");

    printf("Apakah A == B? %d\n", isEqual(A, B));
    printf("Apakah A != B? %d\n", isNotEqual(A, B));
    printf("Apakah A < B? %d\n", isLessThan(A, B));
    printf("Apakah A > B? %d\n", isGreaterThan(A, B));

    return 0;
}