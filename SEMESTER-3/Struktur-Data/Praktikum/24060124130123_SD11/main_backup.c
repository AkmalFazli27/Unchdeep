/* File : main.c */
/* Deskripsi : aplikasi ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124130123 / Muhammad Akmal Fazli Riyadi*/
/* Tanggal : 4 Desember 2025 */

#include "pohon2.h"

int main() {
    // kamus
    bintree B, B2, B3, BST;
    infotype deletedValue;
     
    // algoritma
    B = Tree(84,
               Tree(73,
                    Tree(78,NIL,NIL),
                    Tree(70,
                         Tree(79,NIL,NIL),
                         NIL)),
               Tree(82,
                    Tree(77,
                         Tree(65,NIL,NIL),
                         Tree(84,NIL,NIL)),
                    Tree(73,
                         NIL,
                         Tree(75,
                              NIL,
                              Tree(65,NIL,NIL))))
               );

    printf("========== PENELUSURAN ==========\n");
    printf("Pohon B: \n");
    PrintTreeInden(B, 0);
    
    printf("\nLevel 2 pada Pohon B: ");
    PrintLevel2(B, 2);
    printf("\n");

    printf("\n========== MANIPULASI ELEMEN ==========\n");
    printf("Update 65 (A) menjadi 88 (X)\n");
    UpdateAllX(&B, 65, 88);
    printf("Pohon B setelah update: \n");
    PrintTreeInden(B, 0);

    printf("\n========== PENAMBAHAN ELEMEN ==========\n");
    printf("AddDaunTerkiri 90 (Z)\n");
    AddDaunTerkiri(&B, 90);
    printf("Pohon B setelah AddDaunTerkiri: \n");
    PrintTreeInden(B, 0);

    printf("\nAddDaun: Tambah 87 (W) sebagai anak kiri 90 (Z)\n");
    AddDaun(&B, 90, 87, true);
    printf("Pohon B setelah AddDaun: \n");
    PrintTreeInden(B, 0);

    printf("\nInsertX 81 (Q) (BST insert)\n");
    B2 = Tree(77,
              Tree(68,NIL,NIL),
              Tree(83,NIL,NIL));
    printf("Pohon B2 sebelum InsertX: \n");
    PrintTreeInden(B2, 0);
    InsertX(&B2, 81);
    printf("Pohon B2 setelah InsertX 'Q': \n");
    PrintTreeInden(B2, 0);

    printf("\n========== PENGHAPUSAN ELEMEN ==========\n");
    printf("DelDaunTerkiri\n");
    DelDaunTerkiri(&B, &deletedValue);
    printf("Nilai yang dihapus: %d\n", deletedValue);
    printf("Pohon B setelah DelDaunTerkiri: \n");
    PrintTreeInden(B, 0);

    printf("\nDelDaun 75 (K)\n");
    DelDaun(&B, 75);
    printf("Pohon B setelah DelDaun 'K': \n");
    PrintTreeInden(B, 0);

    printf("\nDeleteX 73 (I) (hapus node dengan 2 anak)\n");
    DeleteX(&B, 73);
    printf("Pohon B setelah DeleteX 'I': \n");
    PrintTreeInden(B, 0);

    printf("\n========== SOAL TAMBAHAN ==========\n");
    printf("BuildBalanceTree dengan 5 node\n");
    printf("Masukkan 5 karakter: ");
    B3 = BuildBalanceTree(5);
    printf("Pohon B3 (balanced): \n");
    PrintTreeInden(B3, 0);

    printf("\nIsBalanceTree B3: %d\n", IsBalanceTree(B3));
    printf("IsBalanceTree B: %d\n", IsBalanceTree(B));

    printf("\nmaxTree B: %d\n", maxTree(B));
    printf("minTree B: %d\n", minTree(B));

    printf("\n========== BINARY SEARCH TREE ==========\n");
    BST = NIL;
    printf("InsSearch: Membuat BST dengan nilai 5, 3, 7, 2, 4, 6, 8\n");
    BST = InsSearch(BST, 5);
    BST = InsSearch(BST, 3);
    BST = InsSearch(BST, 7);
    BST = InsSearch(BST, 2);
    BST = InsSearch(BST, 4);
    BST = InsSearch(BST, 6);
    BST = InsSearch(BST, 8);
    printf("BST: \n");
    PrintTreeInden(BST, 0);

    printf("\nBSearch 4 pada BST: %d\n", BSearch(BST, 4));
    printf("BSearch 9 pada BST: %d\n", BSearch(BST, 9));

    printf("\nDelBtree 3 (node dengan 2 anak)\n");
    DelBtree(&BST, 3);
    printf("BST setelah DelBtree 3: \n");
    PrintTreeInden(BST, 0);

    printf("\nDelBtree 8 (node daun)\n");
    DelBtree(&BST, 8);
    printf("BST setelah DelBtree 8: \n");
    PrintTreeInden(BST, 0);

    return 0;
}