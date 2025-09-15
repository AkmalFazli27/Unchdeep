"""
Nama File : 4a_perpangkatan.py
Deskripsi : Membuat ekspresi rekursif pada perpangkatan
Pembuat : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal : 1 Januari 2024
"""

"""
DEFINISI DAN SPESIFIKASI
pangkat : 2 integer > 0 --> integer > 0
    {pangkat(x,y) menghasilkan x * y}
"""

# REALISASI
def pangkat(x,y):
    if y == 0 : return 1 # {basis 0}
    return x * pangkat(x, y - 1) # {rekurens terhadap y}

# APLIKASI
print(pangkat(4,2)) # -> 16
print(pangkat(2,3)) # -> 8
print(pangkat(7,3)) # -> 343
