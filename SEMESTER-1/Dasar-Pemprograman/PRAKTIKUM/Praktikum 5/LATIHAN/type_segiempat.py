"""
Program   : TYPE SEGIEMPAT
Deskripsi : Sebuah program yang digunakan untuk melakukan berbagai operasi terhadap empat titik (point) pada bidang koordinat kartesius yang membentuk suatu segiempat. Program ini memiliki beberapa fungsi utama, IsBujurSangkar Memeriksa apakah empat titik yang diberikan membentuk bujur sangkar (semua sisi sama panjang dan sudut siku-siku). IsJajargenjang Memeriksa apakah empat titik yang diberikan membentuk jajargenjang (dua pasang sisi berlawanan sejajar dan sama panjang). AreaBujurSangkar Menghitung luas bujur sangkar yang dibentuk oleh empat titik. Jika titik-titik tersebut tidak membentuk bujur sangkar, fungsi akan mengembalikan pesan "BUKAN BUJUR SANGKAR". Fungsi-fungsi ini memanfaatkan operasi dasar pada titik-titik, seperti menghitung jarak antara dua titik dan gradien garis untuk menentukan kemiringan garis. Program ini dapat membantu pengguna memeriksa bentuk geometri berdasarkan titik-titik yang dimasukkan.
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 30/09/2024
"""

"""
DEFINISI TYPE
type point : <x: real , y: real>
    {<x,y> adalah sebuah point, dengan x  adalah absis, y adalah ordinat} 
type garis : <P1: point, P2: point>
    {<P1,P2> adalah garis direpresentasikan oleh dua titik P1 dan P2 yang berada dalam bidang dua dimensi } 
type segiempat :  <G1: garis, G2: garis, G3: garis, G4: garis>
    {<G1,G2,G3,G4> adalah sebuah segiempat direpresentasikan oleh empat garis G1, G2, G3, dan G4 yang berada dalam bidang dua dimensi} 

DEFINISI DAN SPESIFIKASI SELEKTOR
Absis : point  → real
    {Absis(P) Memberikan Absis Point P} 
Ordinat : point  → real
    {Ordinat(P) Memberikan ordinat Point P} 
TitikAwal : garis → point
    {TitikAwal(G) memberikan titik awal garis G} 
TitikAwal : garis → point
    {TitikAwal(G) memberikan titik akhir garis G} 
GarisSatuSegiempat : segiempat → garis
    {GarisSatuSegiEmpat(segiempat) memberikan garis ke satu pada bagian bawah segiempat}
GarisDuaSegiempat : segiempat → garis
    {GarisDuaSegiEmpat(segiempat) memberikan garis ke dua pada bagian kanan segiempat}
GarisTigaSegiempat : segiempat → garis
    {GarisTigaSegiEmpat(segiempat) memberikan garis ke tiga pada bagian atas segiempat}
GarisEmpatSegiempat : segiempat → garis
    {GarisEmpatSegiEmpat(segiempat) memberikan garis ke empat pada bagian kiri segiempat}

DEFINISI DAN SPESIFIKASI KONSTRUKTOR 
MakePoint : 2 real  → point
    {MakePoint(a,b) membentuk sebuah point dari a dan b dengan a sebagai absis dan b sebagai ordinat}
MakeGaris : 2 point  → garis
    {MakeGaris(P1, P2) membentuk sebuah garis dengan titik awal P1 dan titik akhir P2}
MakeSegiempat : 4 garis → segiempat
    {MakeSegiempat(G1, G2, G3, G4) membentuk sebuah segiempat dengan:
        garis kesatu G1 pada bagian bawah,  
        garis kedua G2 pada bagian kanan, 
        garis ketiga G3 pada bagian atas, 
        garis keempat G4 pada bagian kiri}

DEFINISI OPERATOR/FUNGSI LAIN TERHADAP POINT
Jarak : 2 point  →   real 
    {Jarak(P1,P2) : menghitung jarak antara 2 point P1 dan P2}
Gradien : garis → real
    {Gradien(G) : menghitung gradien pada 1 garis}
    
    {Fungsi antara yang dipakai : FX2 adalah pangkat dua yang pernah didefinisikan pada 
least square dan SQRT(X) adalah fungsi dasar untuk menghitung akar}

DEFINISI DAN SPESIFIKASI OPERATOR TERHADAP GARIS
PanjangGaris : garis → real
    {PanjangGaris(garis) menghitung panjang garis antara dua titik Absis(garis) dan Ordinat(garis) menggunakan rumus jarak Euclidean}

DEFINISI DAN SPESIFIKASI OPERATOR TERHADAP SEGIEMPAT
AreaBujurSangkar : segiempat → real
    {AreaBujurSangkar(segiempat) menghitung luas area dari bujur sangkar yang diberikan menggunakan rumus kuadrat dari panjang garis}

DEFINISI DAN SPESIFIKASI PREDIKAT
IsBujurSangkar? : segiempat → boolean
    {IsBujurSangkar(segiempat) mengecek apakah segiempat yang diberikan adalah bujur sangkat. Segiempat dikatakan bujur sangkar jika keempat sisinya sama panjang}
IsJajarGenjang? : segiempat → boolean
    {IsJajarGenjang(segiempat) mengecek apakah segiempat yang diberikan adalah jajar genjang. Segiempat dikatakan jajar genjang jika sisi-sisi yang berhadapan sama panjang dan sejajar}

DEFINISI DAN SPESIFIKASI FUNGSI TAMBAHAN
FX2 : real -> real
    {FX2(x) adalah hasil kuadrat dari x } 
"""

