# Nama    : Muhammad Akmal Fazli Riyadi
# Tanggal : 2 Desember 2024

def FirstElmt(L):
    return L[0]

def LastElmt(L):
    return L[-1]

def Head(L):
    return L[:-1]

def Tail(L):
    return L[1:]

def Konso(e, L):
    return [e] + L

def isEmpty(L):
    return L == []

def dimensi(L): # atau NbElmt()
    if isEmpty(L):
        return 0
    else:
        return 1 + dimensi(Tail(L))
      
def DuelSihir(S,M,skorS=0,skorM=0):
    if isEmpty(S):
        if skorS > skorM:
            return "Snape Menang"
        if skorS < skorM:
            return "McGonagall Menang"
        return "Keduanya Seri"
    if FirstElmt(S) > FirstElmt(M):
        return DuelSihir(Tail(S),Tail(M),skorS + 1,skorM)
    if FirstElmt(S) < FirstElmt(M):
        return DuelSihir(Tail(S),Tail(M),skorS,skorM + 1)
    return DuelSihir(Tail(S),Tail(M),skorS,skorM)
  
# PRINT
print(DuelSihir([10, 20], [15, 10]))

