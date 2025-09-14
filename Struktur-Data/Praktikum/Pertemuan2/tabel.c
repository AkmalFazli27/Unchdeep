#ifndef tabel_c
#define tabel_c
#include "tabel.h"
/* Deskripsi : */
/* NIM/Nama : 24060124130123/Muhammad Akmal Fazli Riyadi */
/* Tanggal : 9/11/2025 */

/************************KONSTRUKTOR*************************/				 
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
	{Proses: menginisialisasi T} */
void createTable(Tabel *T) {
    for (int i=1; i < 11; i++) {
        T->wadah[i] = ' '; 
    } 
    T->size = 0;
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T) {
    return T.size;
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T) {
    return getSize(T) == 0;
}

/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T) {
    return getSize(T) == 10;
}

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos) {
    if (isEmptyTable(T)) {
        *pos = -999;
    }
    else {
        for (int i = 1; i < 11; i++) {
            if (T.wadah[i] == x) {
                *pos = i;
                break;
            }
            else {
                *pos = -999;
            }
        }
    }
}

/* function countX (T:Tabel, x:character) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x) {
    int count = 0;
    if (isEmptyTable(T)) {
        return 0;
    }
    for (int i = 1; i < 11; i++) {
        if (T.wadah[i] == x) {
            count++;
        }
    }
    return count;
}

/* function countVocal(T: Tabel) -> integer
	{mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
int countVocal(Tabel T) {
    int count = 0;
    for (int i = 1; i < 11; i++) {
        if (T.wadah[i] == 'a' || T.wadah[i] == 'i' || T.wadah[i] == 'u' || T.wadah[i] == 'e' || T.wadah[i] == 'o' ||
            T.wadah[i] == 'A' || T.wadah[i] == 'I' || T.wadah[i] == 'U' || T.wadah[i] == 'E' || T.wadah[i] == 'O') {
            count += 1;
        }
    return count;
    }
}

/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai x}*/
void addXTable(Tabel *T, char x) {
    if (!isFullTable(*T)) {
        for (int i = 1; i < 11; i++) {
            if (T->wadah[i] == ' ') {
                T->wadah[i] = x;
                T->size++;
                break;
            }
        }
    }
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai unik x}*/
void addUniqueXTable(Tabel *T, char x) {
    int pos;
    searchX(*T, x, &pos);
    if (pos == -999) {
        addXTable(T, x);
    } 
}

/* procedure delXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi, x terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x) {
    if (!isEmptyTable(*T)) {
        int pos;
        searchX(*T, x, &pos);
        for (pos; pos < 10; pos++) {
            T->wadah[pos] = T->wadah[pos + 1];
        }
        T->wadah[T->size] = ' ';
        T->size--;
    }
}

/* procedure delTable (input/output T:Tabel, input idx:integer)
	{I.S.: T terdefinisi, idx antara 1...getSize(T)}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx) {
    if (!isEmptyTable(*T)) {
        for (idx; idx < 10; idx++) {
            T->wadah[idx] = T->wadah[idx + 1];
        }
        T->wadah[T->size] = ' ';
        T->size--;
    }
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x) {
    if (!isEmptyTable(*T)) {
        for (int i = 1; i < getSize(*T); i++) {
            if (T->wadah[i] == x) {
                for (int j = i; j < getSize(*T); j++) {
                    T->wadah[j] = T->wadah[j+1];
                }
                T->wadah[T->size] = ' ';
                T->size--;
                i--;
            }
        }
    }
}

/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T) {
    printf("[");
    for (int i = 1; i < 11; i++) {
        printf("%c", T.wadah[i]);
        if (i < 10) {
            printf(", ");
        }
    }
    printf("]\n");
}

/* procedure viewTable (input T:Tabel)
{I.S.: T terdefinisi}
{F.S.: -}
{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T) {
    printf("[");
    for (int i = 1; i < getSize(T)+1; i++) {
        if (T.wadah[i] != ' ') {
            printf("%c", T.wadah[i]);
            if (i < getSize(T)) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N) {
    if (!isEmptyTable(*T)) {
        if (N > 0 && N < 10 - getSize(*T)) {
            int i = getSize(*T) + 1;
            while (N != 0) {
                int x;
                printf("Masukkan elemen ke-%d: ", i);
                scanf(" %c", &x);
                if (x > 0) {
                    T->wadah[i] = x;
                    T->size++; 
                    N--;
                    i++;
                }
            }
        }
    }
}

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus(Tabel T) {
    if (!isEmptyTable(T)) {
        char modus;
        int max_count = 0;
        for (int i = 1; i < getSize(T)+1; i++) {
            int count = 0;
            for (int j = 1; j < getSize(T)+1; j++) {
                if (T.wadah[i] == T.wadah[j]) {
                    count++;
                }
            }
            if (max_count < count) {
                modus = T.wadah[i];
                max_count = count;
            }
        }
        return modus;
    }
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean 
	{mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2) {
    if (getSize(T1) == getSize(T2)) {
        boolean cond = true;
        for (int i = 1; i < getSize(T1); i++) {
            if (T1.wadah[i] == T2.wadah[i]) {
                cond = 1;
            }
            else {
                cond = false;
                break;
            }
        }
        return cond;
    }
    else {
        return false;
    }
}


/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel 
	{mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T) {
    Tabel T3;
    createTable(&T3);
    int x = 1;
    
    for (int i = getSize(T); i > 0; i--) {
        T3.wadah[x] = T.wadah[i];
        x++;
        T3.size++;
    }
    return T3;
}

/* procedure inverseTable(input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
	{Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T);

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T);

/* procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T);

#endif