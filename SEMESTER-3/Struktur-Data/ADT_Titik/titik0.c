#include "titik0.h"
// Konstruktor
Titik makeTitik(int x, int y) {
    Titik T;
    T.x = x;
    T.y = y;
    return T;
}
// Selektor
int getAbsis(Titik T) {
    return T.x;
}
int getOrdinat(Titik T) {
    return T.y;
}

// Mutator
void setAbsis(Titik *T, int newX) {
    T->x = newX;
}
void setOrdinat(Titik *T, int newY) {
    T->y = newY;
}

// Baca Tulis
void bacaTitik(Titik *T) {
    int x, y;
    printf("Masukkan absis dan ordinat (x y): ");
    scanf("%d %d", &x, &y);
    *T = makeTitik(x, y);
}
void tulisTitik(Titik T) {
    printf("(%d,%d)",getAbsis(T), getOrdinat(T));
}

// Relasional
int isEqual(Titik T1, Titik T2) {
    return (getAbsis(T1) == getAbsis(T2) && getOrdinat(T1) == getOrdinat(T2));
}
int isNotEqual(Titik T1, Titik T2) {
    return !isEqual(T1, T2);
}
int isLessThan(Titik T1, Titik T2) {
    return (getAbsis(T1) < getAbsis(T2) && getOrdinat(T1) < getOrdinat(T2));
}
int isGreaterThan(Titik T1, Titik T2) {
    return (getAbsis(T1) > getAbsis(T2) && getOrdinat(T1) > getOrdinat(T2));
}