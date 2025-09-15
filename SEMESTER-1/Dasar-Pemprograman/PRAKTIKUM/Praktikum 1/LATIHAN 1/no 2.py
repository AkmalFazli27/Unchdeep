"""
DEFINISI DAN SPESIFIKASI

IsPositif? : integer → boolean
 {IsPositif? (x) benar jika x positif }
"""

# REALISASI
def is_positif (x):
    return x >= 0


# APLIKASI
print(is_positif (1))
print(is_positif (0))
print(is_positif (-1))