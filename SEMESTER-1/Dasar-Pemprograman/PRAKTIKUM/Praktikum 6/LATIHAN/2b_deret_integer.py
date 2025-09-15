"""
Nama File : 2b_deret_integer.py
Deskripsi : Membuat ekspresi rekursif untuk menghitung deret bilangan integer: 1 + 2 + 3 + 4 + ...
Pembuat : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal : 1 Januari 2024
"""

"""
DEFINISI DAN SPESIFIKASI
deret_int : integer > 0 --> integer > 0
    {deret_int(n) menghitung deret bilangan integer dengan suku awal 1 dan beda 1 sampai suku ke-n}
"""

# REALISASI
def deret_int(n):
    if n == 1 : return 1 # {basis 1}
    return n + deret_int(n-1) # {rekurens terhadap n}

# APLIKASI
print(deret_int(4)) # -> 10
print(deret_int(5)) # -> 15
print(deret_int(6)) # -> 21