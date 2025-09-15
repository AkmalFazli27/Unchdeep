/*Nama File 		: namaHari.c*/
/*Deskripsi 		: Menentukan nama hari sesuai dengan nomor hari dan jika tidak sesuai maka muncul pesan "Masukan nomor hari tidak tepat!"*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 28 Februari 2025 - 17:03*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    int hari;
    printf("Masukkan angka untuk nama hari 1 - 7 = ");
    scanf("%d",&hari);
    
    /*Algoritma*/
    if (hari > 7 || hari < 1) {
        printf("Masukkan nomor hari tidak tepat");
    }

    else {
        switch (hari) {
            case 1:
                printf("Hari Senin");
                break;
            
            case 2:
                printf("Hari Selasa");
                break;
            
            case 3:
                printf("Hari Rabu");
                break;
            
            case 4:
                printf("Hari Kamis");
                break;
            
            case 5:
                printf("Hari Jumat");
                break;
            
            case 6:
                printf("Hari Sabtu");
                break;
            
            case 7:
                printf("Hari Minggu");
                break;
        }
    }
    return 0;

}