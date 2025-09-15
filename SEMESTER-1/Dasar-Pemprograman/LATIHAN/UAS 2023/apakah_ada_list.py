from bahan_list import *

# DEFINISI DAN SPESEFIKASI
# IsContainList : List of list -> boolean
#   {IsContainList(S) mengembalikan trus jika salah satu anggota dari list of list S berupa list}

# REALISASI


# REALISASI DALAM PYTHON
def IsContainList(S):
    if IsEmpty(S):
        return False
    else:
        if IsAtom(FirstList(S)):
            return IsContainList(TailList(S))
        else:
            return True
        
# APLIKASI
print(IsContainList([6,[3,1],[28,12,9],4]))
print(IsContainList([6,3,1,28,12,9,4]))