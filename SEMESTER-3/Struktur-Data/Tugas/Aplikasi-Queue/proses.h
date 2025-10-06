#ifndef PROSES_H
#define PROSES_H

#include <stdbool.h>

/* ----- Definisi Tipe Proses ----- */
typedef struct {
    char IDProses;  /* komponen IDProses bertipe character  */
    int BurstTime;  /* komponen Burst Time bertipe integer  */
} Proses;


/* ----- KONSTRUKTOR ----- */

/* procedure makeProses(input/output P: Proses, input ID: character, BT: integer)
{I.S. P tak terdefinisi, ID dan BT terdefinisi.}
{F.S. P terisi dengan IDProses=ID dan BurstTime=BT.} 
*/
void makeProses(Proses *P, char ID, int BT);


/* ----- SELEKTOR ----- */
/* Mengirimkan komponen dari sebuah Proses */

/* function getIDProses(P: Proses) -> character
{I.S. P terdefinisi.}
{F.S. Mengembalikan nilai IDProses dari P.}
*/
char getIDProses(Proses P);

/* function getBurstTime(P: Proses) -> integer
{I.S. P terdefinisi.}
{F.S. Mengembalikan nilai BurstTime dari P.}
*/
int getBurstTime(Proses P);


/* ----- MUTATOR ----- */
/* Mengubah nilai komponen dari sebuah Proses */

/* procedure setIDProses(input/output P: Proses, input newID: character)
{I.S. P terdefinisi, newID terdefinisi.}
{F.S. Mengubah nilai IDProses dari P menjadi newID.}
{Menggunakan pointer agar nilai P yang asli berubah.}
*/
void setIDProses(Proses *P, char newID);

/* procedure setBurstTime(input/output P: Proses, input newBT: integer)
{I.S. P terdefinisi, newBT terdefinisi dan non-negatif.}
{F.S. Mengubah nilai BurstTime dari P menjadi newBT.}
{Menggunakan pointer agar nilai P yang asli berubah.}
*/
void setBurstTime(Proses *P, int newBT);


#endif