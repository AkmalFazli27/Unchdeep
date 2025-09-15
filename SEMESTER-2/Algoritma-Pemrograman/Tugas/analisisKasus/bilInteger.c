/*Nama File 		: bilInteger.c*/
/*Deskripsi 		: Mengecek input bilangan integer apakah bilangan positif atau nol atau negatif*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 28 Februari 2025 - 16:52*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    int i;
    printf("Masukkan angka = ");
    scanf("%d",&i);
    
    /*Algoritma*/
    if (i < 0) {
        printf("Angka ini negatif");
    }

    else if (i > 0) {
        printf("Angka ini positif");
    }

    else {
        printf("Angka ini bernilai 0");
    }
    
    return 0;

}