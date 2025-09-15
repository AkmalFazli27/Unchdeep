int main() {
    /*Kamus*/
    int n, i, j, jumlah;

    printf("Masukkan nilai n = ");
    scanf("%d", &n);

    /*Algoritma*/
    for (i = 1; i <= n; i++) { 
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
    return 0;
}