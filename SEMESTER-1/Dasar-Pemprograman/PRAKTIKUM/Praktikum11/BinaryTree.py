# Nama file : BinaryTree.py
# Deskripsi : Membuat fungsi pada binary tree
# Tanggal   : 3 Desember 2024
# Pembuat   : Muhammad Akmal Fazli Riyadi / 24060124130123


# DEFINISI TYPE
# Type PohonBiner: <A: integer, L: PohonBiner, R: PohonBiner>
# Pohon Biner terdiri dari akar yang berupa elemen, 
# L dan R adalah Pohon Biner yang merupakan sub pohon kiri dan sub pohon kanan

# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# MakePB: integer, 2 PohonBiner --> PohonBiner
# {MakePB(A, L, R) membuat Pohon Biner yang terdiri dari akar yang berupa elemen, 
# L dan R adalah Pohon Biner yang merupakan sub pohon kiri dan sub pohon kanan}

# REALISASI
def MakePB(A, L, R):
    return [A, L, R]


# DEFINISI DAN SPESIFIKASI SELEKTOR
# Akar: PohonBiner --> integer
# {Akar(P) mengembalikan akar dari sebuah PohonBiner}

# Left: PohonBiner --> PohonBiner
# {Left(P) mengembalikan subpohon kiri dari sebuah PohonBiner}

# Right: PohonBiner --> PohonBiner
# {Right(P) mengembalikan subpohon kanan dari sebuah PohonBiner}

# REALISASI
def Akar(P):
    return P[0] 

def Left(P):
    return P[1] 

def Right(P):
    return P[2] 


# DEFINISI DAN SPESIFIKASI PREDIKAT TERHADAP POHON BINER
# IsBiner : PohonBiner --> boolean
# {IsBiner(P) bernilai benar jika pohon biner P memiliki anak kanan dan kiri.}

# IsUnerLeft : PohonBiner --> boolean
# {IsUnerLeft(P) bernilai benar jika pohon biner P hanya memiliki anak kiri.}

# IsUnerRight : PohonBiner --> boolean
# {IsUnerRight(P) bernilai benar jika pohon biner hanya memiliki anak kanan.}

# IsTreeEmpty : PohonBiner --> boolean
# {IsTreeEmpty(P) bernilai benar jika pohon biner P kosong.}

# IsOneElmt : PohonBiner --> boolean
# {IsOneElmt(P) bernilai benar jika pohon biner hanya berupa akar, tidak memiliki anak kanan dan kiri.}

# REALISASI
def IsTreeEmpty(T):
    return T == []

def IsOneElmt(T):
    return not IsTreeEmpty(T) and IsTreeEmpty(Left(T)) and IsTreeEmpty(Right(T))

def IsBiner(P) :
    return not IsTreeEmpty(P) and not IsTreeEmpty(Left(P)) and not IsTreeEmpty(Right(P))

def IsUnerLeft(P) :
    return not IsTreeEmpty(P) and not IsTreeEmpty(Left(P)) and IsTreeEmpty(Right(P))

def IsUnerRight(P) :
    return not IsTreeEmpty(P) and IsTreeEmpty(Left(P)) and not IsTreeEmpty(Right(P))


# DEFINISI DAN SPESIFIKASI FUNGSI OPERATOR TERHADAP POHON BINER
# NbElmt: PohonBiner --> integer
# {NbElmt(P) mengembalikan jumlah elemen dalam P

# NbDaun: PohonBiner --> integer
# {NbDaun(P) mengembalikan jumlah daun dalam P}

# NbDaun1: PohonBiner --> integer
# {NbDaun1(P) mengembalikan jumlah daun dalam P dengan rekursif}

# IsMember: PohonBiner, elemen --> boolean
# {IsMember(P, X) mengembalikan True jika X adalah elemen dalam P, False otherwise}

# IsSkewLeft: PohonBiner --> boolean
# {IsSkewLeft(P) mengembalikan True jika P adalah pohon skew kiri, False otherwise}

# IsSkewRight: PohonBiner --> boolean
# {IsSkewRight(P) mengembalikan True jika P adalah pohon skew kanan, False otherwise}

# max2: integer, integer --> integer
# {max2(a, b) mengembalikan nilai maksimum antara a dan b}

# Level: PohonBiner, elemen, integer --> integer
# {Level(P, X, lvl) mengembalikan level dari elemen X dalam P}

# LevelOfX: PohonBiner, elemen --> integer
# {LevelOfX(P, X) mengembalikan level dari elemen X dalam P}

# AddDaunTerkiri: PohonBiner, elemen --> PohonBiner
# {AddDaunTerkiri(P, X) menambahkan elemen X sebagai daun terakhir dalam P}

# AddDaun: PohonBiner, elemen, elemen, boolean --> PohonBiner
# {AddDaun(P, X, Y, Kiri) menambahkan elemen Y sebagai anak kiri atau kanan dari elemen X dalam P}

# DelDaunTerkiri: PohonBiner --> PohonBiner
# {DelDaunTerkiri(P) menghapus daun terakhir dalam P}

