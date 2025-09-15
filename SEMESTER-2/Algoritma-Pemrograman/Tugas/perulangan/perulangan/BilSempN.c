/*Nama File 		: BilSempN.c*/
/*Deskripsi 		: Mencetak bilangan sempurna sampai dengan bilangan integer N*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 8 Maret 2025 - 14:04*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() 
{
    /*Kamus*/
    int N, i, j, jumlah;
    printf("Masukkan nilai N = ");
    scanf("%d", &N);

    /*Algoritma*/
    if (N <= 0) {
        printf("Angka harus positif");
    }

    else {
        for (i = 1; i <= N; i++) { 
            jumlah = 0;  
    
            for (j = 1; j < i; j++) {  
                if (i % j == 0) {
                    jumlah += j;
                }
            }
    
            if (jumlah == i) {  
                printf("%d,", i);
            }
        }
        printf("\b \n");
    }
    return 0;
}