"""
Nama File : 1a_pengurangan.py
Deskripsi : Membuat ekspresi rekursif pada pengurangan
Pembuat : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal : 1 Januari 2024
"""

"""
DEFINISI DAN SPESIFIKASI
min : 2 integer > 0 --> integer > 0
    {min(x,y) menghasilkan x - y}
"""

# REALISASI
def min(x,y):
    if y == x : return 0 # {basis x}
    return 1 + min(x,y + 1) # {rekurens terhadap y}

# APLIKASI
print(min(2,1)) # -> 1
print(min(5,3)) # -> 2
print(min(10,4)) # -> 6