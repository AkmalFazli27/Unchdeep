#include <stdio.h>

int main() {
    int angka;
    printf("Masukkan nilai : ");
    scanf("%d", &angka);
    
    if (angka % 2 == 0)
    {
        printf("Angka ini genap");
    }
    else
    {
        printf("Angka ini ganjil");
    }
    return 0;
}

