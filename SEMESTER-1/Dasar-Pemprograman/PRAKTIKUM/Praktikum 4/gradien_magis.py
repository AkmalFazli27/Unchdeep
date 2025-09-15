"""
Program   : Gradien Magis
Deskripsi : Program ini menghitung energi magis di titik a dan b serta gradien magis di antara kedua titik menggunakan fungsi "kuno" f(x).
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 23/09/2024
"""

"""
DEFINISI DAN SPESIFIKASI

f : integer -> real
{f(x) adalah fungsi yang digunakan untuk menghitung energi magis pada titik x, dengan rumus f(x) = 3 * x^2 + 2 * x - 5}

gradien : integer, integer -> real
{gradien(a, b) menghitung gradien magis antara titik a dan b dengan rumus (f(a) - f(b)) / (a - b), di mana a ≠ b}
"""
# REALISASI
def energi (a):
    return 3*a**2 + 2*a - 5
def gradien (a,b):
    return (energi (a) - energi (b)) / (a - b)

# APLIKASI
print(gradien(3,1))