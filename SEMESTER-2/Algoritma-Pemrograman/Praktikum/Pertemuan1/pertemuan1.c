#include <stdio.h>

// int main() {
//     printf("Hello World!\n");
//     return 0;    
// }

int main() {
    int panjang, lebar, hasil;
    printf("Masukkan Panjang : ");
    scanf("%d", &panjang);
    printf("Masukkan Lebar : ");
    scanf("%d", &lebar);
    hasil = panjang * lebar;
    printf("Jadi hasil luasnya adalah %d", hasil);
}