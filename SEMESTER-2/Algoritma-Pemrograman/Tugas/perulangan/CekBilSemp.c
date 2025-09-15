/*Nama File 		: CekBilSemp.c*/
/*Deskripsi 		: Menentukan apakah input N bilangan integer adalah bilangan sempurna atau bukan*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 6 Maret 2025 - 11:35*/

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
    if (N <= 0) {
        printf("N harus positif");
    }

    else {
        for (i = 1; i < N; i++) 
        {
            if (N % i == 0) {
                jumlah += i;
            }
        }

        if (jumlah == N) {
            printf("Angka %d adalah bilangan sempurna", N);
        }

        else {
            printf("Angka %d bukan bilangan sempurna", N);
        }
    }
    return 0;
}


