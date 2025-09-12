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
	
	/* ============================================== */
	printf("\n\n=========TABLE 2=========\n");
	createTable(&T2);
	printf("Table 2: ");
	printTable(T2);
	printf("Size T2: %d", getSize(T2));
	
	printf("\n\nMenambahkan nilai 'A', 'B', 'B', 'E', 'O'");
	addXTable(&T2,'A');
	addXTable(&T2,'B');
	addXTable(&T2,'B');
	addXTable(&T2,'E');
	addXTable(&T2,'O');
	printf("\nTable 2: ");
	printTable(T2);
	printf("Size T2: %d", getSize(T2));
	printf("\nBanyak nilai 'B': %d", countX(T2, 'B'));
	
	printf("\n\nMenghapus nilai semua 'B' yang ada");
	delAllXTable(&T2, 'B');
	printf("\nTable 2: ");
	printTable(T2);
	printf("Size T2: %d", getSize(T2));

	printf("\n\nMelihat tabel yang terisi");
	printf("\nTabel 2: ");
	viewTable(T2);

	printf("\nMengisi elemen tabel sebanyak 5 kali sesuai input user\n");
	populateTable(&T2, 5);
	printf("\nSetelah diinput sesuai user:");
	printf("\nTable 2: ");
	printTable(T2);
	printf("Modus dari T2: %c", Modus(T2));

	printf("\n\nHapus elemen '4'");
	delTable(&T2, 5);
	printf("\nTable 2: ");
	printTable(T2);

	printf("\n====================");
	printf("\nApakah T1 dan T2 sama? %d", isEqualTable(T1, T2));
	return 0;
}
