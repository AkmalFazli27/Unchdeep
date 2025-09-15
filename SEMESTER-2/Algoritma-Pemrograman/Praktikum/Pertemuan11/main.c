#include <stdio.h>
#include "kalkulator.h"

int main () {
    int a, b;

    printf("Nilai a: ");
    scanf("%d", &a);

    printf("Nilai b: ");
    scanf("%d", &b);

    tambah(&a, b);
    printf("%d", a);

    return 0;
}