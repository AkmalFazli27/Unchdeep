/*Nama File 		: JumDeret.c*/
/*Deskripsi 		: Menentukan jumlah deret bilangan integer dengan input N berupa bilangan terakhir*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 6 Maret 2025 - 10:41*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() 
{
    /*Kamus*/
    int N, i, jumlah;
    printf("Masukkan nilai N = ");
    scanf("%d",&N);
    jumlah = 0;
    
    /*Algoritma*/
    for (i = 1; i <= N; i++) {
        jumlah += i;
    }
    printf("Jumlah deret = %d", jumlah);
    return 0;
}


