"""
File Name : set_24060124130123.py
Deskripsi : Berisi type dan operasi set
Pembuat   : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal   : 5 November 2024
"""


# DEFINISI DAN SPESIFIKASI TYPE
# Set adalah sebuah list dengan syarat setiap elemen harus unik.
# Semua konsruktor, selektor, dan operasi yang telah didefinisikan untuk list juga berlaku pada set.


from list_praktikum7 import *


# DEFINISI DAN SPESIFIKASI OPERASI LIST YANG DIPERLUKAN UNTUK HIMPUNAN
# Rember1: elemen, list -> list
# Rember1(x,L) menghapus sebuah elemen x yang ditemui pertama kali dari list L
# Jika x ada di list L, maka elemen L berkurang 1.
# Jika x tidak ada di list L maka L tetap.
# List kosong tetap menjadi list kosong.

def Rember1(X,L):
    if IsEmpty(L):
        return []
    else:
        if FirstElmt(L) == X:
            return Tail(L)
        return Konso(FirstElmt(L),Rember1(X,Tail(L)))
# print(f"Rember1(2,[1,2,3,3,2]) = {Rember1(2,[1,2,3,3,2])}")
    
# Rember2: elemen, list -> list
# Rember2(x,L) menghapus sebuah elemen x yang ditemui terakhir kali dari list L
# Jika x ada di list L, maka elemen L berkurang 1.
# Jika x tidak ada di list L maka L tetap.
# List kosong tetap menjadi list kosong.
def Rember2(X,L):
    if IsEmpty(L):
        return []
    else:
        if LastElmt(L) == X:
            return Head(L)
        return Konsi(LastElmt(L),Rember2(X,Head(L)))
# print(f"Rember2(2,[1,2,3,3,2]) = {Rember2(2,[1,2,3,3,2])}")

# MultiRember: elemen, list -> list
# MultiRember(x,L) menghapus semua kemunculan elemen x dari list L.
# List baru yang dihasilkan tidak lagi memiliki elemen x.
# List kosong tetap menjadi list kosong.
def MultiRember(X,L):
    if IsEmpty(L):
        return []
    else:
        if X == FirstElmt(L):
            return MultiRember(X,Tail(L))
        return Konso(FirstElmt(L),MultiRember(X,Tail(L)))
# print(f"MultiRember(2,[1,2,3,2]) = {MultiRember(2,[1,2,3,2])}")


#DEFINISI DAN SPESIKASI KONSTRUKTOR SET DARI LIST
# MakeSet1: list -> set 
# MakeSet1(L) membuat set dari list L dengan menghapus semua kemunculan lebih dari satu kali dengan memanfaatkan fungsi IsMember(x,L) untuk mengecek duplikasi elemen.
#   list kosong tetap menjadi himpunan kosong
def MakeSet1(L):
    if IsEmpty(L):
        return L
    else:
        if IsMember(FirstElmt(L),Tail(L)):
            return Tail(L)
        return Konso(FirstElmt(L),MakeSet1(Tail(L)))
# print(f"MakeSet1([1,2,3,2]) = {MakeSet1([2,3,1,4,2,6,1,3,7])}")

# MakeSet2: list -> set 
# MakeSet2(L) membuat set dari list L dengan menghapus semua kemunculan lebih dari satu kali dengan memanfaatkan fungsi MultiRember(x,L) untuk menghapus duplikasi elemen.  
#   list kosong tetap menjadi himpunan kosong
def MakeSet2(L):
    if IsEmpty(L):
        return []
    return Konso(FirstElmt(L),MakeSet2(MultiRember(FirstElmt(L),Tail(L))))
# print(f"MakeSet2([1,2,3,2,2]) = {MakeSet2([2,3,1,4,2,6,1,3,7])}")


#DEFINISI DAN SPESIKASI KONSTRUKTOR SET 
# KonsoSet: elemen,set -> set 
# KonsoSet(e,H) menambahkan sebuah elemen e sebagai elemen pertama set H dengan syarat e belum ada di dalam himpunan H
def KonsoSet(e,H):
    if IsMember(e,H):
        return H
    return Konso(e,H)
# print(f"KonsoSet(3,[1,2,4]) = {KonsoSet(3,[1,2,4])}")


#DEFINISI DAN SPESIFIKASI PREDIKAT
# IsSet: list -> boolean
# IsSet(L) mengembalikan true jika L adalah sebuah set
def IsSet(L):
    if IsEmpty(L):
        return True
    else: 
        if IsMember(FirstElmt(L),Tail(L)):
            return False
        return IsSet(Tail(L))
# print(f"IsSet([1,2,3]) = {IsSet([1,2,3])}")

# IsSubset: 2 set -> boolean
# IsSubset(H1,H2) mengembalikan true jika H1 merupakan subset dari H2
def IsSubset(H1,H2):
    if IsEmpty(H1):
        return True
    else:
        if IsMember(FirstElmt(H1),H2):
            return IsSubset(Tail(H1),H2)
        return False
# print(f"IsSubset([1,2,5],[3,4,2,1]) = {IsSubset([1,2,5],[3,4,2,1])}") 

# IsEqualSet1: 2 set -> boolean
# IsEqualSet1(H1,H2} benar jika H1 adalah set yang sama dengan H2 yang menggunakan fungsi IsSubset(H1, H2)
def IsEqualSet1(H1,H2):
    return IsSubset(H1,H2) == IsSubset(H2,H1)
# print(f"IsEqualSet1([1,2,3],[3,1,2]) = {IsEqualSet1([2, 3, 5, 7, 9], [9, 5, 3, 2, 7])}")

