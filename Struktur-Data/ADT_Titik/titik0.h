#ifndef TITIK0_H
#define TITIK0_H

#include <stdio.h>

// Definisi tipe data Titik
typedef struct {
    int x; // absis
    int y; // ordinat
} Titik;

// Konstruktor
Titik makeTitik(int x, int y);

// Selektor
int getAbsis(Titik T);      // ambil nilai x
int getOrdinat(Titik T);    // ambil nilai y

// Mutator
void setAbsis(Titik *T, int newX);
void setOrdinat(Titik *T, int newY);

// Prosedur Baca/Tulis
void bacaTitik(Titik *T);       // input dari user
void tulisTitik(Titik T);       // output ke user

// Prototipe operasi relasional
int isEqual(Titik T1, Titik T2);            
int isNotEqual(Titik T1, Titik T2);         
int isLessThan(Titik T1, Titik T2);         
int isGreaterThan(Titik T1, Titik T2);      

#endif
