#include <stdio.h>
#include "boolean.h" // Jika Anda menggunakannya
#include "proses.h"
#include "tqueue.h"


/* ----- KONSTRUKTOR ----- */
/*
 * I.S. ID dan BT terdefinisi.
 * F.S. Menghasilkan sebuah Proses baru dengan IDProses=ID dan BurstTime=BT.
 */
void MakeProses(Proses *P, char ID, int BT) {
    P -> IDProses = ID;
    P -> BurstTime = BT;
}

void MakeDaftar(daftarProses *DP) { // Untuk menyimpan array sementara dari setiap proses
    Proses emptyProses;
    MakeProses(&emptyProses, '#', 0); 
    for (int i = 1; i < 6; i++) {
        DP->wadah[i] = emptyProses;
    }
}


/* ----- SELEKTOR ----- */
/* Mengirimkan komponen dari sebuah Proses */

/*
 * I.S. P terdefinisi.
 * F.S. Mengembalikan nilai IDProses dari P.
 */
char GetIDProses(Proses P) {
    return P.IDProses;
}

/*
 * I.S. P terdefinisi.
 * F.S. Mengembalikan nilai BurstTime dari P.
 */
int GetBurstTime(Proses P) {
    return P.BurstTime;
}


/* ----- MUTATOR ----- */
/* Mengubah nilai komponen dari sebuah Proses */

/*
 * I.S. P terdefinisi, newID terdefinisi.
 * F.S. Mengubah nilai IDProses dari P menjadi newID.
 * Menggunakan pointer agar nilai P yang asli berubah.
 */
void SetIDProses(Proses *P, char newID) {
    P->IDProses = newID;
}

/*
 * I.S. P terdefinisi, newBT terdefinisi dan non-negatif.
 * F.S. Mengubah nilai BurstTime dari P menjadi newBT.
 * Menggunakan pointer agar nilai P yang asli berubah.
 */
void SetBurstTime(Proses *P, int newBT) {
    P->BurstTime = newBT;
}

void SetDaftar(daftarProses *DP, tqueue *Q) {
    Proses tempProses;

    for (int i = 1; i <= 5; i++) {
        dequeue(Q, &tempProses);

        DP->wadah[i] = tempProses;
    }
}


/* ----- OPERATOR ----- */
/* Menampilkan informasi Proses */

/*
 * I.S. P terdefinisi.
 * F.S. Menampilkan IDProses dan BurstTime dari P ke layar
 */
void PrintProses(Proses P) {
    printf("ID: %c | BT: %d", GetIDProses(P), GetBurstTime(P));
}

/* ----- LAINNYA ----- */
void swapProses(Proses *a, Proses *b) {
    Proses temp = *a;
    *a = *b;
    *b = temp;
}

void sortDaftarProses(daftarProses *DP) {
    int i, j;
    
    for (i = 1; i <= 5 - 1; i++) {
        for (j = 1; j <= 5 - i; j++) {
            if (GetBurstTime(DP->wadah[j]) > GetBurstTime(DP->wadah[j + 1])) {
                swapProses(&DP->wadah[j], &DP->wadah[j + 1]);
            }
        }
    }
}

/*
 * I.S.: Q bisa dalam keadaan kosong atau sembarang, DP berisi proses yang sudah terurut,
 * dan n adalah jumlah proses.
 * F.S.: Q akan berisi semua proses dari DP dalam urutan yang sama.
 * Proses: Mengosongkan Q lalu mengisinya satu per satu dari DP.
 */
void DaftarKeQueue(tqueue *Q, daftarProses DP) {
    createQueue(Q);

    for (int i = 1; i <= 5; i++) {
        enqueue(Q, DP.wadah[i]);
    }
}
