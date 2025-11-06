/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : Muhammad Akmal Fazli Riyadi / 24060124130123*/
/* Tanggal : November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********* manajemen memori ********/

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address P) {
	//kamus lokal
	
	//algoritma
	if ( P != NIL ) {
		next(P) = NIL;
	}
	P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/

/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L) {
	/* membuat list kosong dengan meng-set First ke NIL */
	L->First = NIL;
}

/****************** TEST LIST KOSONG ******************/

/* function IsEmptyList(L:List1) --> boolean 
/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L) {
	return First(L) == NIL;
}

/*********** OPERATORS ***********/

/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List1 L) {
	//kamus lokal 
	address P;
	//algoritma
	P = First(L);
	if (P != NIL) {
		printf("\nElemen = ");
		do {
			printf("\t%c", info(P));
			P = next(P);
		} while( P != NIL );
	}
}

/**************** PENELUSURAN ****************/

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L) {
	//kamus lokal 
	address P;
	int count;
	
	//algoritma
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

/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ) {
	// kamus lokal
	address P;

	// algoritma
	P = Alokasi(V);
	if (P != NIL) {
		next(P) = First(*L);
		First(*L) = P;
	}
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ) {
	address P, Last;

	P = Alokasi(V);
	if (P != NIL) {
		if (IsEmptyList(*L)) {
			First(*L) = P;
		}
		else {
			Last = Fist(*L);
			while (next(Last) != NIL) {
				Last = next(Last);
			}
			next(Last) = P;
		}
	}

}
/*
//kamus
List1 Senarai;
//algoritma

PrintList(Senarai);
*/