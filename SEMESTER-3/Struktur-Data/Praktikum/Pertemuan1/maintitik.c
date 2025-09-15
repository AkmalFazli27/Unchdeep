/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : Muhammad Akmal Fazli Riyadi/24060124130123 */
/* Tanggal   : 4 September 2025*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
	//kamus main
	Titik T1;
	Titik T2;
	
	//algoritma
	printf("Halo, ini driver modul Titik \n");
	makeTitik(&T1,4,5);
	makeTitik(&T2,-2,0);
	
	printf("=========");
	// T1 = (4,5)
	// T2 = (-2,0)
	printf("\nTitik T1 = (%d,%d)",getAbsis(T1),getOrdinat(T1));
	printf("\nTitik T2 = (%d,%d)",getAbsis(T2),getOrdinat(T2));
	
	printf("\n=========");
	setOrdinat(&T1,3);
	setAbsis(&T2,-7);
	printf("\nUbah ordinat T1 menjadi 3: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	printf("\nUbah absis T2 menjadi -7: (%d,%d)", getAbsis(T2), getOrdinat(T2));
	
	printf("\n=========");
	printf("\nApakah T2 adalah origin? %d",isOrigin(T2));
	printf("\nApakah T1 berada di sumbu-x? %d",isOnSumbuX(T1));
	printf("\nApakah T1 berada di sumbu-y? %d",isOnSumbuY(T2));
	printf("\nApakah T1 dan T2 equal? %d",isEqual(T1,T2));
	
	printf("\n=========");
	geser(&T1,3,-2);
	geser(&T2,2,7);
	printf("\nNilai T1 setelah digeser sumbu-x 3 dan sumbu-y -2: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	printf("\nNilai T2 setelah digeser sumbu-x 3 dan sumbu-y -2: (%d,%d)", getAbsis(T2), getOrdinat(T2));
	refleksiX(&T1);
	printf("\nNilai T1 setelah direfleksikan dengan sumbu-x: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	refleksiY(&T2);
	printf("\nNilai T2 setelah direfleksikan dengan sumbu-y: (%d,%d)", getAbsis(T2), getOrdinat(T2));
	dilatasi(&T2, 2.0);
	printf("\nNilai T2 setelah didilatasi dengan nilai k = 2: (%d,%d)", getAbsis(T2), getOrdinat(T2));
	dilatasiX(&T1,T2, 0.5);
	printf("\nNilai T1 setelah didilatasi dengan titik T2 dengan nilai k = 0.5: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	
	printf("\n=========");
	printf("\nTitik T1 = (%d,%d)",getAbsis(T1),getOrdinat(T1));
	printf("\nTitik T2 = (%d,%d)",getAbsis(T2),getOrdinat(T2));
	printf("\nKuadran dari T1: %d",kuadran(T1));
	printf("\nKuadran dari T2: %d",kuadran(T2));
	
	return 0;
}
