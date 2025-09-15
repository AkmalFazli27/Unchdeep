from math import sqrt

def MakePoint(x,y):
    return [x,y]

def Absis(P):
    return P[0] 

def Ordinat(P):
    return P[1]

def MakeSquare(P1,P2):
    return [P1,P2]

def TopPoint(S):
    return S[0] 

def BottomPoint(S):
    return S[1]

def GetPanjang(S):
    return (Absis(TopPoint(S)) - Absis(BottomPoint(S))) 

def GetLebar(S):
    return (Ordinat(TopPoint(S)) - Ordinat(BottomPoint(S))) 

def GetDiagonal(S):
    return sqrt(GetPanjang(S)**2 + GetLebar(S)**2)

def GetLuas(S):
    return GetPanjang(S) * GetLebar(S)

print(
    GetPanjang(
        MakeSquare(
        MakePoint(3,2),
        MakePoint(-2,-1)
        )
    )
)

print(
    GetLebar(
        MakeSquare(
        MakePoint(3,2),
        MakePoint(-2,-1)
        )
    )
)

print(
    GetDiagonal(
        MakeSquare(
        MakePoint(3,2),
        MakePoint(-2,-1)
        )
    )
)

print(
    GetLuas(
        MakeSquare(
        MakePoint(3,2),
        MakePoint(-2,-1)
        )
    )
)