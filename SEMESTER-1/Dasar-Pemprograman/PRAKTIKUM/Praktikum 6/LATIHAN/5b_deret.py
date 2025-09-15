"""
Nama File : 5b_deret.py
Deskripsi : Membuat ekspresi rekursif untuk menghitung deret : 1 + 4 + 9 + 16 + ...
Pembuat : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal : 1 Januari 2024
"""

"""
DEFINISI DAN SPESIFIKASI
deret : integer > 0 --> integer > 0
    {deret(n) menghitung deret dengan setiap suku bernilai n**2 sampai suku ke-n}
"""

# REALISASI
def deret(n):
    if n == 1 : return 1 # {basis 1}
    return n**2 + deret(n-1) # {rekurens terhadap n}

# APLIKASI
print(deret(6)) # -> 91
print(deret(3)) # -> 14
print(deret(7)) # -> 140