/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"
int main() {
	/*kamus*/
	Matriks M1;
	Matriks M2;
	srand(time(NULL));
	
	/*algoritma*/
	initMatriks(&M1);
	initMatriks(&M2);
	printf("Apakah matriks full? %d\n", isFullMatriks(M1));
	addX(&M1, 5, 3, 3);
	addX(&M1, 7, 2, 3);
	printMatriks(&M1);
	printf("\nBaris matriks: %d", getNBaris(M1));
	printf("\nKolom matriks: %d\n", getNKolom(M1));
	
	printf("\n");
	// populateMatriks(&M2, 3, 3);
	isiMatriksIdentitas(&M2, 3);
	printMatriks(&M2);
	printf("\nBaris matriks: %d", getNBaris(M2));
	printf("\nKolom matriks: %d\n", getNKolom(M2));
	
	return 0;
}
