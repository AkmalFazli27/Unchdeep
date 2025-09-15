/*Nama File 		: volBOlaKerct.c*/
/*Deskripsi 		: Menentukan volume bola dan volume kerucut dengan input jari - jari berupa bilangan float/real*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 3 Maret 2025 - 20.45*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    float jari, phi = 3.1415, vol_bola, vol_kerucut;

    printf("Masukkan jari - jari dalam meter = ");
    scanf("%f", &jari);

    /*Algoritma*/
    vol_bola = (4.0 / 3.0) * phi * jari * jari * jari;
    vol_kerucut = 0.5 * vol_bola;

    printf("Hasil volume bola adalah %.2f", vol_bola);
    printf("\nHasil volume kerucut adalah %.2f", vol_kerucut);

    return 0;
}
