#include <stdio.h>
#include <string.h>

int main() {
    // Define tipe data berupa mahasiswa
    typedef struct {
        char nama[50];
        int umur;
        char jurusan[50];
        float ipk;
    } Mahasiswa;

    // Mahasiswa mhs1;
    // strcpy(mhs1.nama, "Akmal"); // menginisiasi nama
    // mhs1.umur = 20; // menginisiasi umur
    // strcpy(mhs1.jurusan, "Teknologi Informasi"); // menginisisai jurusan
    // mhs1.ipk = 3.5; // menginisiasi nilai ipk

    Mahasiswa mhs[10];
    for (int i = 0; i < 10; i++) {
        scanf("%s %d %s %f", mhs[i].nama, &mhs[i].umur, mhs[i].jurusan, &mhs[i].ipk);
    }

    // printf("Mahasiswa dengan nama %s berumur %d tahun, berjurusan %s, dan nilai ipk %.2f\n", mhs1.nama, mhs1.umur, mhs1.jurusan, mhs1.ipk);
    for (int i = 0; i < 10; i++) {
        printf("Mahasiswa %d bernama %s berumur %d tahun, berjurusan %s, dan nilai ipk %.2f\n", i + 1, mhs[i].nama, mhs[i].umur, mhs[i].jurusan, mhs[i].ipk);
    }

    return 0;
}