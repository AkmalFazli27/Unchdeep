# Nama file : treeNaire.py
# Deskripsi : Membuat fungsi pada tree n aire
# Tanggal   : 3 Desember 2024
# Pembuat   : Muhammad Akmal Fazli Riyadi / 24060124130123
from lol_24060124130123 import *

#DEFINISI DAN SPESIFIKASI KONSTRUKTOR 
def makePN(A,PN):
    return [A,PN]

#DEFINISI DAN SPESIFIKASI SELEKTOR
#Akar: PohonN-ner tidak kosong → Elemen 
#   {Akar(P) adalah Akar dari P. Jika P adalah (A, PN) Akar(P) adalah A}  
def Akar(PN):
    return PN[0]
#Anak: PohonN-ner tidak kosong → List of PohonN-ner 
#   {Anak(P) adalah list of pphon N-ner yang merupakan anak-anak (sub phon) dari P. Jika P adalah (A, PN) Anak (P) adalah PN} 
def Anak(PN):
    return PN[1]

#DEFINISI DAN SPESIFIKASI PREDIKAT
#IsTreeNEmpty PohonN-ner → boolean 26 
#   {IsTreeNEmpty (PN) true jika PN kosong: ()} 
def IsTreeNEmpty (PN): 
    return PN == []

#IsOneElmt: PohonN-ner → boolean 
#   {IsOneElmt(PN) true jika PN hanya terdiri dari Akar} 
def IsOneElmt (PN): 
    return (IsTreeNEmpty (PN) == False) and (IsTreeNEmpty (Anak (PN)) == True)

#NbNELmt: PohonN-ner integer >= 0 
#   {NbNELmt(P) memberikan banyaknya node dari pohon P: 
# Basis 1: NbNELmt ((A)\) = 1 
# Rekurens: NbNELmt ((A,PN)) = 1 + NbELmt(PN) } 
def NbNElmt(PN): 
    # Basis: Jika pohon kosong 
    if IsTreeNEmpty (PN): 
        return 0 
    
    # Jika hanya ada satu elemen (akar saja) 
    if IsOneElmt(PN): 
        return 1 
    
    # Hitung 1 untuk akar, dan rekursif pada setiap anak pohon 
    # Tanpa menggunakan Loop, kita memanggil fungsi untuk setiap anak secara rekursif 
    # Pertama pada anak pertama 
    return 1 + NbNElmt (Anak(PN) [0]) + NbNElmtChild(Anak(PN) [1:])

# Fungsi tambahan untuk menghitung jumlah elemen pada sisa anak-anak
def NbNElmtChild(PN):
    # Basis: Jika tidak ada anak
    if IsTreeNEmpty(PN):
        return 0

    # Jika ada anak, rekursif pada anak pertama dan sisa anak-anak
    return NbNElmt(PN[0]) + NbNElmtChild(PN[1:])

def NbNDaun(PN):
    # Basis: Jika pohon kosong
    if IsTreeNEmpty(PN):
        return 0

    # Jika pohon adalah daun (anak kosong)
    if IsOneElmt(PN) and IsTreeNEmpty(Anak(PN)):
        return 1

    # Rekursi pada akar dan anak-anak
    return NbNDaunChild(Anak(PN))

# Fungsi tambahan untuk menghitung jumlah daun pada sisa anak-anak
def NbNDaunChild(PN):
    # Basis: Jika tidak ada anak
    if IsTreeNEmpty(PN):
        return 0

    # Jika ada anak, rekursif pada anak pertama dan sisa anak-anak
    return NbNDaun(PN[0]) + NbNDaunChild(PN[1:])

# APLIKASI
T = makePN(
    "A",
    [
        makePN("B", []),
        makePN("D", [makePN("J",[])])
        # makePN("E", []),
        # makePN("F", []),
    ],
)
print(f"Tree = {T}")
print(f"NbNElmt(T) = {NbNElmt(T)}")
print(f"NbNDaun(T) = {NbNDaun(T)}")