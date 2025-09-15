from math import sqrt

def MakePoint(x,y):
    return [x,y]

def Absis(P):
    return P[0]

def Ordinat(P):
    return P[1]

def MakeGaris(P1,P2):
    return [P1,P2]

def TitikAwal(G):
    return G[0]

def TitikAkhir(G):
    return G[1]

def fx2(x):
    return x * x

def PanjangGaris(G):
    return sqrt(fx2(Absis(TitikAkhir(G)) - Absis(TitikAwal(G))) + fx2(Ordinat(TitikAkhir(G)) - Ordinat(TitikAwal(G))))

def IsKuadran3(G):
    if Absis(TitikAkhir(G)) < 0 and Absis(TitikAwal(G)) < 0 and Ordinat(TitikAwal(G)) < 0 and Ordinat(TitikAwal(G)) < 0 : return True 
    return False

print(
    IsKuadran3(
        MakeGaris((-2,-3),(-4,-5))
    )
)

print(
    PanjangGaris(
        MakeGaris((-2,-3),(-4,-5))
    )
)