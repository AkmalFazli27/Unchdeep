"""
Nama File : 3a_pembagian.py
Deskripsi : Membuat ekspresi rekursif pada pembagian
Pembuat : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal : 1 Januari 2024
"""

"""
DEFINISI DAN SPESIFIKASI
bagi : 2 integer > 0 --> integer > 0
    {bagi(x,y) menghasilkan x / y}
"""

# REALISASI
def bagi(x,y):
    if x == y : return 1 # {basis y}
    return bagi(x - y,y) + 1 # {rekurens terhadap x}

# APLIKASI
print(bagi(10,2)) # -> 5
print(bagi(21,3)) # -> 7
print(bagi(100,4)) # -> 25