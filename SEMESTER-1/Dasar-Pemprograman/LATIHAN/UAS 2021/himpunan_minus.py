from bahan_list import *

def minus(A,B):
    if IsEmpty(A):
        return []
    else:
        if IsMember(FirstElmt(A),B):
            return minus(TailList(A),B)
        else:
            return Konso(FirstElmt(A),minus(TailList(A),B))

A = [5,12,16,7,19,25,30]
B = [12,7,25]    
print(minus(A,B))