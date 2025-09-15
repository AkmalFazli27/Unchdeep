"""
Nama File : 1b_perkalian3.py
Deskripsi : Membuat ekspresi rekursif untuk menghitung perkalian dengan 3 atau f(n) = 3 * n
Pembuat : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal : 1 Januari 2024
"""

"""
DEFINISI DAN SPESIFIKASI
kali3 : integer > 0 --> integer > 0
    {kali3(n) menghasilkan 3 * n}
"""

# REALISASI
def kali3(n):
    if n == 1 : return 3 # {basis 1}
    return 3 + kali3(n-1) # {rekurens terhadap n}

# APLIKASI
print(kali3(5)) # -> 15
print(kali3(10)) # -> 30
print(kali3(13)) # -> 39