"""
Nama File : 4b_geometri.py
Deskripsi : Membuat ekspresi rekursif untuk menghitung deret geometri: 1 + 3 + 9 + 27 + ... 
Pembuat : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal : 1 Januari 2024
"""

"""
DEFINISI DAN SPESIFIKASI
geo : integer > 0 --> integer > 0
    {geo(n) menghitung deret geometri dengan suku awal 1 dan rasio 3 sampai suku ke-n}
"""

# REALISASI
def geo(n):
    if n == 1 : return 1 # {basis 1}
    return 3**(n-1) + geo(n-1) # {rekurens terhadap n}

# APLIKASI
print(geo(4)) # -> 40
print(geo(6)) # -> 364
print(geo(8)) # -> 3280