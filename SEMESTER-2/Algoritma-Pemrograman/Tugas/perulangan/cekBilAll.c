/*Nama File 		: cekBilAll.c*/
/*Deskripsi 		: Menentukan apakah input N bilangan integer adalah bilangan prima atau bilangan sempurna atau bilangan biasa*/
/*Pembuat   		: 24060124130123 - Muhammad Akmal Fazli Riyadi*/
/*Tgl Pembuatan	    : 8 Maret 2025 - 15:51*/

#include <stdio.h> /*header file*/

int main() 
{
    /*Kamus*/
    int N, i, j, faktor, jumlah;
    printf("Masukkan nilai N = ");
    scanf("%d",&N);
    faktor = 0;
    jumlah = 0;
    

    if (N <= 0) {
        printf("N harus bilangan positif");
    }
    
    else {
        for (i = 1; i <= N; i++) {
            if (N % i == 0) {
                faktor ++;
                jumlah += i;
            }
        }
        
        if (faktor == 2) {
            printf("Bilangan %d adalah bilangan prima", N);
        }
    
        else if (jumlah - N == N) {
            printf("Bilangan %d adalah bilangan sempurna", N);
        }
    
        else {
            printf("Bilangan %d adalah bilangan biasa", N);
        }
    }
    return 0;
}
