/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "matriks.h" 
#ifndef MATRIKS_H
#define MATRIKS_H

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M) {
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            M->cell[i][j] = -999;
        }
    }
    M->nbaris = 0;
    M->nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M) {
    return getNBaris(M) == 0 && getNKolom(M) == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M) {
    return getNBaris(M) != 0 && getNKolom(M) != 0;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col) {
    if (M->cell[row][col] == -999) {
        int i, j;
        int rowBaru = 1; 
        int colBaru = 1; 

        for (j = 1; j < 11; j++) {
            if (M->cell[row][j] != -999) {
                rowBaru = 0; 
                break;
            }
        }

        for (i = 1; i < 11; i++) {
            if (M->cell[i][col] != -999) {
                colBaru = 0; 
                break;
            }
        }

        M->cell[row][col] = X;

        if (rowBaru == 1) {
            M->nbaris++;
        }

        if (colBaru == 1) {
            M->nkolom++;
        }
    }
}
    

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X) {
    int i, j;
    int idxRow, idxCol;

    for (i = 1; i < 11; i++) {
        for (j = 1; j < 11; j++) {
            if (M->cell[i][j] == X) {
                idxRow = i;
                idxCol = j;
                M->cell[i][j] = -999;
                break;
            }
        }
    }

    if (M->cell[idxRow][idxRow] == -999) {
        for (j = 1; j <= 11; j++) {
            if (M->cell[idxRow][j] != -999) {
                break;
            }
        }

        if (j > 11) {
            M->nbaris--;
        }

        for (i = 1; i <= 11; i++) {
            if (M->cell[i][idxCol] != -999) {
                break;
            }
        }

        if (i > 11) {
            M->nkolom--;
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
    int i, j;
    int randInt;
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            randInt = rand() % 10 + 1;
            addX(&(*M), randInt, i, j);
        }
    }
    M->nbaris = x;
    M->nkolom = y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                M->cell[i][j] = 1;
                M->nbaris++;
                M->nkolom++;
            }
            else {
                M->cell[i][j] = 0;
            }
        }
    }
    M->nbaris = n;
    M->nkolom = n;
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
    int i, j;
    int z;
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            printf("Baris ke-%d kolom ke-%d: ",i, j);
            scanf("%d", &z);
            M->cell[i][j] = z;
        }
        printf("\n");
    }
    M->nbaris = x;
    M->nkolom = y;
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks *M) {
    for (int i = 1; i < 11; i++) {
        printf("[");
        for (int j = 1; j < 11; j++) {
            printf("%d", M->cell[i][j]);
            if (j < 10) {
                printf("\t");
            }
        }
        printf("]");
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks *M) {
    int i, j;

    for (i = 1; i <= getNBaris(*M); i++) {
        printf("[");
        for (j = 1; j <= getNKolom(*M); j++) {
            printf("%d", M->cell[i][j]);
            if (j < getNKolom(*M)) {
                printf("\t");
            }
        }
        printf("]");
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
    int i, j;
    Matriks M3;
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        initMatriks(&M3);
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M2); j++) {
                M3.cell[i][j] = M2.cell[i][j] + M1.cell[i][j];
            }
        }
        M3.nbaris = getNBaris(M1);
        M3.nkolom = getNKolom(M1);
        return M3;
    }
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2) {
    int i, j;
    Matriks M3;

    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        initMatriks(&M3);
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M2); j++) {
                M3.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
        }
        M3.nbaris = getNBaris(M1);
        M3.nkolom = getNKolom(M1);
        return M3;
    }
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2) {
    Matriks M3;
    int i, j, k, hasil;
    
    initMatriks(&M3);
    if (getNBaris(M1) == getNKolom(M2) || getNBaris(M2) == getNKolom(M1)) {
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M2); j++) {
                hasil = 0;
                for (k = 0; k <= getNKolom(M1); k++) {
                    hasil += M1.cell[i][k] * M2.cell[k][j];
                }
                M3.cell[i][j] = hasil;
            }
        }
        M3.nbaris = j-1;
        M3.nkolom = k-1;
    }
    return M3;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x) {
    Matriks M2;
    int i, j;
    if (!isEmptyMatriks(M1)) {
        initMatriks(&M2);
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M1); j++) {
                M2.cell[i][j] = M1.cell[i][j] * x;
            }
        }
        M2.nbaris = getNBaris(M1);
        M2.nkolom = getNKolom(M1);
        return M2;
    }
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    int i, j, temp;

    if (!isEmptyMatriks(*M)) {
        for (i = 1; i <= getNBaris(*M); i++) {
            j = i;
            while (j <= getNKolom(*M)) {
                temp = M->cell[j][i];
                M->cell[j][i] = M->cell[i][j];
                M->cell[i][j] = temp;
                j++;
            }
        }
    }
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
    Matriks M2;
    int i, j;
    
    initMatriks(&M2);
    M2.nbaris = getNBaris(M);
    M2.nkolom = getNKolom(M);
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            M2.cell[i][j] = M.cell[j][i];
        }
    }
    return M2;
}

/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n) {
    Matriks T;
    int i, j;
    initMatriks(&T);
    T.nbaris = getNBaris(M) + 2 * n;
    T.nkolom = getNKolom(M) + 2 * n;

    for (i = 1; i <= getNBaris(T); i++) {
        for (j = 1; j <= getNKolom(T); j++) {
            if (i > n && i <= getNBaris(M) + n && j > n && j <= getNKolom(M) + n) {
                T.cell[i][j] = M.cell[i - n][j - n];
            }
            else {
                T.cell[i][j] = 0;
            }
        }
    }
    return T;
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size) {
    int i, j, k, l, max, temp, row, col;
    Matriks T;

    // algoritma
    initMatriks(&T);
    if (getNBaris(M) % size == 0 && getNKolom(M) % size == 0) {
        for (i = 1; i <= getNBaris(M); i = i + size) {
            for (j = 1; j <= getNKolom(M); j = j + size) {
                max = 0;

                for (k = i; k < i + size; k++) {
                    for (l = j; l < j + size; l++) {
                        temp = M.cell[k][l];
                        if (temp > max) {
                            max = temp;
                        }
                    }
                }

                row = (i - 1) / size + 1;
                col = (j - 1) / size + 1;
                addX(&T, max, row, col);
            }
        }
    }

    return T;
}

/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size) {
    int i, j, k, l, sum, avg, temp, row, col;
    Matriks T;

    initMatriks(&T);
    if (getNBaris(M) % size == 0 && getNKolom(M) % size == 0) {
        for (i = 1; i <= getNBaris(M); i = i + size) {
            for (j = 1; j <= getNKolom(M); j = j + size) {
                sum = 0;

                for (k = i; k < i + size; k++) {
                    for (l = j; l < j + size; l++) {
                        sum += M.cell[k][l];
                    }
                }

                avg = sum / size * size;
                row = (i - 1) / size + 1;
                col = (j - 1) / size + 1;
                addX(&T, avg, row, col);
            }
        }
    }

    return T;
}

/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K);

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col);

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X);

#endif