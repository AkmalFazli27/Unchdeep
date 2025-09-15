from bahan_list import *


T = MakeBST(50,
        MakeBST(17,
                MakeBST(12,
                        # MakeBST(9,[],[]),
                        # MakeBST(14,[],[])),
                        [],[]),
                MakeBST(23,
                        # MakeBST(19,[],[]),
                        [],[])),
        # [],
        MakeBST(72,
                MakeBST(54,[],
                        # MakeBST(67,[],[])),
                        []),
                MakeBST(76,[],[]))
        # []
    )

print(T)

Bagi4 = lambda x : x % 4 == 0
def IsMaxBST4(P,Bagi4):
    if IsEmpty(P):
        return False
    if IsEmpty(Right(P)):
        return Bagi4(Akar(P))
    if IsUnerLeft(P):
        return Bagi4(Akar(P))
    else:
        return IsMaxBST4(Right(P),Bagi4)
       
print(IsMaxBST4(T,Bagi4))

