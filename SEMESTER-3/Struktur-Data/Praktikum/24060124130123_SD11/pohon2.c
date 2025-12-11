/* File : pohon2.h */
/* Deskripsi : realisasi ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124130123 / Muhammad Akmal Fazli Riyadi */
/* Tanggal : 4 Desember 2025 */

#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ) {
    // kamus lokal
    int i;

    // algoritma 
    if (!IsEmptyTree(P)) {
        for (i = 1; i <= H; i++) {
            printf("  ");
        }
        // Tampilkan sebagai karakter jika nilai dalam range ASCII printable (32-126)
        if (info(P) >= 32 && info(P) <= 126) {
            printf("%c\n", (char)info(P));
        } else {
            printf("%d\n", info(P));
        }
        PrintTreeInden(left(P), H + 1);
        PrintTreeInden(right(P), H + 1);
    }
}

/* procedure PrintLevel2(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel2(bintree P, int N) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P)) {
        if (N == 1) {
            printf("%c ", info(P));
        }
        else {
            PrintLevel2(left(P), N - 1);
            PrintLevel2(right(P), N - 1);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            info(*P) = Y;
        }
        UpdateAllX(&left(*P), X, Y);
        UpdateAllX(&right(*P), X, Y);
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(*P)) {
        *P = Tree(X, NIL, NIL);
    }
    else if (IsDaun(*P) || IsUnerRight(*P)) {
        left(*P) = Tree(X, NIL, NIL);
    }
    else {
        AddDaunTerkiri(&left(*P), X);
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            if (Kiri) {
                left(*P) = Tree(Y, NIL, NIL);
            } 
            else {
                right(*P) = Tree(Y, NIL, NIL);
            }
        }
        else {
            AddDaun(&left(*P), X, Y, Kiri);
            AddDaun(&right(*P), X, Y, Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(*P)) {
        *P = Tree(X, NIL, NIL);
    }
    else {
        if (X < info(*P)) {
            InsertX(&left(*P), X);
        }
        else {
            InsertX(&right(*P), X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X) {
    // kamus lokal
    bintree temp;

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (IsEmptyTree(left(*P))) {
            *X = info(*P);
            temp = *P;
            *P = right(*P);
            DealokasiTree(&temp);
        }
        else {
            DelDaunTerkiri(&left(*P), X);
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P) && info(*P) == X) {
            DealokasiTree(P);
        }
        else {
            DelDaun(&left(*P), X);
            DelDaun(&right(*P), X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X) {
    // kamus lokal
    bintree temp, pred;

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            if (IsDaun(*P)) {
                DealokasiTree(P);
            }
            else if (IsUnerLeft(*P)) {
                temp = *P;
                *P = left(*P);
                DealokasiTree(&temp);
            }
            else if (IsUnerRight(*P)) {
                temp = *P;
                *P = right(*P);
                DealokasiTree(&temp);
            }
            else {
                pred = left(*P);
                while (!IsEmptyTree(right(pred))) {
                    pred = right(pred);
                }
                info(*P) = info(pred);
                DeleteX(&left(*P), info(pred));
            }
        }
        else {
            DeleteX(&left(*P), X);
            DeleteX(&right(*P), X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
    // kamus lokal
    bintree P, leftSubtree, rightSubtree;
    infotype X;
    int nLeft;
    char ch;

    // algoritma
    if (n == 0) {
        return NIL;
    }
    else {
        nLeft = n / 2;
        leftSubtree = BuildBalanceTree(nLeft);
        
        printf("Masukkan karakter untuk node: ");
        scanf(" %c", &ch);
        X = (int)ch; // Convert char to int untuk infotype
        
        rightSubtree = BuildBalanceTree(n - nLeft - 1);
        P = Tree(X, leftSubtree, rightSubtree);
        return P;
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
    // kamus lokal

    // algoritma
    return abs(NbElm(left(P)) - NbElm(right(P))) <= 1;
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }
    else if (IsDaun(P)) {
        return info(P);
    }
    else {
        return max2(info(P), max2(maxTree(left(P)), maxTree(right(P))));
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P) {
    // kamus lokal
    int min2(int a, int b) {
        return (a < b) ? a : b;
    }

    // algoritma
    if (IsEmptyTree(P)) {
        return 127;
    }
    else if (IsDaun(P)) {
        return info(P);
    }
    else {
        return min2(info(P), min2(minTree(left(P)), minTree(right(P))));
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return false;
    }
    else if (info(P) == X) {
        return true;
    }
    else if (X < info(P)) {
        return BSearch(left(P), X);
    }
    else {
        return BSearch(right(P), X);
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {
        return Tree(X, NIL, NIL);
    }
    else {
        if (X < info(P)) {
            left(P) = InsSearch(left(P), X);
        }
        else {
            right(P) = InsSearch(right(P), X);
        }
        return P;
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X) {
    // kamus lokal
    bintree temp, pred;

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (X < info(*P)) {
            DelBtree(&left(*P), X);
        }
        else if (X > info(*P)) {
            DelBtree(&right(*P), X);
        }
        else {
            if (IsDaun(*P)) {
                DealokasiTree(P);
            }
            else if (IsUnerLeft(*P)) {
                temp = *P;
                *P = left(*P);
                DealokasiTree(&temp);
            }
            else if (IsUnerRight(*P)) {
                temp = *P;
                *P = right(*P);
                DealokasiTree(&temp);
            }
            else {
                pred = left(*P);
                while (!IsEmptyTree(right(pred))) {
                    pred = right(pred);
                }
                info(*P) = info(pred);
                DelBtree(&left(*P), info(pred));
            }
        }
    }
}