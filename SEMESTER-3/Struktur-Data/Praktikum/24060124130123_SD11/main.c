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
    B = Tree('T',
               Tree('I',
                    Tree('N',NIL,NIL),
                    Tree('F',
                         Tree('O',NIL,NIL),
                         NIL)),
               Tree('R',
                    Tree('M',
                         Tree('A',NIL,NIL),
                         Tree('T',NIL,NIL)),
                    Tree('I',
                         NIL,
                         Tree('K',
                              NIL,
                              Tree('A',NIL,NIL))))
               );

    printf("Pohon B: \n");
    PrintTreeInden(B, 0);
    
    /*PENELUSURAN*/
    printf("\nLevel 2 pada Pohon B: ");
    PrintLevel2(B, 2);

    
    /*** MANIPULASI ELEMEN bintree ***/
    printf("\n\nUpdate 'A' menjadi 'X'");
    UpdateAllX(&B, 'A', 'X');
    printf("\nPohon B setelah update: \n");
    PrintTreeInden(B, 0);

    
    /******* PENAMBAHAN ELEMEN bintree ********/
    printf("\nAddDaunTerkiri 'Z'");
    AddDaunTerkiri(&B, 'Z');
    printf("\nPohon B setelah AddDaunTerkiri: \n");
    PrintTreeInden(B, 0);

    printf("\nAddDaun: Tambah 'W' sebagai anak kiri 'Z'");
    AddDaun(&B, 'Z', 'W', true);
    printf("\nPohon B setelah AddDaun: \n");
    PrintTreeInden(B, 0);

    printf("\nInsertX 'Q' (BST insert)");
    B2 = Tree('M',
              Tree('D',NIL,NIL),
              Tree('S',NIL,NIL));
    printf("\nPohon B2 sebelum InsertX: \n");
    PrintTreeInden(B2, 0);
    InsertX(&B2, 'Q');
    printf("Pohon B2 setelah InsertX 'Q': \n");
    PrintTreeInden(B2, 0);

    
    /******* PENGHAPUSAN ELEMEN ********/
    printf("\nDelDaunTerkiri");
    DelDaunTerkiri(&B, &deletedValue);
    printf("\nNilai yang dihapus: %c", (char)deletedValue);
    printf("\nPohon B setelah DelDaunTerkiri: \n");
    PrintTreeInden(B, 0);

    printf("\nDelDaun 'K'");
    DelDaun(&B, 'K');
    printf("\nPohon B setelah DelDaun 'K': \n");
    PrintTreeInden(B, 0);

    printf("\nDeleteX 'I' (hapus node dengan 2 anak)");
    DeleteX(&B, 'I');
    printf("\nPohon B setelah DeleteX 'I': \n");
    PrintTreeInden(B, 0);

    
    /*********** SOAL TAMBAHAN *****************/
    printf("\n\nBuildBalanceTree dengan 5 node");
    printf("\nMasukkan 5 karakter (in-order): ");
    B3 = BuildBalanceTree(5);
    printf("Pohon B3 (balanced): \n");
    PrintTreeInden(B3, 0);

    /*PREDIKAT*/
    printf("\nIsBalanceTree B3: %d", IsBalanceTree(B3));
    printf("\nIsBalanceTree B: %d", IsBalanceTree(B));

    printf("\n\nmaxTree B: %c", (char)maxTree(B));
    printf("\nminTree B: %c", (char)minTree(B));

    
    /*Operator KHUSUS Binary Search Tree*/
    printf("\n\nInsSearch: Membuat BST dengan nilai 5, 3, 7, 2, 4, 6, 8");
    BST = NIL;
    BST = InsSearch(BST, 5);
    BST = InsSearch(BST, 3);
    BST = InsSearch(BST, 7);
    BST = InsSearch(BST, 2);
    BST = InsSearch(BST, 4);
    BST = InsSearch(BST, 6);
    BST = InsSearch(BST, 8);
    printf("\nBST: \n");
    PrintTreeInden(BST, 0);

    printf("\nBSearch 4 pada BST: %d", BSearch(BST, 4));
    printf("\nBSearch 9 pada BST: %d", BSearch(BST, 9));

    printf("\n\nDelBtree 3 (node dengan 2 anak)");
    DelBtree(&BST, 3);
    printf("\nBST setelah DelBtree 3: \n");
    PrintTreeInden(BST, 0);

    printf("\nDelBtree 8 (node daun)");
    DelBtree(&BST, 8);
    printf("\nBST setelah DelBtree 8: \n");
    PrintTreeInden(BST, 0);

    printf("\n");
    return 0;
}