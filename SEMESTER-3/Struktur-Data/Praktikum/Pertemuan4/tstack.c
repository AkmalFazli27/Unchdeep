/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi */
/* Tanggal   : 25 September 2025 */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
#ifndef TSTACK_H
#define TSTACK_H
/* include tstack+boolean */

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T) {
    int i;
    for (i = 1; i <= 10; i++) {
        T->wadah[i] = '#';
    }
    T->top = 0; 
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T) {
    return top(T) == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T) {
    return top(T) == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E) {
    if (!isFullStack(*T)) {
		T->top++;
		T->wadah[top(*T)] = E;
	}
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X) {
    if (!isEmptyStack(*T)) {
		*X = infotop(*T);
		T->wadah[top(*T)] = '#';
		T->top--;
	}
	else {
		*X = '#';
	}
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack *T) {
    int i;
	printf("[ ");
    for (i = 1; i <= 10; i++) {
        printf("%c", T->wadah[i]);
        if (i < 10) {
            printf(" | ");
        }
    }
    printf(" ]\n");
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack *T) {
    int i;
	printf("[ ");
    for (i = 1; i <= top(*T); i++) {
        if (T->wadah[i] != '#') {
            printf("%c", T->wadah[i]);
            if (i < top(*T)) {
                printf(" | ");
            }
        }
    }
    printf(" ]\n");
}

/* boolean isPalindrom(kata:String) 
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(char kata[30]) {
    Tstack simpan;
    int awal, length;
    char A;
    createStack(&simpan);
    
    length = strlen(kata);

    for (int i = 0; i < length / 2; i++) {
        push(&simpan, kata[i]);
    }

    if (length % 2 == 0) {
        awal = length / 2;
    } 
    else {
        awal = (length / 2) + 1;
    }

    while (awal < length) {
        pop(&simpan, &A);
        if (A != kata[awal]) {
            return false;
        }
        awal++;
    }
    return true;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N) {
    if (!isFullStack(*T)) {
        if (N > 0 && N <= (10 - top(*T))) {
            for (int i = 0; i < N; i++) {
                char x;
                printf("Masukkan elemen ke-%d: ", top(*T) + 1);
                scanf(" %c", &x);
                T->top++;
                T->wadah[T->top] = x;
            }
        }
    }
}

#endif