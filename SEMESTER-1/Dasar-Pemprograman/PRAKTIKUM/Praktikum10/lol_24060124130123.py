# Nama File : lol_24060124130123.py
# Deskripsi : List of list
# Pembuat   : Muhammad Akmal Fazli Riyadi
# NIM       : 24060124130123
# Tanggal   : 16 November 2024 

from set_24060124130123 import *

# DEFINISI DAN SPESIFIKASI PREDIKAT KHUSUS UNTUK LIST OF LIST
# IsEmpty : list of list → boolean
#   {IsEmpty(S) benar jika S adalah list of list kosong}
def IsEmptyS(S):
    return S == []

# IsAtom : list of list → boolean
#   {IsAtom(S) menghasilkan true jika list adalah atom, yaitu terdiri dari sebuah atom}
def IsAtom(S):
    return type(S) != list

# IsList : list of list → boolean
#   {IsList(S) menghasilkan true  jika S adalah sebuah list (bukan atom)}
def IsList(S):
    return type(S) == list


# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# KonsLo : List, List of list → List of list
#   {KonsLo(L,S) diberikan sebuah List L dan sebuah List of List S, membentuk list baru dengan List yang diberikan sebagai elemen pertama List of list: L o S → S'}  
def KonsLo(L,S):
    return [L] + S

# KonsLi : List of list, List → List of list
#   {KonsLi (S,L) diberikan sebuah List of list S  dan sebuah list L, membentuk list baru dengan List yang diberikan sebagai elemen terakhir list of List: S • L → S'}
def KonsLi(S,L):
    return S + [L]


# DEFINISI DAN SPESIFIKASI SELEKTOR
# FirstList: List of list tidak kosong → List
#   {FirstList(S) Menghasilkan elemen pertama list, mungkin sebuah list atau atom}
def FirstList(S):
    return S[0]

# TailList : List of list tidak kosong → List of list
#   {TailList(S) Menghasilkan  "sisa" list of list S  tanpa elemen pertama list  S}
def LastList(S):
    return S[-1]

# LastList : List of list tidak kosong → List of list
#   {LastList(S) : Menghasilkan elemen terakhir list of list S, mungkin list atau atom}
def TailList(S):
    return S[1:]

# HeadList : List of list tidak kosong  →  List of list 
#   {HeadList(S) Menghasilkan "sisa" list of list tanpa elemen terakhir list}
def HeadList(S):
    return S[:-1]


# DEFINISI DAN SPESIFIKASI PREDIKAT
# IsEqS : 2 List of list → boolean
#   {IsEqS (S1,S2) true jika S1 identik dengan S2 : semua elemennya sama}         
def IsEqS(S1,S2):
    if IsEmptyS(S1) and IsEmptyS(S2):
        return True
    if IsEmptyS(S1) or IsEmptyS(S2):
        return False
    else:
        if IsAtom(FirstList(S1)) and IsAtom(FirstList(S2)):
            if FirstList(S1) == FirstList(S2):
                return IsEqS(TailList(S1),TailList(S2))
            else:
                return False
        else:
            if IsList(FirstList(S1)) and IsList(FirstList(S2)):
                return IsEqual(FirstList(S1),FirstList(S2)) and IsEqS(TailList(S1),TailList(S2))
            else:
                return False

# IsMemberLS : List, List of list → boolean
#   {IsMemberLS (L,S2) true jika L adalah anggota S}
def IsMemberLS(L,S):
    if IsEmptyS(S):
        return False
    else:
        if IsAtom(FirstList(S)):
            return IsMemberLS(L,TailList(S))
        else:
            if IsEqS(FirstList(S),L):
                return True
            else:
                return IsMemberLS(L,TailList(S))

# IsMemberS : elemen, List of list → boolean
#   {IsMemberS (A,S) true jika A adalah anggota S}
def IsMemberS(x, S):
    if IsEmptyS(S):
        return False
    else:
        if IsAtom(FirstList(S)):
            if x == FirstList(S):
                return True
            else:
                return IsMemberS(x, TailList(S))
        elif IsList(FirstList(S)):
            return IsMemberS(x, FirstList(S)) or IsMemberS(x, TailList(S))


# DEFINISI DAN SPESIFIKASI FUNGSI ANTARA
# Max2 : 2 integer → integer
#   {Max2(a,b) menghasilkan nilai maksimum a dan b}
def max2(a,b):
    if a >= b : return a
    return b


# DEFINISI DAN SPESIFIKASI OPERASI
# Rember: elemen, List of list → List of list
#   {Rember (x,S) menghapus sebuah elemen bernilai a dari semua list S}
def Rember(x,S):
    if IsEmptyS(S):
        return S
    else:
        if IsList(FirstList(S)):
            return KonsLo(Rember(x,FirstList(S)),Rember(x,TailList(S)))
        else:
            if FirstElmt(S) == x:
                return Rember(x,TailList(S))
            return KonsLo(FirstElmt(S),Rember(x,TailList(S)))

