"""
DEFINISI DAN SPESIFIKASI
LS : 4 real → real
 {LS(x1,x2,y1,y2) adalah jarak antara dua buah titik (x1,x2) dengan (y1,y2) }
"""

"""
DEFINISI DAN SPESIFIKASI FUNGSI ANTARA

dif2 : 2 real → real
 {dif(x,y) adalah kuadrat dari selisih antara x dan y }
FX2 : real → real
 { FX2 (x) adalah hasil kuadrat dari x }
"""


# REALISASI
import math
def FX2 (x) : return x * x
def dif2 (x,y) : return FX2(x - y)
def LS (x1,y1,x2,y2) : return math.sqrt(dif2(y2,y1) + dif2(x2,x1))


# APLIKASI

print(LS (-3, 1, 5, 7))
print(LS (1, 2, 4, 6))
print(LS (0, 4, -6, 4))