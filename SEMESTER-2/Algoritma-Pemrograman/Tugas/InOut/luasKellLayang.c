/*Nama File 		: luasKellLayang.c*/
/*Deskripsi 		: Menentukan luas layang-layang dan keliling layang - layang yang diberi input 2 sisi dan 2 diagonal berupa bilangan float/real*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 3 Maret 2025 - 21:08*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    float s1, s2, d1, d2, kel_layang, luas_layang;

    printf("Masukkan sisi satu layang - layang dalam meter = ");
    scanf("%f", &s1);
    printf("Masukkan sisi dua layang - layang dalam meter = ");
    scanf("%f", &s2);
    printf("Masukkan diagonal satu layang - layang dalam meter = ");
    scanf("%f", &d1);
    printf("Masukkan diagonal dua layang - layang dalam meter = ");
    scanf("%f", &d2);

    /*Algoritma*/
    kel_layang = 2 * (s1 + s2);
    luas_layang = 0.5 * d1 * d2;

    printf("Hasil keliling layang - layang adalah %.1f", kel_layang);
    printf("\nHasil luas layang - layang adalah %.1f", luas_layang);

    return 0;
}
