/*Nama File 		: FaktorBil.c*/
/*Deskripsi 		: Menentukan faktor bilangan dari input N berupa biangan integer*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 6 Maret 2025 - 10:50*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() 
{
    /*Kamus*/
    int N, i;
    printf("Masukkan nilai N = ");
    scanf("%d",&N);
    
    printf("Faktor dari %d adalah ",N);

    /*Algoritma*/
    if (N <= 0) {
        printf("N harus positif");
    }
    
    else {
        for (i = 1; i <= N; i++) {
            if (N % i == 0) {
                if (N == i) {
                    printf("%d",i);
                }
                else {
                    printf("%d,",i);
                }
            }
        }
    }
    return 0;
}


