/*Nama File 		: jarakPBola.c*/
/*Deskripsi 		: Menentukan jarak vertikal benda yang mengalami gerak parabola dengan input kecepatan awal dan waktu berupa bilangan float/real*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 1 Maret 2025 - 14:51*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    float v0, waktu, gravitasi = 9.8, gParabola;

    printf("Masukkan v0 dalam meter per detik = ");
    scanf("%f", &v0);

    printf("Masukkan waktu dalam detik = ");
    scanf("%f", &waktu);
    
    /*Algoritma*/
    gParabola = v0 * waktu - 0.5 * (gravitasi * waktu * waktu);
    
    printf("Hasil jarak vertikal benda yang mengalami gerak parabola adalah %.2f", gParabola);

    return 0;
}
