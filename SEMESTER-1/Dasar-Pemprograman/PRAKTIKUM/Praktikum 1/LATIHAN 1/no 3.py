"""
DEFINISI DAN SPESIFIKASI

IsAnA : character → boolean
 {IsAnA (C) benar jika c adalah karakter (huruf) 'A' }
"""


# REALISASI

def IsAnA(c):
    return c == "A"


# APLIKASI
print(IsAnA (1))
print(IsAnA (0))
print(IsAnA (-1))