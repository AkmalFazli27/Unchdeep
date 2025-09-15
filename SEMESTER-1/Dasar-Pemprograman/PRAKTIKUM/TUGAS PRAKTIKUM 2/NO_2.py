"""
Nama File : NO_2.py
Deskripsi : Menghitung jumlah hari dari tanggal 1 Januari dengan memperhitungkan tahun kabisat
Tanggal   : 10 September 2024
Nama / NIM   : Muhammad Akmal Fazli Riyadi / 24060124130123
"""

"""
DEFINISI DAN SPESIFIKASI
Harike1900 : integer [1..31], integer [1..12], integer [0..99] → integer [1..366] 
 {Harike1900 (d,m,y) menentukan jumlah hari dari awal tahun (y) pada 1 Januari pada suatu
tanggal (d) dan bulan (m)}

dpm : integer [1..12] → integer [1..36] 
 {dpm(b) adalah jumlah hari kumulatif dari tanggal 1 Januari hingga tanggal 1 bulan (b)
pada tahun tertentu tanpa memperhitungkan tahun kabisat}

is_kabisat : integer [0..99] → boolean 
 {is_kabisat(y) bernilai True jika tahun (y) habis dibagi 4 tetapi tidak habis dibagi 100,
atau habis dibagi 400}
"""

# REALISASI
def dpm(b):
    if b == 1:
        return 1
    elif b == 2:
        return 32  
    elif b == 3:
        return 60  
    elif b == 4:
        return 91  
    elif b == 5:
        return 121  
    elif b == 6:
        return 152  
    elif b == 7:
        return 182  
    elif b == 8:
        return 213  
    elif b == 9:
        return 244  
    elif b == 10:
        return 274  
    elif b == 11:
        return 305  
    elif b == 12:
        return 335

def harike1900 (d,m,y): 
    return dpm(m) + d  - (0 if is_kabisat(y) and m > 2 else 1) 

def is_kabisat(y):
    return y % 400 == 0 or y % 4 == 0 and y % 100 != 0

# APLIKASI
print(harike1900(27,6,1006)) # -> 178
print(harike1900(15,12,1772)) # -> 350
print(harike1900(9,4,1540)) # -> 100
