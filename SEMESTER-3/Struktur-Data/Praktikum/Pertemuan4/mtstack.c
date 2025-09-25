/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi */
/* Tanggal   : 25 September 2025 */
/***********************************/

#include <stdio.h>
#include "tstack.h"
/* include tstack+boolean */

int main() 
{	/* kamus main */
	Tstack A, B; // variabel A bertipe tStack
	char kata[30] = "KASUR RUSAK";
	char X;
	
	/* algoritma */
	createStack(&A);
	printf("Stack A:\n");
	printStack(&A);
	printf("Apakah stack A kosong? %d\n", isEmptyStack(A));
	
	printf("\nPush character A, B, C ke stack A\n");
	push(&A, 'A');
	push(&A, 'B');
	push(&A, 'C');
	printf("Stack A:\n");
	printStack(&A);
	printf("Apakah stack A penuh? %d\n", isFullStack(A));
	
	printf("\nPop nilai top stack A");
	pop(&A, &X);
	printf("\nStack A:\n");
	printStack(&A);
	printf("Nilai yang di-pop: %c", X);
	
	// ===================================
	createStack(&B);
	printf("\n\nMasukkan nilai sesuai user ke stack B\n");
	pushN(&B, 8);
	printf("Stack B:\n");
	printStack(&B);

	printf("\nApakah kata 'KASUR RUSAK' itu palindrom: %d", isPalindrom(kata));
	
	
	
	return 0;
}
