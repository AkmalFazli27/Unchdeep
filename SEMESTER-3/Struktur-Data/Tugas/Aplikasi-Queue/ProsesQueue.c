#include <stdio.h>
#include "boolean.h" 
#include "ProsesQueue.h"

/* ----- KONSTRUKTOR ----- */
/* procedure makeProses(input/output P: Proses, input ID: character, BT: integer)
{I.S. P tak terdefinisi, ID dan BT terdefinisi.}
{F.S. P terisi dengan IDProses=ID dan BurstTime=BT.} 
*/
void makeProses(Proses *P, char ID, int BT) {
    P -> IDProses = ID;
    P -> BurstTime = BT;
}

/* procedure makeDaftar(input/output DP: daftarProses)
{I.S.: -}
{F.S.: DP terisi dengan elemen Proses berisi kosong.}
*/
void makeDaftar(daftarProses *DP) {
    Proses emptyProses;
    makeProses(&emptyProses, '#', 0); 
    for (int i = 1; i < 6; i++) {
        DP->wadah[i] = emptyProses;
    }
}

/*procedure createQueue(output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan Proses kosong, head=tail=0}
*/ 
void createQueue(tqueue *Q) {
    Proses emptyProses;
    makeProses(&emptyProses, '#', 0); 
    for (int i = 1; i < 6; i++) {
        Q->wadah[i] = emptyProses;
    }
    Q->head = 0;
    Q->tail = 0;
}


/* ----- SELEKTOR ----- */
/* Mengirimkan komponen dari sebuah Proses */

/*function head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} 
*/
#define head(Q) (Q).head

/*function tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} 
*/
#define tail(Q) (Q).tail

/*function infoHead(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terdepan antrian Q} 
*/
Proses infoHead(tqueue Q) { 
    return Q.wadah[head(Q)];
}

/*function infoTail(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terakhir antrian Q} 
*/
Proses infoTail(tqueue Q) { 
    return Q.wadah[tail(Q)];
}

/* function getIDProses(P: Proses) -> character
{I.S. P terdefinisi.}
{F.S. Mengembalikan nilai IDProses dari P.}
*/
char getIDProses(Proses P) {
    return P.IDProses;
}

/* function getBurstTime(P: Proses) -> integer
{I.S. P terdefinisi.}
{F.S. Mengembalikan nilai BurstTime dari P.}
*/
int getBurstTime(Proses P) {
    return P.BurstTime;
}


/* ----- MUTATOR ----- */
/* Mengubah nilai komponen dari sebuah Proses */

/* procedure setIDProses(input/output P: Proses, input newID: character)
{I.S. P terdefinisi, newID terdefinisi.}
{F.S. Mengubah nilai IDProses dari P menjadi newID.}
{Menggunakan pointer agar nilai P yang asli berubah.}
*/
void setIDProses(Proses *P, char newID) {
    P->IDProses = newID;
}

/* procedure setBurstTime(input/output P: Proses, input newBT: integer)
{I.S. P terdefinisi, newBT terdefinisi dan non-negatif.}
{F.S. Mengubah nilai BurstTime dari P menjadi newBT.}
{Menggunakan pointer agar nilai P yang asli berubah.}
*/
void setBurstTime(Proses *P, int newBT) {
    P->BurstTime = newBT;
}

void setDaftar(daftarProses *DP, tqueue *Q) {
    Proses tempProses;

    for (int i = 1; i <= 5; i++) {
        dequeue(Q, &tempProses);
        DP->wadah[i] = tempProses;
    }
}

/*procedure enqueue( input/output Q: tQueue, input e: Proses )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } 
*/
void enqueue(tqueue *Q, Proses P) {
    if (!isFullQueue(*Q)) {
        if (isEmptyQueue(*Q)) {
            Q->head++;
        }
        Q->tail++;
        Q->wadah[tail(*Q)] = P; 
    }
}

