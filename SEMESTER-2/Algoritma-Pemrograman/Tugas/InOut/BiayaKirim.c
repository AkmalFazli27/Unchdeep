/*Nama File 		: BiayaKirim.c*/
/*Deskripsi 		: Menentukan biaya kirim dengan input berat dan jarak berupa bilangan integer*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 1 Maret 2025 - 14:51*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    int berat, jarak, biaya_kirim;

    printf("Masukkan berat barang dalam kg = ");
    scanf("%d", &berat); 
    
    printf("Masukkan jarak pengiriman dalam km = ");
    scanf("%d", &jarak); 
    
    /*Algoritma*/
    biaya_kirim = 10000 + (5000 * berat) + (2000 * jarak);
    
    printf("Biaya pengiriman adalah %d", biaya_kirim);

    return 0;
}
