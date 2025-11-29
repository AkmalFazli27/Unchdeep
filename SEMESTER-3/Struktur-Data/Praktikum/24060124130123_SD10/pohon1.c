/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130123 / Muhammad Akmal Fazli Riyadi*/
/* Tanggal : 27 November 2025 */

#include "pohon1.h"

bintree AlokasiTree(infotype E) {
    //kamus lokal
    bintree P;
    //algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}

bintree Tree (infotype akar, bintree left, bintree right) {
    //kamus lokal
    bintree P;
    //algoritma
    P = AlokasiTree(akar);
    if (P != NIL) {
        left(P) = left;
        right(P) = right;
    }
    return P;
}

void PrintPrefix(bintree P) {
    //kamus lokal
    
    //algoritma 
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c(",info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

void DealokasiTree(bintree *P) {
    //kamus lokal
    
    //algoritma
    if (*P != NIL) {
        free(*P);
        *P = NIL;
    }
}

/****** SELEKTOR *****/
/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
    // kamus lokal

    // algoritma
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P) {
    // kamus lokal

    // algoritma
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P) {
    // kamus lokal

    // algoritma
    return P == NIL;
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P) {
    // kamus lokal

    // algoritma
    return (P != NIL) && (left(P) == NIL) && (right(P) == NIL);
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P) {
    // kamus lokal

    // algoritma
    return (P != NIL) && (left(P) != NIL) && (right(P) != NIL);
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P) {
    // kamus lokal

    // algoritma
    return (P != NIL) && (left(P) != NIL) && (right(P) == NIL);
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P) {
    // kamus lokal

    // algoritma
    return (P != NIL) && (left(P) == NIL) && (right(P) != NIL);
}

/*PENELUSURAN*/

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        return 1 + NbElm(left(P)) + NbElm(right(P)); 
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }
    else if (IsDaun(P)) {
        return 1;
    }
    else {
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
    // kamus lokal

    // algoritma
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return -1;
    }
    else if (IsDaun(P)) {
        return 0;
    }
    else {
        return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return false;
    }
    else {
        if (info(P) == X) {
            return true;
        }
        else {
            return SearchX(left(P), X) || SearchX(right(P), X);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            info(*P) = Y;
        }
        UpdateX(&left(*P), X, Y);
        UpdateX(&right(*P), X, Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
    // kamus lokal
    int count;

    // algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        count = 0;
        if (info(P) == X) {
            count = 1;
        }
        return count + CountX(left(P), X) + CountX(right(P), X);
    }
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P) || IsDaun(P)) {
        return true;
    }
    else if (IsUnerLeft(P)) {
        return IsSkewLeft(left(P));
    }
    else {
        return false;
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P) || IsDaun(P)) {
        return true;
    }
    else if (IsUnerRight(P)) {
        return IsSkewRight(right(P));
    }
    else {
        return false;
    }
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(,D),C)*/
void PrintPrefixRingkas(bintree P) {
    //kamus lokal
    
    //algoritma 
    if (!IsEmptyTree(P)) {
        printf("%c", info(P));
        if (!IsDaun(P)) {
            printf("(");
            PrintPrefixRingkas(left(P));
            printf(",");
            PrintPrefixRingkas(right(P));
            printf(")");
        }
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
    // kamus lokal
    int leftLevel, rightLevel;

    // algoritma
    if (info(P) == X) {
        return 1;
    }
    else {
        if (!IsEmptyTree(left(P))) {
            leftLevel = LevelX(left(P), X);
            if (leftLevel != 0) {
                return leftLevel + 1;
            }
        }
        if (!IsEmptyTree(right(P))) {
            rightLevel = LevelX(right(P), X);
            if (rightLevel != 0) {
                return rightLevel + 1;
            }
        }
        return 0;
    }
}

/*function CountLevel(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }
    else if (T == 1) {
        return 1;
    }
    else {
        return CountLevel(left(P), T - 1) + CountLevel(right(P), T - 1);
    }
}

/*procedure PrintLevel( input P:bintree, input N: integer )
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree P, int N) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P)) {
        if (N == 1) {
            printf("%c ", info(P));
        }
        else {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return '#';
    }
    else if (IsDaun(P)) {
        return info(P);
    }
    else {
        if (!IsEmptyTree(left(P))) {
            return GetDaunTerkiri(left(P));
        }
        else {
            return GetDaunTerkiri(right(P));
        }
    }
}

/*function FrekuensiX(P:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree P }*/
float FrekuensiX(bintree P, infotype X) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return 0.0;
    }
    else {
        return (float)CountX(P, X) / (float)NbElm(P);
    }
}

/*function CountVocal(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree P}*/
int CountVocal(bintree P) {
    // kamus lokal
    int count;

    // algoritma
    count = 0;
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        if (info(P) == 'A' || info(P) == 'a' ||
			info(P) == 'E' || info(P) == 'e' ||
			info(P) == 'I' || info(P) == 'i' ||
			info(P) == 'O' || info(P) == 'o' ||
			info(P) == 'U' || info(P) == 'u') {
                count = 1;
            }
        return count + CountVocal(left(P)) + CountVocal(right(P));
    }
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P)) {
        if (info(P) == 'A' || info(P) == 'a' ||
            info(P) == 'E' || info(P) == 'e' ||
            info(P) == 'I' || info(P) == 'i' ||
            info(P) == 'O' || info(P) == 'o' ||
            info(P) == 'U' || info(P) == 'u') {
            printf("%c ", info(P));
        }
        PrintVocal(left(P));
        PrintVocal(right(P));
    }
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree L}*/
int CountConsonant(bintree P) {
    // kamus lokal
    int count;

    // algoritma
    count = 0;
    if (IsEmptyTree(P)) {
        return 0;
    }
    else {
        if (info(P) != 'A' && info(P) != 'a' &&
			info(P) != 'E' && info(P) != 'e' &&
			info(P) != 'I' && info(P) != 'i' &&
			info(P) != 'O' && info(P) != 'o' &&
			info(P) != 'U' && info(P) != 'u') {
                count = 1;
            }
        return count + CountConsonant(left(P)) + CountConsonant(right(P));
    }
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P)) {
        if (info(P) != 'A' && info(P) != 'a' &&
			info(P) != 'E' && info(P) != 'e' &&
			info(P) != 'I' && info(P) != 'i' &&
			info(P) != 'O' && info(P) != 'o' &&
			info(P) != 'U' && info(P) != 'u') {
            printf("%c ", info(P));
        }
        PrintConsonant(left(P));
        PrintConsonant(right(P));
    }
}

/*function Modus(P:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P) {
    // kamus lokal
    char modusLeft, modusRight, modeCurr;
    int countLeft, countRight, countCurr;

    // algoritma
    if (IsEmptyTree(P)) {
        return '\0';
    }
    else if (IsDaun(P)) {
        return info(P);
    }
    else {
        modeCurr = info(P);
        countCurr = CountX(P, modeCurr);
        
        if (!IsEmptyTree(left(P))) {
            modusLeft = Modus(left(P));
            countLeft = CountX(P, modusLeft);
        }
        else {
            countLeft = 0;
        }
        
        if (!IsEmptyTree(right(P))) {
            modusRight = Modus(right(P));
            countRight = CountX(P, modusRight);
        }
        else {
            countRight = 0;
        }
        
        if (countCurr >= countLeft && countCurr >= countRight) {
            return modeCurr;
        }
        else if (countLeft >= countRight) {
            return modusLeft;
        }
        else {
            return modusRight;
        }
    }
}