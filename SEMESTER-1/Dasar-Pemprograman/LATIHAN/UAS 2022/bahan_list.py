def Konso(e,L):
    return [e] + L

def Konsi(e,L):
    return L + [e]

def FirstElmt(L):
    return L[0]

def LastElmt(L):
    return L[-1]

def Tail(L):
    return L[1:]

def Head(L):
    return L[:-1]

def IsEmpty(L):
    return L == []

def IsOneElmt(L):
    if IsEmpty(L):
        return False
    return Tail(L) == [] and Head(L) == []

def IsAtom(S):
    return type(S) != list

def IsList(S):
    return type(S) == list

def KonsLo(L,S):
    return [L] + S

def KonsLi(S,L):
    return S + [L]

def FirstList(S):
    return S[0]

def LastList(S):
    return S[-1]

def TailList(S):
    return S[1:]

def HeadList(S):
    return S[:-1]

def max2(a,b):
    if a >= b : return a
    return b

def makePN(A,PN):
    return [A,PN]

def makePN(A,PN):
    return [A,PN]

def Akar(PN):
    return PN[0]

def Anak(PN):
    return PN[1]

def IsTreeNEmpty (PN): 
    return PN == []

def IsOneElmtTree (PN): 
    return (IsTreeNEmpty (PN) == False) and (IsTreeNEmpty (Anak (PN)) == True)

def IsMemberS(x, S):
    if IsEmpty(S):
        return False
    else:
        if IsAtom(FirstList(S)):
            if x == FirstList(S):
                return True
            else:
                return IsMemberS(x, TailList(S))
        elif IsList(FirstList(S)):
            return IsMemberS(x, FirstList(S)) or IsMemberS(x, TailList(S))