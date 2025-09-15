from bahan_list import *
def Max2(a,b):
    if a >= b:
        return a
    else:
        return b
    
def Max(S):
    # if IsEmpty(S):
    #     return 0
    if IsOneElmt(S):
        if IsAtom(FirstList(S)):
            return FirstList(S)
        return Max(FirstList(S))
    else:
        if IsAtom(FirstList(S)):
            return Max2(FirstList(S),Max(TailList(S)))
        return Max2(Max(FirstList(S)),Max(TailList(S)))


# APLIKASI
print(Max([0,[6,7],[4,2,3],1]))
print(Max([50,[24,102],190,[200]]))