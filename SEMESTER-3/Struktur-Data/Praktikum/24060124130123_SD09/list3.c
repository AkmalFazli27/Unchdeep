/* File : list3.c */
/* Deskripsi : realisasi ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130123 / Muhammad Akmal Fazli Riyadi */
/* Tanggal : 20/11/2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) //representasi fisik fungsi
{	//kamus lokal
	address P;
	//algoritma
	P = (address)malloc(sizeof(Elm));
	if (P != NIL) {
		info(P) = E;
		next(P) = NIL;
		prev(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
	free(*P);
    *P = NIL;
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L) {
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L) {
	return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L) {
	// kamus lokal 
	address P;
	// algoritma
	P = First(L);
	if (P != NIL) {
		do {
			printf("%c ", info(P));
			P = next(P);
		} while( P != NIL );
	}
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L) {
	// kamus lokal 
	address P;
	int count;
	
	// algoritma
	P = First(L);
	count = 0;
	if (P != NIL) {
		while (P != NIL) {
			count ++;
			P = next(P);
		}
	}
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ) {
	// kamus lokal
	address P;

	// algoritma
	P = Alokasi(V);
	if (!IsEmptyList(*L)) {
		next(P) = First(*L);
		prev(First(*L)) = P;
		prev(P) = NIL;  // P is the new first node
		First(*L) = P;
	}
	else {
		First(*L) = P;
		prev(P) = NIL;
		next(P) = NIL;
	}
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ) {
	// kamus lokal
	address P, Last;

	// algoritma
	P = Alokasi(V);
	if (!IsEmptyList(*L)) {
		Last = First(*L);
		while (next(Last) != NIL) {
			Last = next(Last);
		}
		next(Last) = P;
		prev(P) = Last;
		next(P) = NIL;
	}
	else {
		First(*L) = P;
		prev(P) = NIL;
		next(P) = NIL;
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V) {
	// kamus lokal
	address P;

	// algoritma
	*V = '#';
	if (!IsEmptyList(*L)) {
		P = First(*L);
		*V = info(P);
		First(*L) = next(P);
		if (First(*L) != NIL) {
			prev(First(*L)) = NIL;
		}
		Dealokasi(&P);
	}
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V) {
	// kamus lokal
	address Last;

	// algoritma
	*V = '#';
	if (!IsEmptyList(*L)) {
		Last = First(*L);
		while (next(Last) != NIL) {
			Last = next(Last);
		}
		*V = info(Last);
		
		if (Last == First(*L)) {
			First(*L) = NIL;
		}
		else {
			next(prev(Last)) = NIL;
		}
		Dealokasi(&Last);
	}
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
	// kamus lokal
	address P;

	// algoritma
	if (!IsEmptyList(*L)) {
		P = First(*L);
		while (P != NIL && info(P) != X) {
			P = next(P);
		}
		
		if (P != NIL) {
			if (P == First(*L)) {
				First(*L) = next(P);
				if (First(*L) != NIL) {
					prev(First(*L)) = NIL;
				}
			}
			else {
				next(prev(P)) = next(P);
				if (next(P) != NIL) {
					prev(next(P)) = prev(P);
				}
			}
			Dealokasi(&P);
		}
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A) {
	// kamus lokal
	address P;

	// algoritma
	P = First(L);
	*A = NIL;
	while (P != NIL && *A == NIL) {
		if (info(P) == X) {
			*A = P;
		}
		P = next(P);
	}
}