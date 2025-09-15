/*Nama File 		: gayaSentr.c*/
/*Deskripsi 		: Menentukan gaya sentripetal dengan input massa, kecepatan, dan jari-jari berupa bilagan float/real*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 3 Maret 2025 - 20:50*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    float massa, kecepatan, jari, gaya;

    printf("Masukkan massa dalam kg = ");
    scanf("%f", &massa);

    printf("Masukkan kecepatan dalam meter/detik = ");
    scanf("%f", &kecepatan);

    printf("Masukkan jari - jari dalam meter = ");
    scanf("%f", &jari);
    
    /*Algoritma*/
    gaya = massa * (kecepatan * kecepatan / jari);
    
    printf("Hasil gaya sentripetal adalah %.2f", gaya);

    return 0;
}
