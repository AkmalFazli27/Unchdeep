# Nama file : Praktikum 1.py
# Deskripsi : Menghitung nilai pangkat
# Tanggal : 27 Agustus 2024
# Pembuat : M. Akmal Fazli Riyadi - 24060124130123

# Definisi dan Spesifikasi
# fx2 : interger --> interger
    # fx2 (x) menghitung nilai pangkat dua dari x
    # x sebuah bilangan interger

x = 1
y = 2
a = 3
b = 4
c = 5

# Realisasi
def fx2 (x):
    return x**2

def fx3 (x):
    return x**3
print(f"{x}^2 = {fx2 (x)} \n{x}^3 = {fx3 (x)}")

def fx2 (x,y):
    return x + y
print(f"{x} + {y} = {fx2 (x,y)}")

def max2 (a,b):
    return ((a+b) + abs(a-b)) // 2
print(max2 (a,b))

def max3 (a,b,c):
    return max2 (max2 (a,b),c)
print(max3 (a,b,c))

def is_origin (x, y):
    return (x == 0) and (y == 0)
print(is_origin (x,y))



