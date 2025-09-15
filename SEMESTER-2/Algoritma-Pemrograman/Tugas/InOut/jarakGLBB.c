/*Nama File 		: jarakGLBB.c*/
/*Deskripsi 		: Menentukan jarak benda yang megalami GLBB dengan input waktu, percepatan, dan jarak berupa bilangan float/real*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 1 Maret 2025 - 14:51*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    float v0, waktu, percepatan, jarak;

    printf("Masukkan v0 dalam meter per detik = ");
    scanf("%f", &v0); // Input kecepatan awal dalam meter per detik berupa float

    printf("Masukkan waktu dalam detik = ");
    scanf("%f", &waktu); // Input waktu dalam detik berupa float

    printf("Masukkan percepatan dalam meter per detik kuadrat = ");
    scanf("%f", &percepatan); // Input percepatan dalam meter per detik kuadrat berupa float
    
    /*Algoritma*/
    jarak = v0 * waktu + 0.5 * (percepatan * waktu * waktu); // Rumus mencari jarak GLBB
    
    printf("Hasil jarak benda yang mengalami GLBB adalah %.2f", jarak);

    return 0;
}
