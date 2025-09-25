#include <stdio.h>
#include "tstack.h"

void addCommand (Tstack *Backward, Tstack *Forward, char UML){
    push(Backward, UML);
    createStack(Forward);
}

void backwardCommand (Tstack *Backward, Tstack *Forward, char *UML){
    pop(Backward, UML);
    push(Forward, *UML);
}

void forwardCommand (Tstack *Backward, Tstack *Forward, char *UML){
    pop(Forward, UML);
    push(Backward, *UML);
} 

int main() {
    Tstack Backward, Forward ;
    int pilihan;
    char UML;

    createStack(&Backward);

    do {
        printf("\nMenu:\n");
        printf("1. Input UML baru\n");
        printf("2. Backward\n");
        printf("3. Forward\n");
        printf("4. Tampilkan isi stack\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
                printf("Masukkan UML: ");
                scanf(" %c", &UML);  
                addCommand(&Backward, &Forward, UML);
            } 
        else if (pilihan == 2) {
            if (isEmptyStack(Backward)) {
                printf("Tidak ada yang bisa di-backward\n");
            } 
            else {
                backwardCommand(&Backward, &Forward, &UML);  
            }
        } 
        else if (pilihan == 3) {
            if (isEmptyStack(Forward)) {
                printf("Tidak ada yang bisa di-forward\n");
            } 
            else {
                forwardCommand(&Backward, &Forward, &UML);
            }
        } 
        else if (pilihan == 4) {
            viewStack(&Backward);
            viewStack(&Forward);
        } 
        else if (pilihan == 0) {
            printf("Program selesai.\n");
        } 
        else {
            printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 0);

    return 0;
}
