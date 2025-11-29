/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130123 / Muhammad Akmal Fazli Riyadi*/
/* Tanggal : 27 November 2025 */

#include "pohon1.h"

int main() {
     //kamus
     bintree B;
     
     //algoritma
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
     printf("Pohon B: ");
     PrintPrefixRingkas(B);
     
     /*PREDIKAT*/
     printf("\n\nApakah Pohon B kosong? %d", IsEmptyTree(B));
     printf("\nApakah Pohon B biner? %d", IsBiner(B));

     /*PENELUSURAN*/
     printf("\nBanyak elemen Pohon B: %d", NbElm(B));
     printf("\nBanyak daun Pohon B: %d", NbDaun(B));
     printf("\nTinggi Pohon B: %d", Tinggi(B));

     /*** PENCARIAN ***/
     printf("\nApakah 'R' ada di Pohon B? %d", SearchX(B, 'R'));

     /*** MANIPULASI ELEMEN bintree ***/
     printf("\nUpdate 'R' menjadi 'Z'");
     UpdateX(&B, 'R', 'Z');
     printf("\nPohon B setelah update: ");
     PrintPrefixRingkas(B);

     /*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
     printf("\n\nBanyak elemen 'A' pada Pohon B: %d", CountX(B, 'A'));
     
     printf("\nApakah Pohon B condong kiri? %d", IsSkewLeft(B));
     printf("\nApakah Pohon B condong kanan? %d", IsSkewRight(B));
     
     printf("\n\nLevel elemen 'M' pada Pohon B: %d", LevelX(B, 'M'));
     printf("\nBanyak node pada level 3: %d", CountLevel(B, 3));
     
     printf("\nNode pada level 2: ");
     PrintLevel(B, 2);
     
     printf("\nDaun terkiri: %c", GetDaunTerkiri(B));
     
     printf("\nFrekuensi 'A' pada Pohon B: %.2f", FrekuensiX(B, 'A'));
     
     printf("\n\nBanyak huruf vokal: %d", CountVocal(B));
     printf("\nHuruf vokal: ");
     PrintVocal(B);
     
     printf("\nBanyak huruf konsonan: %d", CountConsonant(B));
     printf("\nHuruf konsonan: ");
     PrintConsonant(B);
     
     printf("\n\nModus (huruf paling sering muncul): %c", Modus(B));
     
     printf("\n");
     return 0;
}
