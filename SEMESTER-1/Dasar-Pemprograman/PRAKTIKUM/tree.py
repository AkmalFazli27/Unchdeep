def PreMakeTree(A,PN):
    return [A,PN]

def PosMakeTree(PN,A):
    return [PN,A]

def Akar(T):
    return T[1]

def Anak(T):
    return T[0]

def IsTreeNEmpty(PN):
    return PN == []

def IsOneElmt(PN):
    return len(PN) == 1 or PN == []

def NbNElmt()

T = PosMakeTree([[],2],2)
Tx = [[3,2],2]

print(T)
print(Tx)
print(IsTreeNEmpty(Anak(Anak(T))))
print(IsTreeNEmpty(Anak(Anak(T))))
