"""
Program   : TYPE GARIS
Deskripsi : Program TYPE GARIS adalah sebuah program yang berfungsi untuk memodelkan dan mengelola garis dalam bidang 2 dimensi menggunakan tipe bentukan (data structures). Program ini memungkinkan pengguna untuk membuat dan mengoperasikan garis berdasarkan titik-titik koordinat, serta menghitung berbagai sifat garis seperti panjang garis, gradien, dan apakah dua garis sejajar.
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 30/09/2024
"""

"""
DEFINISI TYPE
type point : <x: real , y: real>
    {<x,y> adalah sebuah point, dengan x  adalah absis, y adalah ordinat} 
type garis : <P1: point , P2: point>
    {<P1,P2> adalah garis direpresentasikan oleh dua titik P1 dan P2 yang berada dalam bidang dua dimensi} 

DEFINISI DAN SPESIFIKASI SELEKTOR 
Absis : point  → real
    {Absis(P) Memberikan Absis Point P} 
Ordinat : point  → real
    {Ordinat(P) Memberikan ordinat Point P} 
TitikAwal : garis → point
    {TitikAwal(G) memberikan titik awal garis G} 
TitikAkhir : garis → point
    {TitikAkhir(G) memberikan titik akhir garis G}

DEFINISI DAN SPESIFIKASI KONSTRUKTOR
MakePoint  : 2 real  → point
    {MakePoint(a,b) membentuk sebuah point dari a dan b dengan a sebagai absis dan b sebagai ordinat} 
MakeGaris  : 2 point → garis
    {MakeGaris(P1, P2) membentuk sebuah garis dengan titik awal P1 dan titik akhir P2} 

DEFINISI DAN SPESIFIKASI OPERATOR TERHADAP GARIS
PanjangGaris : garis → boolean
    {PanjangGaris(garis) menghitung panjang garis antara dua titik Absis(garis) dan Ordinat(garis) menggunakan rumus jarak Euclidean} 

DEFINISI DAN SPESIFIKASI PREDIKAT
IsSejajar? : 2 garis → boolean
    {IsSejajar(TitikAwal, TitikAkhir) mengecek apakah garis yang dibentuk oleh Absis(TitikAwal)-Ordinat(TitikAwal) dan Absis(TitikAkhir)-Ordinat(TitikAkhir) sejajar. Dua garis sejajar jika dan hanya jika gradien (kemiringan) kedua garis sama} 

DEFINISI OPERATOR/FUNGSI LAIN TERHADAP POINT
Jarak : 2 point → real 
    {Jarak(P1,P2) : menghitung jarak antara 2 point P1 dan P2} 
Gradien : garis → real
    {Gradien(G) : menghitung gradien pada 1 garis} 
 
    {Fungsi antara yang dipakai : FX2 adalah pangkat dua yang pernah didefinisikan pada least square dan SQRT(X) adalah fungsi dasar untuk menghitung akar} 
"""
# REALISASI
from math import sqrt

def MakePoint(x,y):
    return [x,y]

def MakeGaris(P1,P2):
    return [P1,P2]

def TitikAwal(G):
    return G[0]

def TitikAkhir(G):
    return G[1]

def Absis(P):
    return P[0]

def Ordinat(P):
    return P[1]

def IsOrigin(P):
    return Absis(P) == 0 and Ordinat(P) == 0

def fx2(x):
    return x*x

def Jarak(P1,P2):
    return sqrt(fx2(Absis(P2) - Absis(P1) + fx2(Ordinat(P2) - Ordinat(P1))))

def Gradien(G):
    return (Ordinat(TitikAwal(G)) - Ordinat(TitikAkhir(G))) / (Absis(TitikAwal(G)) - Absis(TitikAkhir(G)))

def IsSejajar(G1,G2):
    if Gradien(G1) == Gradien(G2): return f"Garis sejajar"
    return "Garis tidak sejajar"

# APLIKASI
print(IsSejajar((MakeGaris(MakePoint(1,2),MakePoint(4,2))),MakeGaris(MakePoint(5,0),MakePoint(2,0))))
