#include <stdio.h>
#include <string.h>
#include "tstack.h"

int main() {
    Tstack Undo, Redo;
    char perintah;
    int pilihan;

    createStack(&Undo);
    
    do {
        printf("\nMenu:\n");
        printf("1. Input perintah baru\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Tampilkan isi stack\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                // input perintah baru
                scanf(" %c", &perintah);   
                push(&Undo, perintah);        
                createStack(&Redo);  
                break;
            case 2:
                // undo
                pop(&Undo, &perintah);
                push(&Redo, perintah);
                break;
            case 3:
                // redo
                pop(&Redo, &perintah);
                push(&Undo, perintah);
                break;
            case 4:
                // tampilkan isi undo dan redo
                printStack(Undo);
                printStack(Redo);
                break;
            case 0:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}
