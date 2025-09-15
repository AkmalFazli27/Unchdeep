"""
DEFINISI DAN SPESIFIKASI

IsOrigin? : real, real → boolean
 {IsOrigin? (x,y) benar jika (x,y) adalah dua nilai yang mewakili titik origin (0,0) } 
"""

# REALISASI
def IsOrigin (x, y):
    return x == 0 and y == 0


# APLIKASI
print(IsOrigin (1, 0))
print(IsOrigin (1, 1))
print(IsOrigin (0, 1))