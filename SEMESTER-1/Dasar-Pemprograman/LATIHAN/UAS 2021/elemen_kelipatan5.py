from bahan_list import *

kelipatan = lambda a : a % 5 == 0

def Filter_List(T,f):
    if IsEmpty(T):
        return []
    else:
        if f(FirstElmt(T)):
            return Konso(FirstElmt(T),Filter_List(Tail(T),f))
        else:
            return Filter_List(Tail(T),f)

def Kelipatan5(x):
    return x % 5 == 0
        
def Bukan_Kelipatan5(x):
    return x % 5 != 0

L1 = [60,18,7,20,19,23,50]

print(Filter_List(L1,lambda x : Kelipatan5(x)))
print(Filter_List(L1,lambda x : Bukan_Kelipatan5(x)))
