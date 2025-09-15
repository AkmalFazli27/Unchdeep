"""
Program   : Jalan Semut
Deskripsi : Program ini menghitung jarak terpendek yang ditempuh oleh semut dari sudut sebuah balok (0,0,0) ke sudut berlawanan (x,y,z) melalui permukaan balok.
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 23/09/2024
"""

"""
DEFINISI DAN SPESIFIKASI

jalanSemut : integer, integer, integer -> real 
{jalanSemut(x, y, z) menghitung jarak terpendek yang ditempuh oleh semut dari titik (0,0,0) ke titik (x,y,z) dengan menggunakan rumus jarak terpendek yang melibatkan tiga kombinasi jarak antara x, y, dan z.}
"""
# REALISASI
import math

def jalanSemut (x,y,z):
    jarak1 = math.sqrt((x + y) ** 2 + z ** 2)
    jarak2 = math.sqrt((x + z) ** 2 + y ** 2)
    jarak3 = math.sqrt((z + y) ** 2 + x ** 2)

    jarak_terpendek = min(jarak1, jarak2, jarak3)
    
    return round(jarak_terpendek,3)

# APLIKASI
print(jalanSemut(3,4,5))
print(jalanSemut(1,2,7))