# DelDaun: PohonBiner, elemen --> PohonBiner
# {DelDaun(P, X) menghapus elemen X dalam P}

# MakeListDaun: PohonBiner --> list
# {MakeListDaun(P) mengembalikan list daun dalam P}

# MakeListPreOrder: PohonBiner --> list
# {MakeListPreOrder(P) mengembalikan list elemen dalam P dengan traversal pre-order}

# MakeListPostOrder: PohonBiner --> list
# {MakeListPostOrder(P) mengembalikan list elemen dalam P dengan traversal post-order}

# MakeListInOrder: PohonBiner --> list
# {MakeListInOrder(P) mengembalikan list elemen dalam P dengan traversal in-order}

# MakeListLevel: PohonBiner, integer --> list
# {MakeListLevel(P, N) mengembalikan list elemen dalam P pada level N}

# Left: PohonBiner --> PohonBiner
# {Left(P) mengembalikan subpohon kiri dari P}

# Right: PohonBiner --> PohonBiner
# {Right(P) mengembalikan subpohon kanan dari P}

# Akar: PohonBiner --> elemen
# {Akar(P) mengembalikan elemen akar dari P}

# MakePB: elemen, PohonB ```python
# {MakePB(X, L, R) mengembalikan pohon biner baru dengan elemen X sebagai akar, L sebagai subpohon kiri, dan R sebagai subpohon kanan}

# REALISASI
def NbElmt(P) :
    if IsTreeEmpty(P) :
        return 0
    else :
        return NbElmt(Left(P)) + 1 + NbElmt(Right(P))

def NbElmt1(P):
    if IsTreeEmpty(P):
        return 0
    elif IsOneElmt(P):
        return 1
    else:
        return 1 + NbElmt1(Left(P)) + NbElmt1(Right(P))

def NbDaun(P) :
    if IsTreeEmpty(P) :
        return 0
    else :
        return NbDaun1(P)

def NbDaun1(P):
    if IsOneElmt(P) :
        return 1
    else :
        if (IsBiner(P)) :
            return NbDaun1(Left(P)) + NbDaun1(Right(P))
        
        elif (IsUnerLeft(P)) :
            return NbDaun1(Left(P))
        
        elif (IsUnerRight(P)) :
            return NbDaun1(Right(P))


def NbElmt(P) :
    if IsTreeEmpty(P) :
        return 0
    elif IsOneElmt(P) :
        return 1
    else :
        return 1 + NbElmt(Left(P)) + NbElmt(Right(P))
    
#        POHON        LEVEL
#          K           1
#      J       I       2
#   -    R   Q  -      3
#      D  -            4
#     W -              5
#   -  -

def RepPrefix(P):
    if IsOneElmt(P):  
        return [Akar(P)]  
    else:
        if IsBiner(P):  
            return [Akar(P), RepPrefix(Left(P)), RepPrefix(Right(P))]
        elif IsUnerLeft(P):  
            return [Akar(P), RepPrefix(Left(P)), []]
        elif IsUnerRight(P):  
            return [Akar(P), [], RepPrefix(Right(P))]


def IsMember(P, X) :
    if IsTreeEmpty(P)  :
        return False
    elif Akar(P) == X :
        return True
    else :
        return IsMember(Left(P), X) or IsMember(Right(P),X)


def IsSkewLeft(P):
    if IsTreeEmpty(P):
        return False
    elif IsOneElmt(P):
        return True
    elif IsUnerLeft(P):
        return IsSkewLeft(Left(P))
    else:
        return False


def IsSkewRight(P):
    if IsTreeEmpty(P):
        return False
    elif IsOneElmt(P):
        return True
    elif IsUnerRight(P):
        return IsSkewRight(Right(P))
    else:
        return False

#        POHON        LEVEL
#          K           1
#      J       I       2
#   -    R   Q  -      3
#      D  -            4
#     W -              5
#   -  -

def max2(a,b) :
    if a < b :
        return b
    else :
        return a
    
def Level(P,X,lvl):
    if IsTreeEmpty(P):
        return 0
    elif Akar(P) == X:
        return lvl
    else:
        return max2(Level(Left(P),X,lvl+1),Level(Right(P),X,lvl + 1))

def LevelOfX(P,X):
    if IsTreeEmpty(P):
        return 0
    elif Akar(P) == X :
        return 0
    else:
        return Level(P,X,0)
    

def AddDaunTerkiri(P,X):
    if IsTreeEmpty(P):
        return MakePB(X,[],[])
    elif IsUnerRight(P):
        return MakePB(Akar(P),Left(P),AddDaunTerkiri(Right(P),X))
    else:
        return MakePB(Akar(P),AddDaunTerkiri(Left(P),X),Right(P))


def AddDaun(P,X,Y,Kiri):
    if IsTreeEmpty(P):
        return P
    elif Akar(P) == X:
        if Kiri:
            return MakePB(Akar(P),MakePB(Y,[],[]),Right(P))
        else:
            return MakePB(Akar(P),Left(P),MakePB(Y,[],[]))
    else:
        return MakePB(Akar(P),AddDaun(Left(P),X,Y,Kiri),AddDaun(Right(P),X,Y,Kiri))


