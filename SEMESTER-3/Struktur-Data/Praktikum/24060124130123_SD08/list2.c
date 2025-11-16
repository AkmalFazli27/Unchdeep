/* File : List2.h */
/* Deskripsi : realisasi ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : 24060124130123 / Muhammad Akmal Fazli Riyadi*/
/* Tanggal : 16/11/2025 */

#include "list2.h" 
#include <stdio.h>
#include <stdlib.h>

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
    // kamus lokal
    address P;
    
    // algoritma
    P = (address) malloc(sizeof(Elm));
    if (P != NIL) {
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
    // kamus lokal
    
    // algoritma
    if (P != NIL) {
        next(P) = NIL;
        free(P);  
    }
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L) {
    // kamus lokal
    
    // algoritma
    L->First = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L) {
    // kamus lokal
    
    // algoritma
    return First(L) == NIL;
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L) {
    // kamus lokal
    
    // algoritma
    return (First(L) != NIL) && (next(First(L)) == First(L));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L) {
    // kamus lokal
    address P;

    // algoritma
    P = First(L);
    if (!IsEmptyList(L)) {
        do {
            printf("%c ", info(P));
            P = next(P);
        } while (P != First(L));
    }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
    // kamus lokal 
    address P;
    int count;
    
    // algoritma
    P = First(L);
    count = 0;
    if (IsEmptyList(L)) {
        return count;
    }
    else {
        do {
            P = next(P);
            count++;
        } while (P != First(L));
        return count;
    }
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ) {
    // kamus lokal
    address P, Last;

    // algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P;
        }
        else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(P) = First(*L);
            First(*L) = P;
            next(Last) = First(*L);
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ) {
    // kamus lokal
    address P, Last;

    // algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P;
        }
        else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(Last) = P;
            next(P) = First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
    // kamus lokal
    address P, Last;

    // algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        *V = info(P);
        if (IsOneElm(*L)) {
            First(*L) = NIL;
            Dealokasi(P);
        }
        else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
            Dealokasi(P);
        }
    }
    else {
        *V = '#';
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
    // kamus lokal
    address P, Prev;

    // algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        *V = info(P);
        if (IsOneElm(*L)) {
            First(*L) = NIL;
            Dealokasi(P);
        }
        else {
            while (next(next(P)) != First(*L)) {
                P = next(P);
            }
            Prev = P;
            P = next(P);  
            
            *V = info(P);
            next(Prev) = First(*L);  
            Dealokasi(P);
        }
    }
    else {
        *V = '#';
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
    // kamus lokal
    address P, Prev;

    // algoritma
    if (!IsEmptyList(*L)) {
        if (info(First(*L)) == X) {
            P = First(*L);
            if (IsOneElm(*L)) {
                First(*L) = NIL;
            }
            else {
                Prev = First(*L);
                while (next(Prev) != First(*L)) {
                    Prev = next(Prev);
                }
                First(*L) = next(P);
                next(Prev) = First(*L);
            }
            Dealokasi(P);
        }
        else {
            Prev = First(*L);
            P = next(Prev);
            while (P != First(*L) && info(P) != X) {
                Prev = P;
                P = next(P);
            }
            if (info(P) == X) {
                next(Prev) = next(P);
                Dealokasi(P);
            }
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
    // kamus lokal
    address P;

    // algoritma
    *A = NIL;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) {
                *A = P;
            }
            P = next(P);
        } while (P != First(L) && *A == NIL);
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
    // kamus lokal
    address P;

    // algoritma
    SearchX(*L, X, &P);
    if (P != NIL) {
        info(P) = Y;
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L) {
    address P, Prev, Next, Last;

    if (!IsEmptyList(*L) && !IsOneElm(*L)) {
        Last = First(*L);
        P = First(*L);
        Prev = NIL;
        
        do {
            Next = next(P);
            next(P) = Prev;
            Prev = P;
            P = Next;
        } while (P != First(*L));
        
        // Hubungkan circular: last (yang dulu first) ke Prev (yang jadi first baru)
        next(Last) = Prev;
        First(*L) = Prev;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
    // kamus lokal
    address P;
    int count;

    // algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X) {
    // kamus lokal
    int freq, len;
    
    // algoritma
    freq = CountX(L, X);
    len = NbElm(L);

    if (len == 0) {
        return 0.0;
    }
    return (float)freq / len;
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
    // kamus lokal
    address P;
    int count;

    // algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == 'A' || info(P) == 'a' ||
                info(P) == 'E' || info(P) == 'e' ||
                info(P) == 'I' || info(P) == 'i' ||
                info(P) == 'O' || info(P) == 'o' ||
                info(P) == 'U' || info(P) == 'u') {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L) {
    // kamus lokal
    address P;
    int count;

    // algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if ((info(P) == 'N' || info(P) == 'n') && 
                (info(next(P)) == 'G' || info(next(P)) == 'g')) {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
    // kamus lokal
    address P, NewElm;

    // algoritma
    SearchX(*L, X, &P);
    if (P != NIL) {
        NewElm = Alokasi(V);
        if (NewElm != NIL) {
            next(NewElm) = next(P);
            next(P) = NewElm;
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
    // kamus lokal
    address P, Prev;

    // algoritma
    SearchX(*L, X, &P);
    if (P != NIL) {
        if (P == First(*L)) {
            InsertVFirst(L, V);
        }
        else {
            address NewElm = Alokasi(V);
            if (NewElm != NIL) {
                Prev = First(*L);
                while (next(Prev) != P) {
                    Prev = next(Prev);
                }
                next(NewElm) = P;
                next(Prev) = NewElm;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
    // kamus lokal
    address P, Del;

    // algoritma
    SearchX(*L, X, &P);
    if (P != NIL) {
        Del = next(P);
        *V = info(Del);
        
        if (IsOneElm(*L)) {
            *V = '#';
        }
        else {
            if (Del == First(*L)) {
                infotype temp;
                DeleteVFirst(L, &temp);
                *V = temp;
            }
            else {
                next(P) = next(Del);
                Dealokasi(Del);
            }
        }
    }
    else {
        *V = '#';
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
    // kamus lokal
    address P, Prev, BeforePrev;

    // algoritma
    SearchX(*L, X, &P);
    if (P != NIL) {
        if (IsOneElm(*L)) {
            *V = '#';
        }
        else if (P == First(*L)) {
            DeleteVLast(L, V);
        }
        else {
            Prev = First(*L);
            while (next(Prev) != P) {
                Prev = next(Prev);
            }
            
            *V = info(Prev);
            
            if (Prev == First(*L)) {
                infotype temp;
                DeleteVFirst(L, &temp);
            }
            else {
                BeforePrev = First(*L);
                while (next(BeforePrev) != Prev) {
                    BeforePrev = next(BeforePrev);
                }
                next(BeforePrev) = P;
                Dealokasi(Prev);
            }
        }
    }
    else {
        *V = '#';
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X) {
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

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
    // kamus lokal
    address P;
    int pos;
    boolean found;

    // algoritma
    found = false;
    if (!IsEmptyList(L)) {
        P = First(L);
        pos = 1;
        
        do {
            if (info(P) == X) {
                printf("%d ", pos);
                found = true;
            }
            P = next(P);
            pos++;
        } while (P != First(L));
    }
    
    if (!found) {
        printf("0");
    }
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L) {
    // kamus lokal
    address P;
    int maxCount, currentCount;

    // algoritma
    maxCount = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            currentCount = CountX(L, info(P));
            
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
            
            P = next(P);
        } while (P != First(L));
    }
    return maxCount;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
    // kamus lokal
    address P;
    int maxCount, currentCount;
    char modus;

    // algoritma
    maxCount = 0;
    modus = '\0';
    
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            currentCount = CountX(L, info(P));
            
            if (currentCount > maxCount) {
                maxCount = currentCount;
                modus = info(P);
            }
            
            P = next(P);
        } while (P != First(L));
    }
    return modus;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    // kamus lokal
    address P;

    // algoritma
    CreateList(L);
    
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
    }
    
    if (!IsEmptyList(L2)) {
        P = First(L2);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L2));
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2) {
    // kamus lokal
    address P;
    int count, mid, i;

    // algoritma
    CreateList(L1);
    CreateList(L2);
    
    if (!IsEmptyList(L)) {
        count = NbElm(L);
        mid = (count + 1) / 2;  
        
        P = First(L);
        i = 1;
        
        do {
            if (i <= mid) {
                InsertVLast(L1, info(P));
            }
            else {
                InsertVLast(L2, info(P));
            }
            P = next(P);
            i++;
        } while (P != First(L));
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
    // kamus lokal
    address P;

    // algoritma
    CreateList(L2);
    
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    }
}