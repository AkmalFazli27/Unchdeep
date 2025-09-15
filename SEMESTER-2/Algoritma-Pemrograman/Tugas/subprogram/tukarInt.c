/*Nama File 	: tukarInt.c*/
/*Deskripsi 	: Program menukar nilai bilangan a dan b.*/
/*Pembuat   	: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	: 26 Maret 2025 - 21:45*/

#include <stdio.h> /*header file*/

/*Program Utama*/
void tukarInt(int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main() {
    /*Kamus*/
    int a, b;

    /*Algoritma*/
    printf("Masukkan nilai a: ");
    scanf("%d", &a);
    printf("Masukkan nilai b: ");
    scanf("%d", &b);

    printf("Sebelum ditukar: \n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    tukarInt(&a, &b);

    printf("Setelah ditukar: \n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}