/*procedure dequeue( input/output Q:tQueue, output P: Proses )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju}
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } 
*/
void dequeue(tqueue *Q, Proses *P) {
    Proses emptyProses;
    makeProses(&emptyProses, '#', 0);  

    if (!isEmptyQueue(*Q)) {
        *P = Q->wadah[head(*Q)];  

        for (int i = 1; i < tail(*Q); i++) {
            Q->wadah[i] = Q->wadah[i + 1];
        }
        Q->wadah[tail(*Q)] = emptyProses;

        if (tail(*Q) == 1) {
            Q->head = 0;
            Q->tail = 0;
        } else {
            Q->tail--;
        }
    } else {
        *P = emptyProses;  
    }
}


/* ----- OPERATOR ----- */
/* Menampilkan informasi Proses */

/* procedure printProses(input/output P: Proses)
{I.S. P terdefinisi.}
{F.S. Menampilkan IDProses dan BurstTime dari P ke layar}
*/
void printProses(Proses P) {
    printf("ID: %c | BT: %d", getIDProses(P), getBurstTime(P));
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: Mencetak elemen tak kosong ke layar}
*/
void viewQueue(tqueue *Q) {
    if (!isEmptyQueue(*Q)) {
        for (int i = head(*Q); i <= tail(*Q); i++) {
            printProses(Q->wadah[i]); 
            if (i < tail(*Q)) {
                printf("\n");
            }
        }
    }
}

/*procedure printEksekusi(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: Mencetak proses eksekusi dengan waktu mulai dan waktu selesai}
*/
void printEksekusi(tqueue *Q) {
    int waktuSkrg = 0;
    int waktuMulai, waktuSelesai;
    Proses prosesDieksekusi; 

    while (!isEmptyQueue(*Q)) {
        Proses prosesSkrg = infoHead(*Q);
        waktuMulai = waktuSkrg;
        waktuSelesai = waktuSkrg + getBurstTime(prosesSkrg);

        printf("Eksekusi Proses '%c', Mulai: %d, Selesai: %d (Burst Time: %d)\n",
               getIDProses(prosesSkrg),
               waktuMulai,
               waktuSelesai,
               getBurstTime(prosesSkrg));

        waktuSkrg = waktuSelesai;
        dequeue(Q, &prosesDieksekusi);
    }
}

/* ----- PREDIKAT ----- */

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}
*/
boolean isEmptyQueue(tqueue Q) {
    return Q.head == 0 && Q.tail == 0;
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}
*/
boolean isFullQueue(tqueue Q) {
    return Q.tail == 5;
}


/* ----- LAINNYA ----- */

/* procedure swapProses(input/output a: Proses, b: Proses)
{I.S. a dan b terdefinisi.}
{F.S. Menukar posisi Prses a dan Proses b}
*/
void swapProses(Proses *a, Proses *b) {
    Proses temp = *a;
    *a = *b;
    *b = temp;
}

/* procedure sortDaftarProses(input/output DP: daftarProses)
{I.S. DP terdefinisi.}
{F.S. Menghasilkan daftar proses yang sudah diurutkan berdasarkan burst time}
*/
void sortDaftarProses(daftarProses *DP) {
    int i, j;
    
    for (i = 1; i <= 5 - 1; i++) {
        for (j = 1; j <= 5 - i; j++) {
            if (getBurstTime(DP->wadah[j]) > getBurstTime(DP->wadah[j + 1])) {
                swapProses(&DP->wadah[j], &DP->wadah[j + 1]);
            }
        }
    }
}

/* procedure daftarKeQueue(input/output Q: tqueue, input DP: daftarProses)
{I.S. DP terdefinisi.}
{F.S. Memasukkan elemen daftar proses yang sudah diurutkan berdasarkan burst time ke dalam queue}
*/
void daftarKeQueue(tqueue *Q, daftarProses DP) {
    createQueue(Q);

    for (int i = 1; i <= 5; i++) {
        enqueue(Q, DP.wadah[i]);
    }
}

