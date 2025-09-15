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

def IsOneElmtP(T):
    return not IsTreeEmpty(T) and IsTreeEmpty(Left(T)) and IsTreeEmpty(Right(T))

def max2(a, b) :
    if a > b : 
        return a
    else : 
        return b

def IsUnerLeft(T) :
    return (not IsTreeEmpty(Left(T))) and (IsTreeEmpty(Right(T)))

def IsUnerRight(P) :
    return not IsTreeEmpty(P) and IsTreeEmpty(Left(P)) and not IsTreeEmpty(Right(P))

def IsBiner(T) :
    return (not IsTreeEmpty(Left(T))) and (not IsTreeEmpty(Right(T)))

T = MakeBST(50,
        MakeBST(17,
                MakeBST(12,
                        MakeBST(9,[],[]),
                        MakeBST(14,[],[])),
                MakeBST(23,
                        MakeBST(19,[],[]),
                        [])),
        MakeBST(72,
                MakeBST(54,[],
                        MakeBST(67,[],[])),
                MakeBST(76,[],[]))
    )
print(T)


def total_elemen_daun(P):
    if IsTreeEmpty(P):
        return 0
    if IsOneElmtP(P):
        return Akar(P)
    else:
        return total_elemen_daun(Left(P)) + total_elemen_daun(Right(P))

def max_elemen_daun(P):
    if IsTreeEmpty(P):
        return 0
    if IsOneElmtP(P):
        return Akar(P)
    else:
        return max2(max_elemen_daun(Left(P)),max_elemen_daun(Right(P)))

def total_elemen_node(P):
    if IsTreeEmpty(P):
        return 0
    if IsOneElmtP(P):
        return Akar(P)
    else:
        return Akar(P) + total_elemen_node(Left(P)) + total_elemen_node(Right(P))

def nb_node(P):
    if IsTreeEmpty(P):
        return 0
    if IsOneElmtP(P):
        return 1
    else:
        return 1 + nb_node(Left(P)) + nb_node(Right(P))

def rata2_elemen_daun(P):
    if IsTreeEmpty(P):
        return 0
    if IsOneElmtP(P):
        return Akar(P)
    else:
        return total_elemen_node(P) / nb_node(P)

def BST(x,P):
    if IsTreeEmpty(P):
        return False
    elif Akar(P) == x:
        return True
    elif x < Akar(P):
        return BST(x,Left(P))
    elif x > Akar(P):
        return BST(x,Right(P))


print(total_elemen_daun(T))
print(max_elemen_daun(T))
print(total_elemen_node(T))
print(rata2_elemen_daun(T))
print(BST(19,T))
