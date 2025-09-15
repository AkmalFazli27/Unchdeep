/*Nama File 	: enkripsiPesan.c*/
/*Deskripsi 	: Program mengonversi pesan terenkripsi menjadi pesan yang bisa dibaca.*/
/*Pembuat   	: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	: 26 Maret 2025 - 21:35*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int hitungPanjang(const char *str) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

int main() {
    /*Kamus*/
    char pesan[255];
    int kode;

    /*Algoritma*/
    printf("Masukkan kode: ");
    scanf("%d", &kode);

    printf("Masukkan pesan terenkripsi: ");
    scanf("%s", pesan);

    for (int i = 0; i < hitungPanjang(pesan); i++) {
        if (pesan[i] >= 'a' && pesan[i] <= 'z') {
            pesan[i] = ((pesan[i] - 'a' - kode + 26) % 26) + 'a';
        }
    }

    printf("Isi pesan: %s\n", pesan);

    return 0;
}