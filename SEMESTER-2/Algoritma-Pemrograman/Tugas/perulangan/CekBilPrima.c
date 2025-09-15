/*Nama File 		: CekBilPrima.c*/
/*Deskripsi 		: Menentukan apakah input N bilangan integer adalah bilangan prima atau bukan*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 6 Maret 2025 - 11:21*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() 
{
    /*Kamus*/
    int N, i, faktor;
    printf("Masukkan nilai N = ");
    scanf("%d",&N);
    faktor = 0;
    
    if (N <= 0) {
        printf("N harus positif");
    }
    
    else {
        for (i = 1; i <= N; i++) {
            if (N % i == 0) {
                faktor ++;
            }
        }
        
        if (faktor == 2) {
            printf("Bilangan %d adalah bilangan prima",N);
        }
        
        else {
            printf("Bilangan %d adalah bukan bilangan prima",N);
        }
        
    }

    return 0;
}


