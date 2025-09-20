/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"
void header (char *title) {
	printf("================= %s =================\n", title);
}

int main() {
	/*kamus*/
	Matriks M1, M2, M3;
	srand(time(NULL));
	
	/*algoritma*/
	/* ================= 1. KONSTRUKTOR & SELEKTOR ================= */
	header("1. KONSTRUKTOR & SELEKTOR");
	initMatriks(&M1);
	printf("Menginisiasi matriks M1 berisi kosong: \n");
	printMatriks(&M1);
	printf("Panjang baris M1: %d", getNBaris(M1));
	printf("\nPanjang kolom M1: %d", getNKolom(M1));
	
	/* ================= 2. PREDIKAT ================= */
	printf("\n\n");
	header("2. PREDIKAT");
	printf("Apakah matriks M1 kosong? %d", isEmptyMatriks(M1));
	printf("\nApakah matriks M1 penuh? %d", isFullMatriks(M1));
	
	/* ================= 3. MUTATOR ================= */
	printf("\n\n");
	header("3. MUTATOR");
	printf("Menambahkan nilai 1 pada [1,1], nilai 2 pada [2,2], dan nilai 3 pada [3,3]\n");
	addX(&M1, 1, 1, 1); 
	addX(&M1, 2, 2, 2); 
	addX(&M1, 3, 3, 3); 
	viewMatriks(&M1);
	printf("Panjang baris M1 setelah ditambah nilai: %d", getNBaris(M1));
	printf("\nPanjang kolom M1 setelah ditambah nilai: %d", getNKolom(M1));

	// printf("\nHapus nilai 2 pada matriks M1\n");
	// delX(&M1, 2);
	// viewMatriks(&M1);
	// printf("Panjang baris M1 setelah menghapus nilai 2: %d", getNBaris(M1));
	// printf("\nPanjang kolom M1 setelah menghapus nilai 2: %d", getNKolom(M1));

	printf("\n\nMengubah matriks M2 menjadi identitas 3x3\n");
	isiMatriksIdentitas(&M2, 3);
	viewMatriks(&M2);
	printf("Panjang baris M2: %d", getNBaris(M2));
	printf("\nPanjang kolom M2: %d", getNKolom(M2));
	
	printf("\n\nMengisi nilai random pada matriks M2 dengan 3x3\n");
	initMatriks(&M2);
	isiMatriksRandom(&M2, 3, 3);
	viewMatriks(&M2);
	printf("Panjang baris M2: %d", getNBaris(M2));
	printf("\nPanjang kolom M2: %d", getNKolom(M2));
	
	printf("\n\nMengisi matriks M3 sesuai input user\n");
	initMatriks(&M3);
	populateMatriks(&M3, 3, 3);
	printf("Matriks M3:\n");
	viewMatriks(&M3);

	/* ================= 4. OPERASI ARITMATIKA ================= */
	printf("\n");
	header("4. OPERASI ARITMATIKA");
	printf("Menjumlahkan matriks M2 dan M3 menjadi matriks A\n");
	Matriks A = addMatriks(M2, M3);
	viewMatriks(&A);

	printf("\nMengurangkan matriks M2 dan M3 menjadi matriks B\n");
	Matriks B = subMatriks(M2, M3);
	viewMatriks(&B);

	printf("\nMengalikan matriks M2 dan M3 menjadi matriks C\n");
	Matriks C = kaliMatriks(M2, M3);
	viewMatriks(&C);


	return 0;
}
