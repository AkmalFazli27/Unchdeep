"""
Menghitung perkalian dengan 3 aray f(n) = 3*n
f(1)=3
f(n+1)=f(n)=3
"""
def kali3(n):
    if n == 1 : return 3
    return 3 + kali3(n-1)
print(f"Hasil 3 x 5 = {kali3(5)}")

"""
Menghitung deret bilangan integer: 1+2+3+4+…
s(1)=1
s(2)=1+2
s(3)=1+2+3
"""
def deret(n):
    if n == 1 : return 1
    return n + deret(n-1)
print(f"Hasil deret bilangan dengan n = 5 adalah {deret(5)}")

"""
Menghitung deret aritmatika: 3+6+9+12+…
s(1)=3
s(2)=3+6
s(3)=3+6+9
"""
def arit(n):
    if n == 1 : return 3
    return 3*n + arit(n-1)
print(f"Hasil dari deret aritmatika dengan n = 4 adalah {arit(4)}")

"""
Menghitung deret geometri: 1+3+9+27+…
f(1)=1
f(n+1)=f(n)=3
"""
def geo(n):
    if n == 1 : return 1
    return 3**(n-1) + geo(n-1)
print(f"Hasil dari deret geometri dengan n = 5 adalah {geo(5)}")

"""
Menghitung deret : 1+4+9+16+…
s(1)=1
s(2)=1+4
s(3)=1+4+9
"""
def deret(n):
    if n == 1 : return 1
    return n**2 + deret(n-1)
print(f"Hasil dari deret dengan n = 6 adalah {deret(6)}")