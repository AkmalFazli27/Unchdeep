"""
Program   : TYPE MAHASISWA
Deskripsi : Fungsi ini menggunakan tipe bentukan MHS2 dan akan menghasilkan range (selisih nilai tertinggi dan terendah) dari nilai mahasiswa tersebut. Fungsi ini harus mengembalikan sebuah nilai tipe bentukan yang memuat: KodeMatkul, NilaiTertinggi, NilaiTertinggi, NilaiTerendah, RangeNilai.
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 30/09/2024
"""

"""
DEFINISI TYPE
type MHS1 : <x:string, y:string, z:Tanggal>
    {<x, y, z> adalah sebuah data informasi dasar, dengan x adalah NIM, y adalah Nama, dan z adalah tanggal lahir mahasiswa}
type MHS2 : <x:string, y:string, z:integer>
    {<x, y, z> adalah sebuah data informasi nilai, dengan x adalah NIM, y adalah KodeMatkul, dan z adalah Nilai}
type MHS3 : <x:string, y:string>
    {<x, y> adalah sebuah data informasi matkul, dengan x adalah KodeMatkul dan y adalah NamaMatkul}

DEFINISI DAN SPESIFIKASI SELEKTOR MHS1
NIM: MHS1 --> string
    {NIM(P) memberikan NIM MHS1 dari P}

Nama: MHS1 --> string
    {Nama(P) memberikan Nama MHS1 dari P}

Tanggal: MHS1 --> string
    {Tanggal(P) memberikan tanggal lahir MHS1 dari P}

DEFNISI DAN SPESIFIKASI SELEKTOR MHS2
NIM: MHS2 --> string
    {NIM(P) memberikan NIM MHS2 dari P}

Nama: MHS2 --> string
    {Nama(P) memberikan KodeMatkul MHS2 dari P}

Tanggal: MHS2 --> integer
    {Tanggal(P) memberikan Nilai MHS2 dari P}

DEFNISI DAN SPESIFIKASI SELEKTOR MHS3
NIM: MHS3 --> string
    {NIM(P) memberikan KodeMatkul MHS3 dari P}

Nama: MHS3 --> string
    {Nama(P) memberikan NamaMatkul MHS3 dari P}

DEFINISI DAN SPESIFIKASI KONSTRUKTOR
MakeTanggal: integer[1..31], integer[1..12], integer > 0 --> TGL
    {MakeTanggal(d, m, y) membentuk sebuah type bentukan tanggal lahir dengan d adalah tanggal, m adalah bulan, dan y adalah tahun} 

MakeMHS1: 2 string, Tanggal --> MHS1
    {MakeMHS1(NIM, Nama, Lahir) membentuk sebuah type bentukan informasi dasar dengan NIM, Nama, dan tanggal lahir mahasiswa} 

MakeMHS2: 2 string, integer --> MHS2
    {MakeMHS2(NIM,KodeMatkul, Nilai) membentuk sebuah type bentukan informasi nilai dengan NIM, Kode Matkul, dan Nilai} 

MakeMHS3: 2 string --> MHS3
    {MakeMHS1(KodeMatkul, NamaMatkul) membentuk sebuah type bentukan informasi matkul dengan Kode Matkul dan Nama Matkul} 
"""

# REALISASI
def MakeTanggal(d, m, y):
    return [d, m, y]

def MakeMHS1(NIM, Nama, Lahir):
    return [NIM,Nama,Lahir]

def MakeMHS2(NIM,KodeMatkul, Nilai):
    return [NIM,KodeMatkul, Nilai]

def NimMHS2(P):
    return P[0]

def KodeMatkulMhs2(P):
    return P[1]

def NilaiMhs2(P):
    return P[2]

def MakeMHS3(KodeMatkul, NamaMatkul):
    return [KodeMatkul,NamaMatkul]

def hitungRangeNilai (KE1,KE2):
    return f"{KodeMatkulMhs2(KE1)}, {max(NilaiMhs2(KE1), NilaiMhs2(KE2))}, {min(NilaiMhs2(KE1), NilaiMhs2(KE2))}, {abs(NilaiMhs2(KE2) - NilaiMhs2(KE1))}"

# APLIKASI
print(hitungRangeNilai((MakeMHS2(123,1,90)), MakeMHS2(123,1,95)))

# gak tau kak saya bingung :(