# Max : List of list tidak kosong → integer
#   {Max (S) menghasilkan nilai elemen (atom) yang maksimum dari S}
def Max(S):
    if IsOneElmt(S):
        if IsAtom(FirstList(S)):
            return FirstList(S)
        return Max(FirstList(S))
    else:
        if IsAtom(FirstList(S)):
            return max2(FirstList(S),Max(TailList(S)))
        return max2(Max(FirstList(S)),Max(TailList(S)))

# NBElmtAtom: list of list → integer
#   {NBElmtAtom(S) mengembalikan banyaknya elemen list of list S yang berupa atom}
def NBElmtAtom(S):
    if IsEmptyS(S):
        return 0
    else:
        if IsList(FirstList(S)):
            return 0 + NBElmtAtom(TailList(S))
        return 1 + NBElmtAtom(TailList(S))

# NBElmtList: list of list → integer
#   {NBElmtList(S) mengembalikan banyaknya elemen list of list S yang berupa list}
def NBElmtList(S):
    if IsEmptyS(S):
        return 0
    else:
        if IsList(FirstList(S)):
            return 1 + NBElmtList(TailList(S))
        return 0 + NBElmtList(TailList(S))    

# SumLoL: list of list → integer
#   {SumLoL(S) mengembalikan jumlah semua elemen dalam list of list S}
def SumLoL(S):
    if IsEmptyS(S):
        return 0
    else:
        if IsEmpty(FirstList(S)):
            return 0
        else:
            if IsList(FirstList(S)):
                return FirstList(FirstList(S)) + SumLoL(TailList(FirstList(S)))
            return FirstElmt(S) + SumLoL(TailList(S))

# MaxNBElmtList: list of list → integer
#   {MaxNBElmtList(S) mengembalikan banyaknya elemen list maksimum yang ada pada list of list S}
def MaxNBElmtList(S):
    if IsEmptyS(S):
        return 0
    if IsAtom(FirstList(S)):
        return MaxNBElmtList(TailList(S))
    if IsList(FirstList(S)):
        return max2(NbElmt(FirstList(S)),MaxNBElmtList(TailList(S)))

# MaxSumElmt: list of list → integer
#   {MaxSumElmt(S) mengembalikan elemen maksimum pada list of list S. Jika elemen berupa list, maka dihitung jumlahan elemen dalam list tersebut. Jika elemen atom, maka nilainya adalah elemen tersebut}
def MaxSumElmt(S):
    if IsEmptyS(S):
        return 0
    if IsAtom(FirstList(S)):
        return max2(FirstList(S),MaxSumElmt(TailList(S)))
    if IsList(FirstList(S)):
        return max2(SumElmt(FirstList(S)),MaxSumElmt(TailList(S)))
    

# APLIKASI
# print(f"KonsLo([2,3],[1,4,5]) = {KonsLo([2,3],[1,4,5])}")
# print(f"KonsLi([9],[1,2,[3,5]]) = {KonsLi([9],[1,2,[3,5]])}")
# print(f"FirstList([[1,2],4,9]) = {FirstList([[1,2],4,9])}")
# print(f"LastList([1,4,5,10]) = {LastList([1,4,5,10])}")
# print(f"HeadList([1,2,3,[6,7]]) = {HeadList([1,2,3,[6,7]])}")
# print(f"TailList([11,12,27,[15]]) = {TailList([11,12,27,[15]])}")
# print(f"IsEmptyS([[]]) = {IsEmptyS([[]])}")
# print(f"IsAtom(FirstList([3,4])) = {IsAtom(FirstList([3,4]))}")
# print(f"IsList(FirstList([3,4])) = {IsList(FirstList([3,4]))}")
# print(f"IsEqS([2],[1,2]) = {IsEqS([2],[1,2])}")
# print(f"IsMemberLS([3,4],[[3,4],[5]]) = {IsMemberLS([3,4],[[3,4],[5]])}")
# print(f"IsMemberS(3,[1,2,3,[4]]) = {IsMemberS(3,[1,2,3,[4]])}")
# print(f"Rember(3,[1,2,3,[4,3]]) = {Rember(3,[1,2,3,[4,3]])}")
# print(f"Max([4,5,6,[8,9,10],[12,0],8]) = {Max([4,5,6,[8,9,10],[12,0],8])}")
# print(f"NBElmtAtom([4,5,6,[8,9,10],[12,0],8]) = {NBElmtAtom([4,5,6,[8,9,10],[12,0],8])}")
# print(f"NBElmtList([4,[5,6],[8,9,10],[12,0],8]) = {NBElmtList([4,[5,6],[8,9,10],[12,0],8])}")
# print(f"SumLoL([4,5,6,[2,3,1]]) = {SumLoL([4,5,6,[2,3,1]])}")
# print(f"MaxNBElmtList([[4,5,6,7],[8,9,10],[12,0],8]) = {MaxNBElmtList([[4,5,6,7],[8,9,10],[12,0],8])}")
# print(f"MaxSumElmt([[1,2],9,[4,5,6],8]) = {MaxSumElmt([[1,2],9,[4,5,6],8])}")
print(Max([50,[24,102],190,[200]]))


