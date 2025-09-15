# Nama File  : TipeGaris.py
# Deskripsi  : Program TYPE GARIS adalah sebuah program yang berfungsi untuk memodelkan dan mengelola garis dalam bidang 2 dimensi menggunakan tipe bentukan (data structures). Program ini memungkinkan pengguna untuk membuat dan mengoperasikan garis berdasarkan titik-titik koordinat, serta menghitung berbagai sifat garis seperti panjang garis, gradien, dan apakah dua garis sejajar.
# NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
# Tanggal   : 21/10/2024

from math import sqrt

def MakePoint(x,y):
    return [x,y]

def MakeGaris(P1,P2):
    return [P1,P2]

def StartP(G):
    return G[0]

def EndP(G):
    return G[1]

def Absis(P):
    return P[0]

def Ordinat(P):
    return P[1]

def fx2(x):
    return x*x

def Jarak(P1,P2):
    return sqrt(fx2(Absis(P2) - Absis(P1)) + (fx2(Ordinat(P2) - Ordinat(P1))))

def PanjangGaris(G):
    return Jarak(StartP(G),EndP(G))

def Gradien(G):
    return (Ordinat(StartP(G)) - Ordinat(EndP(G))) / (Absis(StartP(G)) - Absis(EndP(G)))

def IsSejajar(G1,G2):
    if Gradien(G1) == Gradien(G2) : return f"Garis sejajar"
    return "Garis tidak sejajar"

def IsTegakLurus(G1,G2):
    if Gradien(G1) * Gradien(G2) == -1 : return f"Garis tegak lurus"
    return "Garis tidak tegak lurus"


print(PanjangGaris((MakeGaris(MakePoint(1,2),MakePoint(4,6)))))
print(Gradien((MakeGaris(MakePoint(1,1),MakePoint(4,4)))))
print(IsSejajar((MakeGaris(MakePoint(1,2),MakePoint(4,2))),MakeGaris(MakePoint(5,0),MakePoint(2,0))))
print(IsTegakLurus((MakeGaris(MakePoint(0,1),MakePoint(2,5))),MakeGaris(MakePoint(0,5),MakePoint(4,3))))
