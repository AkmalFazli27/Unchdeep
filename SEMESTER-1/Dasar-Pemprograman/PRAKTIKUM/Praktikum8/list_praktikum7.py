"""
Nama File : list.py
Deskripsi : Berisi type dan operasi list
Pembuat   : Muhammad Akmal Fazli Riyadi
NIM       : 24060124130123
Tanggal   : 2 November 2024 
"""


"""
DEFINISI DAN SPESIFIKASI TYPE
Konstruktor menambahkan elemen di awal, notasi prefix
type List: [] atau  [e o List]
Konstruktor menambahkan elemen di akhir, notasi postfix
type List: [] atau [List o e]
"""


"""
DEFINISI DAN SPESIFIKASI KONSTRUKTOR
Konso: elemen, List → List
  {Konso(e,L) menghasilkan sebuah List dari e dan L dengan e sebagai elemen pertama}
REALISASI
"""
def Konso(e,L):
    return [e] + L


"""
Konsi: List, elemen → List
  {Konsi(L,e) menghasilkan sebuah List dari L dan e dengan e sebagai elemen terakhir}
Realisasi
"""
def Konsi(e,L):
    return L + [e]


"""
DEFINISI DAN SPESIFIKASI SELEKTOR
FirstElmt: List tidak kosong → elemen
  {FirstElmt(L) mengembalikan elemen pertama dari list L}
Realisasi
"""
def FirstElmt(L):
    return L[0]


"""
LastElmt: List tidak kosong → elemen
  {LastElmt(L): mengembalikan elemen terakhir terakhir list L}
Realisasi
"""
def LastElmt(L):
    return L[-1]


"""
Tail: List tidak kosong → List
  {Tail(L): Menghasilkan list tanpa elemen pertama list L, mungkin kosong}
Realisasi
"""
def Tail(L):
    return L[1:]


"""
Head: List tidak kosong → List
  {Head(L): Menghasilkan list tanpa elemen terakhir list L, mungkin kosong}
Realisasi
"""
def Head(L):
    return L[:-1]


"""
DEFINISI DAN SPESIFIKASI PREDIKAT
IsEmpty: List → boolean
  {IsEmpty(L) benar jika list kosong}
Realisasi
"""
def IsEmpty(L):
    return L == []


"""
IsOneElmt: List → boolean
  {IsOneElmt(L) adalah benar jika list L hanya mempunyai satu elemen}
Realisasi
"""
def IsOneElmt(L):
    if IsEmpty(L):
        return False
    return Tail(L) == [] and Head(L) == []


"""
DEFINISI DAN SPESIFIKASI FUNGSI YANG MENGOPERASIKAN LIST
NbElmt: List → integer
  {NbElmt(L) Menghasilkan banyaknya elemen list, nol jika kosong}
Realisasi
"""
def NbElmt(L):
    if IsEmpty(L):
        return 0
    return 1 + NbElmt(Tail(L))


"""
ElmtKeN: integer >= 0, List → elemen
  {ElmtKeN(N,L) mengembalikan elemen ke N dari list L, N <= NbElmt(L) dan N >= 0}
Realisasi
"""
def ElmtKeN(N,L):
    if N == 1:
        return FirstElmt(L)
    return ElmtKeN(N - 1,Tail(L))



"""
IsMember: elemen, List → boolean
  {IsMember(X,L) adalah benar jika X adalah anggota elemen List L}
Realisasi
"""
def IsMember(X,L):
    if IsEmpty(L):
        return False
    if X == FirstElmt(L):
        return True
    return IsMember(X,Tail(L))



"""
Copy: List → List
  {Copy(L) menghasilkan list yang identik dengan list L}
Realisasi
"""
def Copy(L):
    if IsEmpty(L):
        return []
    return Konso(FirstElmt(L),Copy(Tail(L)))



"""
Invers: List → List
  {Invers(L) menghasilkan List L yang dibalik}
"""
def Inverse(L):
    if IsEmpty(L):
        return []
    return Konso(LastElmt(L),Inverse(Head(L)))


"""
Konkat : 2 List → List
  {Konkat(L1,L2) menghasilkan konketasi 2 buah list, dengan list L2 "sesudah" list L1}
Realisasi
"""
def Konkat(L1,L2):
    return Copy(L1) + Copy(L2)



"""
SumElmt: List of integer → integer
  {SumElmt(L) menghasilkan jumlahan dari setiap elemen di dalam list L}
Realisasi
"""
def SumElmt(L):
    if IsEmpty(L):
        return 0
    return FirstElmt(L) + SumElmt(Tail(L))



"""
AvgElmt: List of integer → integer
  {AvgElmt(L) menghasilkan nilai rata-rata}
Realisasi
"""
def AvgElmt(L):
    if IsEmpty(L):
        return 0
    return SumElmt(L) / NbElmt(L)



def max2(a,b):
    if a > b : return a
    else : return b


"""
MaxElmt: List of integer → integer
  {MaxElmt(L) mengembalikan elemen maksimum dari list L}
Realisasi
"""
def MaxElmt(L):
    if IsOneElmt(L):
        return FirstElmt(L)
    return max2(FirstElmt(L),MaxElmt(Tail(L)))



"""
CekD: element, List → integer
  {CekD(L) mengembalikkan element yang duplikat dalam satu list}
Realisasi
"""
def CekD(X,L):
    if IsEmpty(L):
        return 0
    if X == FirstElmt(L):
        return 1 + CekD(X,Tail(L))
    return CekD(X,Tail(L))



"""
MaxNB: List of integer → <integer, integer>
  {MaxNB(L) menghasilkan <max,countMax}
      dengan max adalah elemen maksimum list L
      dan countMax adalah banyaknya kemunculan max di list L
Realisasi
"""
def MaxNB(L):
    return MaxElmt(L), CekD(MaxElmt,L)



"""
AddList: 2 List of integer → List of integer
  {AddList(L1,L2) menghaislkan list baru yang setiap elemennya adalah hasil
   penjumlahan setiap elemen di L1 dan L2 pada posisi yang sama}
Realisasi
"""
def AddList(L1,L2):
    if IsEmpty(L1):
        return L2
    if IsEmpty(L2):
        return L1
    return Konso(FirstElmt(L1) + FirstElmt(L2),AddList(Tail(L1),Tail(L2)))



"""
IsPalindrom(L): List of character → boolean
    IsPalindrom(L) benar jika L merupakan kata palindrom
    yaitu kata yang sama jika dibaca dari kiri atau kanan
contoh: KASUR RUSAK, NABABAN
"""
def IsPalindrom(L):
    if IsEmpty(L):
        return True
    if FirstElmt(L) != LastElmt(L):
        return False
    return IsPalindrom(Tail(Head(L)))



