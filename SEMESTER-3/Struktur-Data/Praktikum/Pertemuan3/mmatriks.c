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
	isiMatriksRandom(&M1, 3, 3);
	// addX(&M1, 5, 2, 2);
	printMatriks(&M1);
	
	printf("\n");
	populateMatriks(&M2, 3, 3);
	printMatriks(&M2);
	
	return 0;
}
