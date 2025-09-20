/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h" 
/* include tstack+boolean */

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	
	/* algoritma */
	createStack(&A);
	pushN(&A, 5);
	printStack(A);

	
	
	
	return 0;
}
