"""
Nama File : 3b_aritmatika.py
Deskripsi : Membuat ekspresi rekursif untuk menghitung deret aritmatika: 3 + 6 + 9 + 12 + ...
Pembuat : Muhammad Akmal Fazli Riyadi / 24060124130123
Tanggal : 1 Januari 2024
"""

"""
DEFINISI DAN SPESIFIKASI
arit : integer > 0 --> integer > 0
    {arit(n) menghitung deret aritmatika dengan suku awal 3 dan beda 3 sampai suku ke-n}
"""

# REALISASI
def arit(n):
    if n == 1 : return 3 # {basis 1}
    return 3*n + arit(n-1) # {rekurens terhadap n}

# APLIKASI
print(arit(5)) # -> 45
print(arit(6)) # -> 63
print(arit(7)) # -> 84