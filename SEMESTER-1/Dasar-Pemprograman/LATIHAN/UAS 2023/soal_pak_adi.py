from bahan_list import *
T = MakeBST(50,
        MakeBST(17,
                MakeBST(12,
                        MakeBST(9,[],[]),
                        MakeBST(14,[],[])),
                MakeBST(23,
                        MakeBST(19,[],[]),
                        [])),
        # [],
        MakeBST(72,
                MakeBST(54,[],
                        MakeBST(67,[],[])),
                MakeBST(76,[],[]))
        # []
    )

IsEven = lambda x : x % 2 == 0
IsOdd = lambda x : x % 2 != 0

def MaxGanjil(P):
    if IsEmpty(P):
        return False
    else:
        if IsEven(Akar(P)):
            return max2(0,max2(MaxGanjil(Left(P)),MaxGanjil(Right(P))))
        else:
            return max2(Akar(P),max2(MaxGanjil(Left(P)),MaxGanjil(Right(P))))

def MaxGenap(P):
    if IsEmpty(P):
        return False
    else:
        if IsOdd(Akar(P)):
            return max2(0,max2(MaxGenap(Left(P)),MaxGenap(Right(P))))
        else:
            return max2(Akar(P),max2(MaxGenap(Left(P)),MaxGenap(Right(P))))

print(MaxGanjil(T))
print(MaxGenap(T))