#include <stdio.h>
#include "tabel.h"
/* Deskripsi : driver ADT tabel integer*/
/* NIM/Nama : 24060124130123/Muhammad Akmal Fazli Riyadi */
/* Tanggal : 9/11/2025 */

int main() {
	/*kamus*/
	Tabel T1;
	Tabel T2;
	
	/*algoritma*/
	printf("=========TABLE 1=========\n");
	createTable(&T1);
	printf("Table 1: ");
	printTable(T1);
	printf("Size T1: %d", getSize(T1));
	printf("\nApakah T1 kosong? %d", isEmptyTable(T1));
	
	printf("\n\nMenambahkan nilai 'A', 'B', 'C', 'C', 'C', 'D', 'E', 'F', 'G', 'H'");
	addXTable(&T1,'A');
	addXTable(&T1,'B');
	addXTable(&T1,'C');
	addXTable(&T1,'C');
	addXTable(&T1,'C');
	addXTable(&T1,'D');
	addXTable(&T1,'E');
	addXTable(&T1,'F');
	addXTable(&T1,'G');
	addXTable(&T1,'H');
	printf("\nTable 1: ");
	printTable(T1);
	printf("Size T1: %d", getSize(T1));
	printf("\nBanyak huruf vocal: %d", countVocal(T1));
	printf("\nApakah T1 penuh? %d", isFullTable(T1));
	
	printf("\n\nMenghapus nilai 'A'");
	addUniqueXTable(&T1, 'A');
	delXTable(&T1, 'A');
	printf("\nTable 1: ");
	printTable(T1);
	printf("Size T1: %d", getSize(T1));
	printf("\nApakah T1 kosong? %d", isEmptyTable(T1));
	
	
	printf("\n\n=========TABLE 2=========\n");
	createTable(&T2);
	printf("\n%d\n", getSize(T2));
	
	printf("\n%d", countX(T1, 0));
	printf("\n%d", getSize(T1));
	printf("\n%d", getSize(T1));
	return 0;
}
