from bahan_list import *

def min2(a,b):
    if a > b:
        return b
    else:
        return a

def max_list(L1):
    if IsEmpty(L1):
        return 0
    else:
        # return max2(FirstElmt(L1),max_list(Tail(L1)))
        if FirstElmt(L1) > max_list(Tail(L1)):
            return FirstElmt(L1)
        else:
            return max_list(Tail(L1))

def min_list(L1):
    if IsEmpty(L1):
        return 0
    else:
        return min2(FirstElmt(L1),min_list(Tail(L1)))
    
L1 = [19,21,25,11,14,-13,10,-19,10]
print(max_list(L1))
print(min_list(L1))