/*Nama File 		: CekSegitiga.c*/
/*Deskripsi 		: Menentukan bentuk segitiga sama kaki atau sama sisi atau sembarang dari inputan 3 buah sisi segitiga berupa bilangan integer*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 28 Februari 2025 - 16:55*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    int sisi1, sisi2, sisi3;
    printf("Masukkan sisi 1 = ");
    scanf("%d", &sisi1);
    printf("Masukkan sisi 2 = ");
    scanf("%d", &sisi2);
    printf("Masukkan sisi 3 = ");
    scanf("%d", &sisi3);

    /*Algoritma*/
    if (sisi1 <= 0 || sisi2 <= 0 || sisi3 <= 0) {
        printf("Terdapat nilai yang bukan sisi segitiga!");
    }
    
    if (sisi1 == sisi2 && sisi2 == sisi3 && sisi1 == sisi3) {
        printf("Segitiga sama sisi");
    }

    if (sisi1 == sisi2 || sisi1 == sisi3 || sisi2 == sisi3) {
        printf("Segitiga sama kaki");
    }

    printf("Segitiga sembarang");
    
    return 0;
}