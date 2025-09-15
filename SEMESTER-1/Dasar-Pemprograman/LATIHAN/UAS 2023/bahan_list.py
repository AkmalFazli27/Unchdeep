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

def Anak(PN):
    return PN[1]

def IsTreeNEmpty (PN): 
    return PN == []

def IsOneElmtP (PN): 
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

def IsMember(X,L):
    if IsEmpty(L):
        return False
    if X == FirstElmt(L):
        return True
    return IsMember(X,Tail(L))

def IsSubset(H1,H2):
    if IsEmpty(H1):
        return True
    else:
        if IsMember(FirstElmt(H1),H2):
            return IsSubset(Tail(H1),H2)
        return False
    
def MakeBST(A,L,R):
    return [A,L,R]

def Akar(P):
    return P[0]

def Left(P):
    return P[1]

def Right(P):
    return P[2]

def IsTreeEmpty(P):
    return P == []

def IsOneElmtBST(T):
    return not IsTreeEmpty(T) and IsTreeEmpty(Left(T)) and IsTreeEmpty(Right(T))

def IsBiner(P) :
    return not IsTreeEmpty(P) and not IsTreeEmpty(Left(P)) and not IsTreeEmpty(Right(P))

def IsUnerLeft(P) :
    return not IsTreeEmpty(P) and not IsTreeEmpty(Left(P)) and IsTreeEmpty(Right(P))

def IsUnerRight(P) :
    return not IsTreeEmpty(P) and IsTreeEmpty(Left(P)) and not IsTreeEmpty(Right(P))

def FirstElmt(P):
    return P[0]

def Tail(P):
    return P[1:]

