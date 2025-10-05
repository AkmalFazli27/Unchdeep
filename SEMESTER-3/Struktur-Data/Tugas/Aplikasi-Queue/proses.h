#ifndef PROSES_H
#define PROSES_H

#include <stdbool.h>

/* ----- Definisi Tipe Proses ----- */
typedef struct {
    char IDProses;  /* komponen IDProses bertipe character  */
    int BurstTime;  /* komponen Burst Time bertipe integer  */
} Proses;

typedef	struct { 
    Proses wadah[6];
} daftarProses;

/* ----- KONSTRUKTOR ----- */
/* 
I.S. P bisa sembarang, ID dan BT terdefinisi. 
F.S. P terisi dengan IDProses=ID dan BurstTime=BT. 
*/
void MakeProses(Proses *P, char ID, int BT);


/* ----- SELEKTOR ----- */
/* Mengirimkan komponen dari sebuah Proses */

/*
 * I.S. P terdefinisi.
 * F.S. Mengembalikan nilai IDProses dari P.
 */
char GetIDProses(Proses P);

/*
 * I.S. P terdefinisi.
 * F.S. Mengembalikan nilai BurstTime dari P.
 */
int GetBurstTime(Proses P);


/* ----- MUTATOR ----- */
/* Mengubah nilai komponen dari sebuah Proses */

/*
 * I.S. P terdefinisi, newID terdefinisi.
 * F.S. Mengubah nilai IDProses dari P menjadi newID.
 * Menggunakan pointer agar nilai P yang asli berubah.
 */
void SetIDProses(Proses *P, char newID);

/*
 * I.S. P terdefinisi, newBT terdefinisi dan non-negatif.
 * F.S. Mengubah nilai BurstTime dari P menjadi newBT.
 * Menggunakan pointer agar nilai P yang asli berubah.
 */
void SetBurstTime(Proses *P, int newBT);



/* ----- OPERATOR ----- */
/* Menampilkan informasi Proses */

/*
 * I.S. P terdefinisi.
 * F.S. Menampilkan IDProses dan BurstTime dari P ke layar
 * dengan format: "P<ID>(BT)" contoh: "PA(10)".
 */
void PrintProses(Proses P);

/* ----- LAINNYA ----- */
void sortDaftar(daftarProses *DP);



#endif