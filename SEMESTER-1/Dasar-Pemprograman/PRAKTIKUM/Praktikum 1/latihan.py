# SOAL LATIHAN

u = 1
v = 2
w = 3
x = 4
c = "c"
y = 2
x1 = 2
x2 = 1
y1 = 2
y2 = 1


# Mean Olympique
def mo (u, v, w, x):
    return (u + v + w + x)/4
print(mo (u, v, w, x))

# Ekspresi Boolean : POSITIF
def is_positif (x):
    return x > 0
print(is_positif (x))

# Ekspresi Boolean : Apakah Huruf A
def is_a (c):
    return c == "A"
print(is_a (c))

# Ekspresi Boolean : Apakah origin
def is_origin (x, y):
    return x == 0 and y == 0
print(is_origin (x, y))

# Ekspresi numeric : Least Square (jarak 2 titik)
import math

def ls (x1, y1, x2, y2):
    return (x1-x2) + (y1-y2)
print(math.sqrt(ls (x1, y1, x2, y2)))