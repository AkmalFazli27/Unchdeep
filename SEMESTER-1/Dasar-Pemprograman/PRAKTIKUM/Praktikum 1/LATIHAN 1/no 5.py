"""
DEFINISI DAN SPESIFIKASI
IsValid? : integer → boolean
 {IsValid? (x) benar jika (x) bernilai lebih kecil 5 atau lebih besar dari 500 } 
"""

# REALISASI
def IsValid (x):
    return x < 5 or x > 500

# APLIKASI
print(IsValid (5))
print(IsValid (0))
print(IsValid (500))
print(IsValid (6000))