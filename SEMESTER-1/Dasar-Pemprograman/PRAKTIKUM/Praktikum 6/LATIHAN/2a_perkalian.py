"""
Nama File : 2a_perkalian.py
Deskripsi : Membuat ekspresi rekursif pada perkalian
Pembuat : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal : 1 Januari 2024
"""

"""
DEFINISI DAN SPESIFIKASI
kali : 2 integer > 0 --> integer > 0
    {kali(x,y) menghasilkan x * y}
"""

# REALISASI
def kali(x,y):
    if y == 0 : return 0 # {basis 0}
    return x + kali(x,y - 1) # {rekurens terhadap y}

# APLIKASI
print(kali(2,2)) # -> 4
print(kali(6,6)) # -> 36
print(kali(3,7)) # -> 21