# REALISASI
def MakePoint(x, y):
    return [x, y]

def Absis(P):
    return P[0]

def Ordinat(P):
    return P[1]

def MakeGaris(P1, P2):
    return [P1, P2]

def TitikAwal(G):
    return G[0]

def TitikAkhir(G):
    return G[1]

def MakeSegiempat(G1, G2, G3, G4):
    return [G1, G2, G3, G4]

def GarisSatuSegiempat(S):
    return S[0]

def GarisDuaSegiempat(S):
    return S[1]

def GarisTigaSegiempat(S):
    return S[2]

def GarisEmpatSegiempat(S):
    return S[3]

def FX2(x):
    return x * x

def Jarak(P1, P2):
    return (FX2(Absis(P1) - Absis(P2)) + FX2(Ordinat(P1) - Ordinat(P2))) * 0.5

def Gradien(G):
    return (Ordinat(TitikAwal(G)) - Ordinat(TitikAkhir(G))) / (Absis(TitikAwal(G)) - Absis(TitikAkhir(G)))

def IsBujurSangkar(segiempat):
    return Jarak(
        TitikAwal(GarisSatuSegiempat(segiempat)),
        TitikAkhir(GarisSatuSegiempat(segiempat)),
    ) * Jarak(
        TitikAwal(GarisDuaSegiempat(segiempat)),
        TitikAkhir(GarisDuaSegiempat(segiempat)),
    ) == Jarak(
        TitikAwal(GarisTigaSegiempat(segiempat)),
        TitikAkhir(GarisTigaSegiempat(segiempat)),
    ) * Jarak(
        TitikAwal(GarisEmpatSegiempat(segiempat)),
        TitikAkhir(GarisEmpatSegiempat(segiempat))
    )

def IsJajargenjang(segiempat):
    return (
        Gradien(
            MakeGaris(
                TitikAwal(GarisSatuSegiempat(segiempat)),
                TitikAkhir(GarisSatuSegiempat(segiempat)),
            )
        )
        == Gradien(
            MakeGaris(
                TitikAwal(GarisTigaSegiempat(segiempat)),
                TitikAkhir(GarisTigaSegiempat(segiempat)),
            )
        )
        and Gradien(
            MakeGaris(
                TitikAwal(GarisSatuSegiempat(segiempat)),
                TitikAkhir(GarisTigaSegiempat(segiempat)),
            )
        )
        == Gradien(
            MakeGaris(
                TitikAwal(GarisDuaSegiempat(segiempat)),
                TitikAkhir(GarisDuaSegiempat(segiempat)),
            )
        )
        and Jarak(
            TitikAwal(GarisSatuSegiempat(segiempat)),
            TitikAkhir(GarisSatuSegiempat(segiempat)),
        )
        == Jarak(
            TitikAwal(GarisTigaSegiempat(segiempat)),
            TitikAkhir(GarisTigaSegiempat(segiempat)),
        )
        and Jarak(
            TitikAwal(GarisSatuSegiempat(segiempat)),
            TitikAkhir(GarisTigaSegiempat(segiempat)),
        )
        == Jarak(
            TitikAwal(GarisDuaSegiempat(segiempat)),
            TitikAkhir(GarisDuaSegiempat(segiempat)),
        )
    )

def AreaBujurSangkar(segiempat):
    return FX2(Jarak(TitikAwal(GarisSatuSegiempat(segiempat)),TitikAkhir(GarisSatuSegiempat(segiempat))))

# APLIKASI
print(
    f"IsJajargenjang: <1,1>, <4,1>, <5,3>, <2,3> -> {
        IsJajargenjang(
            MakeSegiempat(
                MakeGaris(MakePoint(1, 1), MakePoint(4, 1)),
                MakeGaris(MakePoint(4, 1), MakePoint(5, 3)),
                MakeGaris(MakePoint(5, 3), MakePoint(2, 3)),
                MakeGaris(MakePoint(2, 3), MakePoint(1, 1))
            )
        )
    }"
)

print(
    f"IsBujurSangkar: <2,1>, <4,1>, <4,3>, <2,3> -> {
        IsBujurSangkar(
            MakeSegiempat(
                MakeGaris(MakePoint(2, 1), MakePoint(4, 1)), 
                MakeGaris(MakePoint(4, 1), MakePoint(4, 3)), 
                MakeGaris(MakePoint(4, 3), MakePoint(2, 3)), 
                MakeGaris(MakePoint(2, 3), MakePoint(2, 1))
             )
        )
    }"
)

print(
    f"AreaBujurSangkar: <2,1>, <4,1>, <4,3>, <2,3> -> {
        AreaBujurSangkar(
            MakeSegiempat(
                MakeGaris(MakePoint(2, 1), MakePoint(4, 1)), 
                MakeGaris(MakePoint(4, 1), MakePoint(4, 3)), 
                MakeGaris(MakePoint(4, 3), MakePoint(2, 3)), 
                MakeGaris(MakePoint(2, 3), MakePoint(2, 1))
            )
            )
    }"
)