# IsEqualSet2: 2 set -> boolean
# IsEqualSet2(H1,H2} benar jika H1 adalah set yang sama dengan H2 dengan mengecek satu persatu elemen pada H1 dan H2.
def IsEqualSet2(H1,H2):
    if IsEmpty(H1) or IsEmpty(H2):
        return True
    else:
        if IsMember(FirstElmt(H1),H2):
            return IsEqualSet2(Tail(H1),H2)
        return False
# print(f"IsEqualSet2([1,2,3],[3,1,2]) = {IsEqualSet2([1,2,3],[3,1,2])}")

# IsIntersect: 2 set -> boolean
# IsIntersect(H1,H2) benar jika H1 beririsan dengan H2
def IsIntersect(H1,H2):
    if IsEmpty(H1) or IsEmpty(H2):
        return False
    else:
        if IsMember(FirstElmt(H1),H2):
            return True
        return IsIntersect(Tail(H1),H2)
# print(f"IsIntersect([1,5],[1,2,3,4]) = {IsIntersect([1,5],[1,2,3,4])}")


#DEFINISI DAN SPESIFIKASI OPERASI TERHADAP HIMPUNAN
# MakeIntersect1: 2 set -> set
# MakeIntersect1(H1,H2) menghasilkan set baru yang merupakan hasil irisan antara H1 dan H2, rekursif terhadap H1
def MakeIntersect1(H1,H2):
    if IsEmpty(H1) or IsEmpty(H2):
        return []
    else:
        if IsMember(FirstElmt(H1),H2):
            return Konso(FirstElmt(H1),MakeIntersect1(Tail(H1),H2))
        return MakeIntersect1(Tail(H1),H2)
# print(f"MakeIntersect1([1,2,4,5],[1,2,3,5]) = {MakeIntersect1([1,2,4,5],[1,2,3,5])}")

# MakeIntersect2: 2 set -> set
# MakeIntersect2(H1,H2) menghasilkan set baru yang merupakan hasil irisan antara H1 dan H2, rekursif terhadap H2
def MakeIntersect2(H1,H2):
    if IsEmpty(H1) or IsEmpty(H2):
        return []
    else:
        if IsMember(FirstElmt(H2),H1):
            return Konso(FirstElmt(H2),MakeIntersect2(Tail(H2),H1))
        return MakeIntersect2(Tail(H2),H1)
# print(f"MakeIntersect2([1,2,4,5,6],[1,2,3]) = {MakeIntersect2([1,2,4,5,6],[1,2,3])}")

# MakeUnion1: 2 set -> set
# MakeUnion1(H1,H2) menghasilkan set baru yang merupakan hasil gabungan antara H1 dan H2, rekursif terhadap H1
def MakeUnion1(H1,H2):
    if IsEmpty(H1) and IsEmpty(H2):
        return []
    if not IsEmpty(H1) and IsEmpty(H2):
        return H1
    if IsEmpty(H1) and not IsEmpty(H2):
        return H2
    else:
        if IsMember(FirstElmt(H1),H2):
            return MakeUnion1(Tail(H1),H2)
        return Konso(FirstElmt(H1),MakeUnion1(Tail(H1),H2))
# print(f"MakeUnion1([1,2,3,7],[1,4,5,6]) = {MakeUnion1([1,2,3,7],[1,4,5,6])}")

# MakeUnion2: 2 set -> set
# MakeUnion2(H1,H2) menghasilkan set baru yang merupakan hasil gabungan antara H1 dan H2, rekursif terhadap H2
def MakeUnion2(H1,H2):
    if IsEmpty(H1) and IsEmpty(H2):
        return []
    if not IsEmpty(H1) and IsEmpty(H2):
        return H1
    if IsEmpty(H1) and not IsEmpty(H2):
        return H2
    else:
        if IsMember(FirstElmt(H2),H1):
            return MakeUnion2(Tail(H2),H1)
        return Konso(FirstElmt(H2),MakeUnion2(Tail(H2),H1))
# print(f"MakeUnion2([1,2,3,7],[1,4,5,6]) = {MakeUnion2([1,2,3,7],[1,4,5,6])}")

# NBIntersect: 2 set -> integer
# NBIntersect(H1,H2) menghasilkan jumlah elemen yang beririsan pada H1 dan H2
#   tanpa memanfaatkan fungsi MakeIntersect(H1,H2).
def NBIntersect(H1,H2):
    if IsEmpty(H1) or IsEmpty(H2):
        return 0
    else:
        if IsMember(FirstElmt(H1),H2):
            return 1 + NBIntersect(Tail(H1),H2)
        return 0 + NBIntersect(Tail(H1),H2)
# print(f"NBIntersect([1,2,4,5],[1,2,3,5]) = {NBIntersect([1,2,4,5],[1,2,3,5])}")

# NBUnion: 2 set -> integer
# NBUnion(H1,H2) menghasilkan jumlah elemen hasil gabungan antara H1 dan H2
#   tanpa memanfaatkan fungsi MakeUnion(H1,H2).
def NBUnion(H1,H2):
    if IsEmpty(H1) and IsEmpty(H2):
        return 0
    if not IsEmpty(H1) and IsEmpty(H2):
        return NbElmt(H1)
    if IsEmpty(H1) and not IsEmpty(H2):
        return NbElmt(H2)
    else:
        if IsMember(FirstElmt(H1),H2):
            return NBUnion(Tail(H1),H2)
        return 1 + NBUnion(Tail(H1),H2)
# print(f"NBUnion([1,2,3,7],[1,4,5,6]) = {NBUnion([1,2,3,7],[1,4,5,6])}")


# print(Konso(LastElmt([7,8,9,10]), MultiRember(2,[2,3,1,4,2,4,1])))