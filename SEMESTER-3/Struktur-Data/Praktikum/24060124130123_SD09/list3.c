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

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y) {
	// kamus lokal
    address P;

    // algoritma
    SearchX(*L, X, &P);
    if (P != NIL) {
        info(P) = Y;
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L) {
	address P, Temp;

    if (!IsEmptyList(*L)) {
        P = First(*L);
        
        while (P != NIL) {
            Temp = next(P);
            next(P) = prev(P);
            prev(P) = Temp;
            
            if (prev(P) != NIL) {
                P = prev(P);
            } 
			else {
                First(*L) = P;
                break;
            }
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V) {
    // kamus lokal
    address P, NewElm;

    // algoritma
    SearchX(*L, X, &P);
    if (P != NIL) {
        NewElm = Alokasi(V);
        if (NewElm != NIL) {
            next(NewElm) = next(P);
            prev(NewElm) = P;
            next(P) = NewElm;
            
            if (next(NewElm) != NIL) {
                prev(next(NewElm)) = NewElm;
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V) {
	// kamus lokal
    address P, NewElm;

    // algoritma
    SearchX(*L, X, &P);
    if (P != NIL) {
        if (P == First(*L)) {
            InsertVFirst(L, V);
        }
        else {
            NewElm = Alokasi(V);
            if (NewElm != NIL) {
                next(NewElm) = P;
                prev(NewElm) = prev(P);
                next(prev(P)) = NewElm;
                prev(P) = NewElm;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
	// kamus lokal
    address P, Del;

    // algoritma
    *V = '#';
    SearchX(*L, X, &P);
    if (P != NIL && next(P) != NIL) {
        Del = next(P);
        *V = info(Del);
        next(P) = next(Del);
        
        if (next(Del) != NIL) {
            prev(next(Del)) = P;
        }
        
        Dealokasi(&Del);
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V) {
	// kamus lokal
    address P, Del;

    // algoritma
    *V = '#';
    SearchX(*L, X, &P);
    if (P != NIL && prev(P) != NIL) {
        Del = prev(P);
        *V = info(Del);
        
        if (Del == First(*L)) {
            First(*L) = P;
            prev(P) = NIL;
        }
        else {
            prev(P) = prev(Del);
            next(prev(Del)) = P;
        }
        
        Dealokasi(&Del);
    }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X) {
	// kamus lokal
    address P;
    int count;

    // algoritma
    count = 0;
    P = First(L);
    while (P != NIL) {
        if (info(P) == X) {
            count++;
        }
        P = next(P);
    }
    return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X) {
	// kamus lokal
	int freq, total;

	// algoritma
	freq = CountX(L, X);
	total = NbElm(L);
	if (total == 0) {      
        return 0.0;
    }
    
    return (float)freq / total;
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L) {
	// kamus lokal
    address P;
    int maxCount, currentCount;

    // algoritma
    maxCount = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
		while (P != NIL) {
			currentCount = CountX(L, info(P));
			
			if (currentCount > maxCount) {
				maxCount = currentCount;
			}
			
			P = next(P);
		}
    }
    return maxCount;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L) {
	// kamus lokal
	address P;
	infotype modus, curr;
	int maxCount, currCount;

	// algoritma
	if (IsEmptyList(L)) {
		return '#';
	}

	P = First(L);
	modus = info(P);
	maxCount = 0;

	while (P != NIL) {
		curr = info(P);
		currCount = CountX(L, curr);

		if (currCount > maxCount) {
			maxCount = currCount;
			modus = curr;
		}
		P = next(P);
	}
	return modus;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L) {
	// kamus lokal 
	address P;
	int count;
	
	// algoritma
	P = First(L);
	count = 0;
	while (P != NIL) {
		if (info(P) == 'A' || info(P) == 'a' ||
			info(P) == 'E' || info(P) == 'e' ||
			info(P) == 'I' || info(P) == 'i' ||
			info(P) == 'O' || info(P) == 'o' ||
			info(P) == 'U' || info(P) == 'u') {
			count++;
		}
		P = next(P);
	}
	return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L) {
	// kamus lokal
    address P;
    int count;

    // algoritma
    count = 0;
    P = First(L);
    while (P != NIL && next(P) != NIL) {
        if ((info(P) == 'N' || info(P) == 'n') && 
            (info(next(P)) == 'G' || info(next(P)) == 'g')) {
            count++;
        }
        P = next(P);
    }
    return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X) {
	// kamus lokal
	address P;
	int pos;
	boolean found;

	// algoritma
	P = First(L);
	pos = 1;
	found = false;
	while (P != NIL) {
		if (info(P) == X) {
			printf("%d ", pos);
			found = true;
		}
		pos++;
		P = next(P);
	}
	
	if (!found) {
		printf("0");
	}
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X) {
	// kamus lokal
    int count;

    // algoritma
    if (!IsEmptyList(*L)) {
        count = CountX(*L, X);
        
        while (count > 0) {
            DeleteX(L, X);
            count--;
        }
    }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L) {
	// kamus lokal
	address Last;
	
	// algoritma
	CreateList(L);

	if (IsEmptyList(L1)) {
		First(*L) = First(L2);
	}
	else if (IsEmptyList(L2)) {
		First(*L) = First(L1);
	}
	else {
		First(*L) = First(L1);
		Last = First(L1);
		while (next(Last) != NIL) {
			Last = next(Last);
		}
		next(Last) = First(L2);
		prev(First(L2)) = Last;
	}
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2) {
	// kamus lokal
    address P;
    int count, i, Mid;
    
    // algoritma
    CreateList(L1);
    CreateList(L2);
    
    if (IsEmptyList(L)) {
        return;
    }
    
    count = NbElm(L);
    Mid = (count + 1) / 2;
    
    P = First(L);
    for (i = 1; i <= Mid && P != NIL; i++) {
        InsertVLast(L1, info(P));
        P = next(P);
    }
    
    while (P != NIL) {
        InsertVLast(L2, info(P));
        P = next(P);
    }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2) {
	// kamus lokal
	address P;

	// algoritma
	CreateList(L2);
	P = First(L1);
	while (P != NIL) {
		InsertVLast(L2, info(P)); 
        P = next(P);
	}
}