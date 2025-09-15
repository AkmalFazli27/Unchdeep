/*Nama File 		: BilPrimaN.c*/
/*Deskripsi 		: Mencetak bilangan prima sampai dengan bilangan integer sembarang N*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 8 Maret 2025 - 15:21*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() 
{
    /*Kamus*/
    int i, j, N, faktor;
    printf("Masukkan nilai N = ");
    scanf("%d", &N);
    
    if (N > 0) {
        for (i = 1; i <= N; i++) {
            faktor = 0;

            for (j = 1; j <= i; j++) {
                if (i % j == 0) {
                    faktor ++;
                }
            }

            if (faktor == 2) {
                printf("%d,", i);
            }
        }
        printf("\b \n");
    } 
    
    else {
        printf("N harus lebih dari 0!");
    } 
    return 0;
}



