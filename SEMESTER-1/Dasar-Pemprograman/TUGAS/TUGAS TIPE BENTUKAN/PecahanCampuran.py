# Nama File : PecahanCampuran.py
# Deskripsi : Membuat tipe bentukan pecahan beserta konstruksi dan selektornya serta pengaplikasiannya
# NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
# Tanggal   : 21 Oktober 2024

def MakePecahanC(bil,n,d):
    return [bil,n,d]

def MakePecahan(n,d):
    return [n,d]

def Pembilang(P):
    return P[0]

def Penyebut(P):
    return P[1]

def Bilangan(P):
    return P[0]

def Nominator(P):
    return P[1]

def Denominator(P):
    return P[2]

def KaliDenominator(P1,P2):
    if Denominator(P1) != Denominator(P2) : return Denominator(P1) * Denominator(P2)
    return Denominator(P1)

def KaliNoDe(P1,P2):
    return Nominator(P1) * Denominator(P2)

def KaliPembPeny(P1,P2):
    return Pembilang(KonversiPecahan(P1)) * Penyebut(KonversiPecahan(P2))

def KaliPemb(P1, P2):
    return Pembilang(KonversiPecahan(P1)) * Pembilang(KonversiPecahan(P2))

def SimpNom(HasilOp,P1,P2):
    if abs(HasilOp) < KaliDenominator(P1,P2) : return HasilOp
    return HasilOp % KaliDenominator(P1,P2)

def SimpPemb(HasilOp,P1,P2):
    if HasilOp < abs(KaliPembPeny(P1,P2)) : return HasilOp * -1
    return HasilOp % abs(KaliPembPeny(P1,P2))

def IsEqP(P1,P2):
    return KaliPembPeny(P1,P2) == KaliPembPeny(P2,P1)

def IsLtP(P1,P2):
    return KaliPembPeny(P1,P2) < KaliPembPeny(P2,P1)

def IsGtP(P1,P2):
    return KaliPembPeny(P1,P2) > KaliPembPeny(P2,P1)

def KonversiPecahan(P):    
    if Bilangan(P) < 0 : return MakePecahan(Bilangan(P) * Denominator(P) - Nominator(P), Denominator(P))
    return MakePecahan((Denominator(P) * Bilangan(P) + Nominator(P)), Denominator(P))

def KonversiReal(P):
    return Pembilang(KonversiPecahan(P)) / Penyebut(KonversiPecahan(P))

def AddP(P1, P2):
    return MakePecahanC(
        Bilangan(P1) + Bilangan(P2) + (((KaliNoDe(P1, P2) + KaliNoDe(P2, P1)) if Denominator(P1) != Denominator(P2) else Nominator(P1) + Nominator(P2)) // KaliDenominator(P1, P2)),
        SimpNom((KaliNoDe(P1, P2) + KaliNoDe(P2, P1)), P1, P2),
        KaliDenominator(P1, P2),
    )

def SubP(P1, P2):
    return MakePecahanC(
        abs(KaliPembPeny(P1, P2) - KaliPembPeny(P2, P1)) // KaliDenominator(P1, P2),
        SimpNom((KaliPembPeny(P1, P2) - KaliPembPeny(P2, P1)), P1, P2),
        KaliDenominator(P1, P2),
    )

def DivP(P1,P2):
    return MakePecahanC(
        (KaliPembPeny(P1,P2) // KaliPembPeny(P2,P1)) + (1 if KaliPembPeny(P2,P1) < 0 else 0),
        SimpNom(KaliPembPeny(P1,P2),P1,P2),
        abs(KaliPembPeny(P2,P1))
    )

def MulP(P1,P2):
    return MakePecahanC(
        (KaliPemb(P1,P2) // KaliDenominator(P1,P2)) + (1 if KaliPemb(P1,P2) < 0 else 0),
        KaliPemb(P1,P2) % KaliDenominator(P1,P2),
        KaliDenominator(P1,P2)
    )

print(AddP(MakePecahanC(2,3,5), MakePecahanC(1,2,5)))
print(SubP(MakePecahanC(2,1,4), MakePecahanC(1,1,2)))
print(DivP(MakePecahanC(3,3,4), MakePecahanC(1,1,2)))
print(MulP(MakePecahanC(1,1,4), MakePecahanC(3,4,5)))
print(IsEqP(MakePecahanC(2,1,4), MakePecahanC(2,4,8)))
print(IsLtP(MakePecahanC(1,1,4), MakePecahanC(1,1,2)))
print(IsGtP(MakePecahanC(2,2,4), MakePecahanC(1,1,2)))

