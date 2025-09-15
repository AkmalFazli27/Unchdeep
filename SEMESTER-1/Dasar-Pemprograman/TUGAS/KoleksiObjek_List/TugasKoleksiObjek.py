# Nama File : TugasKoleksiObjek.py
# Deskripsi : membuat tipe bentukan point beserta konstruksi dan selektornya serta pengaplikasiannya
# Pembuat   : Muhammad Dimas Arya Putra - 24060124130062
# Tanggal   : 7 November 2023

from list_praktikum7 import *

# DEFINISI DAN SPESIFIKASI TYPE

# type Mhs : <nim:string, nama:string, kelas:character, nilai: list of integer>
#   {type Mhs terdiri atas nim, nama, dan kelas mahasiswa, serta
#   kumpulan nilai kuis yang pernah dikerjakan, dengan maksimal jumlah
#   mengerjakan adalah 10 kali. Nilai mahasiswa memiliki rentang antara
#   0-100}

# DEFINISI DAN SPESIFIKASI KONSTRUKTOR

# MakeMhs: <string, string, character, list of integer> --> Mhs
#   {MakeMhs(nim, nama, kelas, nilai) membentuk sebuah mahasiswa dengan
#   dengan nim, nama, kelas dan nilai berbentuk list of integer.
#   Contoh:
#   MakeMhs(‘234’, ‘Andi’, ‘C’, []) membentuk mahasiswa dengan nim
#   ‘234’, nama ‘Andi’ dari kelas C, dan belum pernah mengerjakan kuis
#   (nilainya berupa list kosong).

#   MakeMhs(‘123’, ‘Caca’, ‘C’, [90,80,100]) membentuk mahasiswa dengan 
#   nim ‘123’, nama ‘CC’ dari kelas C, dan telah mengerjakan kuis
#   sebanyak tiga kali dengan nilai masing-masing adalah 90, 80, dan
#   100. }
# Realisasi dalam Python
def MakeMhs(nim, nama, kelas, nilai):
    return [nim, nama, kelas, nilai]

# DEFINISI DAN SPESIFIKASI SELEKTOR
# GetNIM: Mhs --> string
# {GetNIM(M) memberikan NIM dari mahasiswa M}
# Realisasi dalam Python
def GetNIM(M):
    return M[0]

# GetNama: Mhs --> string
# {GetNama(M) memberikan Nama mahasiswa M}
# Realisasi dalam Python
def GetNama(M):
    return M[1]

# GetKelas: Mhs --> character
# {GetKelas(M) memberikan kelas mahasiswa M}
# Realisasi dalam Python
def GetKelas(M):
    return M[2]

# GetNilai: Mhs --> list of integer
# {GetNilai(M) memberikan daftar nilai mahasiswa M}
# Realisasi dalam Python
def GetNilai(M):
    return M[3]

# DEFINISI DAN SPESIFIKASI PREDIKAT

def HitungRataRataNilaiMhs(nilai):
    if IsEmpty(nilai):
        return 0
    else:
        return SumElmt(nilai) // NbElmt(nilai)

def max2(a, b):
    return ((a + b) + abs(a - b)) // 2

# BAGIAN 2

# type SetMhs : <set of Mhs>
#   {type SetMhs terdiri dari set data mahasiswa Mhs}
def SetMhs(mhs):
    if IsEmpty(mhs):
        return []
    else:
        if IsMember(GetNIM(FirstElmt(mhs)), Tail(mhs)):
            return SetMhs(Tail(mhs))
        else:
            return Konso(FirstElmt(mhs), SetMhs(Tail(mhs)))

print(SetMhs(MakeMhs("001", "Budi", "A", [88, 75, 92])))  

def SetMhsLulus(SetMhs):
    if IsEmpty(SetMhs):
        return []
    else:
        if HitungRataRataNilaiMhs(GetNilai(FirstElmt(SetMhs))) < 70:
            return SetMhsLulus(Tail(SetMhs))
        else:
            return Konso(FirstElmt(SetMhs), SetMhsLulus(Tail(SetMhs)))
        
def SetMhsTidakKuis(kelas, SetMhs):
    if IsEmpty(SetMhs):
        return []
    else:
        if kelas == GetKelas(FirstElmt(SetMhs)) and IsEmpty(FirstElmt(SetMhs)):
            return Konso(FirstElmt(SetMhs), SetMhsTidakKuis(Tail(SetMhs)))
        else:
            return SetMhsTidakKuis(kelas, Tail(SetMhs))

def NilaiTertinggi(SetMhs):
    if IsEmpty(GetNilai(FirstElmt(SetMhs))):
        return NilaiTertinggi(Tail(SetMhs))
    else:
        if IsOneElmt(SetMhs):
            return MaxElmt(GetNilai(FirstElmt(SetMhs)))
        else:
            return max2(MaxElmt(GetNilai(FirstElmt(SetMhs))), NilaiTertinggi(Tail(SetMhs)))

def NilaiTertinggiKelas(kelas, SetMhs):
    if IsEmpty(SetMhs):
        return []
    else:
        if kelas == GetKelas(FirstElmt(SetMhs)) and NilaiTertinggi(SetMhs) == MaxElmt(GetNilai(FirstElmt(SetMhs))):
            return FirstElmt(SetMhs)
        else:
            return NilaiTertinggiKelas(kelas, Tail(SetMhs))
        
def BanyakMhsTidakKuis(SetMhs):
    if IsEmpty(SetMhs):
        return 0
    else:
        if IsEmpty(GetNilai(FirstElmt(SetMhs))):
            return 1 + BanyakMhsTidakKuis(Tail(SetMhs))
        else:
            return 0 + BanyakMhsTidakKuis(Tail(SetMhs))
        
def BanyakMhsLulus(SetMhs):
    if IsEmpty(SetMhs):
        return 0
    else:
        if HitungRataRataNilaiMhs(GetNilai(FirstElmt(SetMhs))) >= 70:
            return 1 + BanyakMhsLulus(Tail(SetMhs))
        else:
            return 0 + BanyakMhsLulus(Tail(SetMhs))
        
print(
    BanyakMhsLulus(
            [
                MakeMhs("001", "Budi", "A", [88, 75, 92]),
                MakeMhs("002", "Siti", "B", [60, 58]),
                MakeMhs("003", "Agus", "A", []),
                MakeMhs("004", "Rina", "C", [85, 90, 78]),
                MakeMhs("005", "Dewi", "B", [72, 65, 80]),
                MakeMhs("006", "Toni", "A", [50, 60, 40]),
                MakeMhs("007", "Mira", "D", []),
                MakeMhs("008", "Rudi", "C", [100, 95, 90]),
                MakeMhs("009", "Linda", "D", [55, 65]),
                MakeMhs("010", "Rahmat", "A", [95, 98, 99]),
                MakeMhs("011", "Fahmi", "B", []),
                MakeMhs("123", "Kemal", "A", [90, 69, 90]),
                MakeMhs("2001", "Zaki", "E", [85, 80, 92]),
                MakeMhs("3001", "Faris", "F", [45, 55, 60]),
                MakeMhs("5001", "Alvin", "G", [92, 94, 96]),
                MakeMhs("9999", "Nina", "H", [72, 80, 88]),
            ]
        ),
    )

