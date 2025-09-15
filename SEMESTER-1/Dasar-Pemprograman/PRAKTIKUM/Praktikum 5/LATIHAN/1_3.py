from math import sqrt

def fx2 (x):
    return x**2

def MakePoint (x,y):
    return [x,y]

def absis(P):
    return P[0]

def ordinat(P):
    return P[1]

def IsOrigin (P):
    return absis(P) == 0 and ordinat(P) == 0

def jarak (P1,P2):
    return sqrt(fx2(absis(P2) - absis(P1) + fx2(ordinat(P2) - ordinat(P1))))

def jarak0 (P):
    return sqrt(fx2(absis(P)) + fx2(ordinat(P)))


# JARAK 2 TITIK
def gradien(P1,P2):
    return ((ordinat(P2) - ordinat(P1)) / (absis(P2) - absis(P1)))

def IsSejajar (P1,P2,P3,P4):
    if gradien(P1,P2) == gradien (P3,P4): return f"Garis sejajar"
    return "Garis tidak sejajar"
# ===============


# SOAL PERSEGI
def IsBujurSangkar (P1,P2,P3,P4):
    if jarak(P1,P2) == jarak (P3,P4): return "Ini bujur sangkar"
    return "Bukan bujur sangkar"

def IsJajarGenjang (P1,P2,P3,P4):
    if jarak(P1,P2) == jarak(P4,P2) and jarak(P1,P4) == jarak(P2,P3): return "Ini jajar genjang"
    return "Bukan jajar genjang woy"

def AreaBujurSangkar (P1,P2):
    return fx2(jarak(P1,P2))

print(
    IsSejajar(
        MakePoint(1,2),
        MakePoint(4,2),
        MakePoint(5,0),
        MakePoint(2,0),
    )
)

print(
    IsBujurSangkar(
        MakePoint(1,2),
        MakePoint(4,2),
        MakePoint(5,0),
        MakePoint(2,0),
    )
)

print(
    IsJajarGenjang(
        MakePoint(1,2),
        MakePoint(4,2),
        MakePoint(5,0),
        MakePoint(2,0),
    )
)

print(
    AreaBujurSangkar(
        MakePoint(1,2),
        MakePoint(4,2),
    )
)
