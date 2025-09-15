from bahan_list import *

# DEFINISI DAN SPESIFIKASI
# FilterGenap : List -> List
#   {FilterGenap(L) adalah sebuah fungsi yang menerima list berupa integer dengan output berupa integer genap sesuai inputannya}

# REALISASI
def FilterGenap(L):
    if IsEmpty(L):
        return []
    else: 
        if FirstElmt(L) % 2 == 0:
            return Konso(FirstElmt(L),FilterGenap(Tail(L)))
        else:
            return FilterGenap(Tail(L))

# APLIKASI
print(FilterGenap([6,3,1,28,12,9,4]))