#include <stdio.h>

void luaspersegi(int sisi, int *luas) {
    *luas = sisi * sisi;
}

int main () {
    int sisi, luas;
    sisi = 3;
    luaspersegi(sisi, &luas);
    printf("%d",luas);
}