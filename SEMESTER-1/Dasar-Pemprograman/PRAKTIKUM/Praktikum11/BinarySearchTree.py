# Nama file : BinarySearchTree.py
# Deskripsi : Membuat fungsi pada binary search tree
# Tanggal   : 3 Desember 2024
# Pembuat   : Muhammad Akmal Fazli Riyadi / 24060124130123


# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# MakeBST: PohonBiner,integer,PohonBiner --> BinarySearchTree
# {MakePB(A, L, R) membuat Pohon Biner yang terdiri dari akar yang berupa elemen, 
# L dan R adalah Pohon Biner yang merupakan sub pohon kiri dan sub pohon kanan}
def MakeBST(L,A,R):
    return [L,A,R]


# DEFIISI DAN SPESIFIKASI SELEKTOR
# Akar : BinarySearchTree --> Elemen
# {Akar(P) mengembalikan Akar dari P yang berupa elemen.}
# Left : BinarySearchTree --> BinarySearchTree
# {Left(P) mengembalikan anak kiri P yang berupa pohon biner.}
# Right : BinarySearchTree --> BinarySearchTree
# {Right(P) mengembalikan anak kanan yang berupa pohon biner.}

# REALISASI
def Akar(P):
    return P[1]

def Left(P):
    return P[0]

def Right(P):
    return P[2]


# DEFINISI DAN SPESIFIKASI PREDIKAT TERHADAP BINARY SEARCH TREE 
# IsBiner : BinarySearchTree --> boolean
# {IsBiner(P) bernilai benar jika binary search tree P memiliki anak kanan dan kiri.}
# IsUnerLeft : BinarySearchTree --> boolean
# {IsUnerLeft(P) bernilai benar jika binary search tree P hanya memiliki anak kiri.}
# IsUnerRight : BinarySearchTree --> boolean
# {IsUnerRight(P) bernilai benar jika binary search tree hanya memiliki anak kanan.}
# IsTreeEmpty : BinarySearchTree --> boolean
# {IsTreeEmpty(P) bernilai benar jika binary search tree P kosong.}
# IsOneElmt : BinarySearchTree --> boolean
# {IsOneElmt(P) bernilai benar jika binary search tree hanya berupa akar, tidak memiliki anak kanan dan kiri.}

# REALISASI
def IsTreeEmpty(P):
    return P == []

def IsOneElmt(T):
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


# DEFINISI DAN SPESIFIKASI FUNGSI OPERATOR TERHADAP BINARY SEARCH TREEE
# BSearchX : BinSearchTree, Elemen --> boolean
# {BSeacrhX(P,X) bernilai benar jika node yang bernilai X ada pada Binary Search Tree P.}
# AddX : BinSearchTree, Elemen --> BinSearchTree
# {AddX(P,X) menghasilkan sebuah pohon Binary Search Tree dengan tambahan node X. Belum ada 
# node bernilai X pada P.}
# MakeBinSearchTree : list of Elemen --> BinSearchTree
# {MakeBinSearchTree(Ls) menghasilkan sebuah Pohon Binary Search Tree yang awalnya berupa list dengan setiap elemen 
# unik}
# DelBtree : BinSearchTree, Elemen --> BinSearchTree
# {DelBtree(P,X) menghasilkan sebuah Pohon BInary Search Tree tanpa node yang bernilai X. 
# Node bernilai X pasti ada sebagai salah satu node P}

# REALISASI
def BSearchX(P,X):
    if IsTreeEmpty(P):
        return False
    elif Akar(P) == X:
        return True
    elif X < Akar(P):
        return BSearchX(Left(P),X)
    elif X > Akar(P):
        return BSearchX(Right(P),X)

def AddX(P,X):
    if IsTreeEmpty(P):
        return MakeBST([],X,[])
    elif X > Akar(P):
        return MakeBST(Left(P),Akar(P),AddX(Right(P),X))
    elif X < Akar(P):
        return MakeBST(AddX(Left(P),X),Akar(P),Right(P))
    
def MakeBinSearchTree(Ls):
    if IsTreeEmpty(Ls):
        return Ls
    else:
        return AddX(MakeBinSearchTree(Tail(Ls)),FirstElmt(Ls))

def DelBTree(P,X):
    """Menghapus X"""
    if IsTreeEmpty(P):
        return P
    if Akar(P) == X:
        return []
    
    if X < Akar(P):
        return MakeBST(DelBTree(Left(P),X),Akar(P),Right(P))
    return MakeBST(Left(P),Akar(P),DelBTree(Right(P),X))


# APLIKASI
print(MakeBST(MakeBST(MakeBST([],2,[]),3,MakeBST([],4,[])),5,MakeBST(MakeBST([],6,[]),7,MakeBST([],8,[]))))
print(f""">> BSearchX(MakeBST(MakeBST([],3,MakeBST([],4,[])),5,MakeBST(MakeBST([],6,[]),7,[])), 4))
   = {BSearchX(MakeBST(MakeBST([],3,MakeBST([],4,[])),5,MakeBST(MakeBST([],6,[]),7,[])), 4)}"""
) # --> True
print(f""">> AddX(MakeBST(MakeBST([],3,MakeBST([],4,[])),5,MakeBST(MakeBST([],6,[]),7,[])), 9)
   = {AddX(MakeBST(MakeBST([],3,MakeBST([],4,[])),5,MakeBST(MakeBST([],6,[]),7,[])), 9)}"""
) # --> [[[[], 2, []], 3, [[], 4, []]], 5, [[[], 6, []], 7, [[], 8, [[], 9, []]]]]
print(f""">> MakeBinSearchTree([2, 3, 4, 5])
   = {MakeBinSearchTree([2, 3, 4, 5])}"""
) # --> [[[[[[[[], 2, []], 3, []], 4, []], 5, []], 6, []], 7, []], 8, []]
print(f""">> DelBTree(MakeBST(MakeBST([],3,MakeBST([],4,[])),5,MakeBST(MakeBST([],6,[]),7,[])),7)
   = {DelBTree(MakeBST(MakeBST([],3,MakeBST([],4,[])),5,MakeBST(MakeBST([],6,[]),7,[])),5),7}"""
) # --> [[[[], 2, []], 3, [[], 4, []]], 5, [[[], 6, []], 7, []]]

# def makePB(A,L,R):
#     return [A,L,R]
# def MinNode(P):
#     if IsTreeEmpty(Left(P)):
#         return Akar(P)
#     else:
#         return MinNode(Left(P))
# def DelBtree(P,X):
#     if Akar(P) == X:
#         if IsBiner(P):
#             return makePB(MinNode(Right(P)),Left(P),DelBtree(Right(P),MinNode(Right(P))))
#         elif IsUnerLeft(P):
#             return makePB(Left(P),[],[])
#         elif IsUnerRight(P):
#             return makePB(Right(P),[],[])
#         elif IsOneELmt(P):
#             return []
#     elif Akar(P) > X:
#         return makePB(Akar(P),DelBtree(Left(P),X),Right(P))
#     elif Akar(P) < X:
#         return makePB(Akar(P),Left(P),DelBtree(Right(P),X))

# B

# print(DelBtree(Bst,15))