def DelDaunTerkiri(P):
    if IsOneElmt(P):
        return []
    elif IsUnerRight(P):
        return MakePB(Akar(P),Left(P),DelDaunTerkiri(Right(P)))
    else:
        return MakePB(Akar(P),DelDaunTerkiri(Left(P)),Right(P))


def DelDaun(P,X):
    if IsTreeEmpty(P):
        return []
    elif Akar(P) == X:
        return []
    else:
        return MakePB(Akar(P),DelDaun(Left(P),X),DelDaun(Right(P),X))


def MakeListDaun(P):
    if IsTreeEmpty(P):
        return []
    elif IsOneElmt(P):
        return [Akar(P)]
    elif IsUnerLeft(P):
        return MakeListDaun(Left(P))
    elif IsUnerRight(P):
        return MakeListDaun(Right(P))
    else:
        return MakeListDaun(Left(P)) + MakeListDaun(Right(P))


def MakeListPreOrder(P):
    if IsTreeEmpty(P):
        return []
    elif IsOneElmt(P):
        return [Akar(P)]
    else:
        return [Akar(P)] + MakeListPreOrder(Left(P)) + MakeListPreOrder(Right(P))


def MakeListPostOrder(P):
    if IsTreeEmpty(P):
        return []
    elif IsOneElmt(P):
        return [Akar(P)]
    else:
        return MakeListPreOrder(Left(P)) + MakeListPreOrder(Right(P)) + [Akar(P)]


def MakeListInOrder(P):
    if IsTreeEmpty(P):
        return []
    elif IsOneElmt(P):
        return [Akar(P)]
    else:
        return MakeListPreOrder(Left(P)) + [Akar(P)] + MakeListPreOrder(Right(P))


def MakeListLevel(P,N):
    if IsTreeEmpty(P):
        return []
    elif N == 0:
        return [Akar(P)]
    else:
        return MakeListLevel(Left(P),N-1) + MakeListLevel(Right(P),N-1)


# APLIKASI
BinaryTree = MakePB('K',
              MakePB('J', [], MakePB('R', MakePB('D', MakePB('W', [], MakePB('X', [], [])), []), [])),
              MakePB('I', MakePB('Q', [], []), []))
print(f"BinaryTree = {BinaryTree}") # --> 2
print(f"NbDaun(BinaryTree) = {NbDaun(BinaryTree)}") # --> 2
print(f"NbElmt1(BinaryTree) = {NbElmt1(BinaryTree)}") # --> 8
print(f"RepPrefix(BinaryTree) = {RepPrefix(BinaryTree)}") # --> ['K', ['J', [], ['R', ['D', ['W', [], ['X']], []], []]], ['I', ['Q'], []]]
print(f"IsMember(BinaryTree, 'I') = {IsMember(BinaryTree, 'I')}") # --> True
print(f"IsSkewLeft(BinaryTree) = {IsSkewLeft(BinaryTree)}") # --> False
print(f"IsSkewRight(BinaryTree) = {IsSkewRight(BinaryTree)}") # --> False
print(f"LevelOfX(BinaryTree, 'I') = {LevelOfX(BinaryTree, 'I')}") # --> 1
print(f"AddDaunTerkiri(BinaryTree, 'F') = {AddDaunTerkiri(BinaryTree, 'F')}") # --> ['K', ['J', [], ['R', ['D', ['W', [], ['X', ['F', [], []], []]], []], []]], ['I', ['Q', [], []], []]]
print(f"AddDaun(BinaryTree, 'K', 'F', True) = {AddDaun(BinaryTree, 'K', 'F', True)}") # --> ['K', ['F', [], []], ['I', ['Q', [], []], []]]
print(f"DelDaunTerkiri(BinaryTree) = {DelDaunTerkiri(BinaryTree)}") # --> ['K', ['J', [], ['R', ['D', ['W', [], []], []], []]], ['I', ['Q', [], []], []]]
print(f"DelDaun(BinaryTree, 'W') = {DelDaun(BinaryTree, 'W')}") # --> ['K', ['J', [], ['R', ['D', [], []], []]], ['I', ['Q', [], []], []]]
print(f"MakeListDaun(BinaryTree) = {MakeListDaun(BinaryTree)}") # --> ['X', 'Q']
print(f"MakeListPreOrder(BinaryTree) = {MakeListPreOrder(BinaryTree)}") # --> ['K', 'J', 'R', 'D', 'W', 'X', 'I', 'Q']
print(f"MakeListPostOrder(BinaryTree) = {MakeListPostOrder(BinaryTree)}") # --> ['J', 'R', 'D', 'W', 'X', 'I', 'Q', 'K']
print(f"MakeListInOrder(BinaryTree) = {MakeListInOrder(BinaryTree)}") # --> ['J', 'R', 'D', 'W', 'X', 'K', 'I', 'Q']
print(f"MakeListLevel(BinaryTree, 2) = {MakeListLevel(BinaryTree, 2)}") # --> ['R', 'Q']
